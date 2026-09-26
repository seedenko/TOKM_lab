//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#pragma hdrstop

#include "fRandomStars.h"
#include "uContainers.h"
#include "Stage.VectorTypes.hpp"
#include "Stage.VectorGeometry.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "GLS.SceneViewer"
#pragma link "GLS.Cadencer"
#pragma link "GLS.Scene"
#pragma link "GLS.Objects"
#pragma link "GLS.BaseClasses"
#pragma link "GLS.Coordinates"
#pragma resource "*.dfm"
TForm1* Form1;

// 7 цветов радуги [КОЖЗГСФ]
static const float RAINBOW_COLORS[7][3] = {
    {1.0f, 0.0f, 0.0f},   // 0: Красный (К)
    {1.0f, 0.5f, 0.0f},   // 1: Оранжевый (О)
    {1.0f, 1.0f, 0.0f},   // 2: Жёлтый (Ж)
    {0.0f, 1.0f, 0.0f},   // 3: Зелёный (З)
    {0.0f, 0.8f, 1.0f},   // 4: Голубой (Г)
    {0.0f, 0.0f, 1.0f},   // 5: Синий (С)
    {0.6f, 0.0f, 1.0f}    // 6: Фиолетовый (Ф)
};

// Вспомогательная функция выборки точки по типу контейнера
static Point3D getContainerPoint(int containerType)
{
    switch (containerType) {
        case 0: return generatePointForCube(1022.0f);
        case 1: return generatePointForSphere(511.0f);
        case 2: return generatePointForSphereSurface(511.0f);
        case 3: return generatePointForCylinder(511.0f, 1022.0f);
        case 4: return generatePointForCylinderSurface(511.0f, 1022.0f);
        case 5: return generatePointForCone(511.0f, 1022.0f);
        default: return generatePointForCube(1022.0f);
    }
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
    mx = 0;
    my = 0;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject* Sender)
{
    srand((unsigned)time(0));
    Caption = "Лабораторная работа №1 — Сиденко Валерия (НИУ «БелГУ»)";
    
    // Настройка начальной позиции камеры для обзора куба 1024x1024x1024
    GLCamera1->Position->SetPoint(1400.0f, 1200.0f, 1800.0f);
    GLCamera1->TargetObject = dcBlock;
    
    dcBlock->ShowAxes = true;
    dcBlock->CubeSize = 1024.0f;
    
    Stars->Size = 2;
    rgBlock->ItemIndex = 0;
    rgMode->ItemIndex = 0;
    seNStars->Value = 100000;
}

//---------------------------------------------------------------------------
void TForm1::ClearScene()
{
    // Очистка динамических сфер
    for (size_t i = 0; i < m_spheres.size(); i++) {
        if (m_spheres[i]) {
            m_spheres[i]->Free();
        }
    }
    m_spheres.clear();

    // Очистка точек
    m_starsLife.clear();
    Stars->Free();
    Stars = (TGLPoints*)(dcBlock->AddNewChild(__classid(TGLPoints)));
    Stars->Size = 2;
    Stars->NoZWrite = false;

    rgBlock->Enabled = true;
    rgMode->Enabled = true;
    seNStars->Enabled = true;
    btnDraw->Enabled = true;

    StatusBar1->Panels->Items[0]->Text = "Сцена очищена";
    GLSceneViewer1->Invalidate();
}

//---------------------------------------------------------------------------
void TForm1::GenerateStarsPoints(int count, int containerType)
{
    Stars->Positions->Clear();
    Stars->Colors->Clear();
    Stars->Size = 2;

    m_starsLife.resize(count);

    for (int i = 0; i < count; i++) {
        Point3D p = getContainerPoint(containerType);
        Stars->Positions->Add(p.x, p.y, p.z);

        // Случайный цвет в диапазоне 1-255 цветов (RGBA)
        float r = (float)(1 + rand() % 255) / 255.0f;
        float g = (float)(1 + rand() % 255) / 255.0f;
        float b = (float)(1 + rand() % 255) / 255.0f;
        Stars->Colors->AddPoint(r, g, b);

        // Случайная длительность свечения [1-100] секунд
        m_starsLife[i].maxLife = 1.0f + (float)(rand() % 100);
        m_starsLife[i].curLife = (float)(rand() % (int)m_starsLife[i].maxLife) + 1.0f;
        m_starsLife[i].r = r;
        m_starsLife[i].g = g;
        m_starsLife[i].b = b;
        m_starsLife[i].a = 1.0f;
    }
}

//---------------------------------------------------------------------------
void TForm1::GenerateStarsSpheres(int count, int containerType)
{
    // Для 3D-сфер ограничиваем число разумным пределом во избежание падения FPS
    int actualCount = count > 300 ? 300 : count;

    for (int i = 0; i < actualCount; i++) {
        Point3D p = getContainerPoint(containerType);
        TGLSphere* sp = (TGLSphere*)(dcBlock->AddNewChild(__classid(TGLSphere)));

        // Случайный радиус [0, 1], масштабированный для куба 1024x1024x1024
        float normRadius = (float)(1 + rand() % 100) / 100.0f; // [0.01, 1.0]
        sp->Radius = normRadius * 20.0f + 5.0f;                // видимый размер сферы
        sp->Position->SetPoint(p.x, p.y, p.z);
        sp->Stacks = 12;
        sp->Slices = 12;

        // Выбор одного из 7 цветов радуги [КОЖЗГСФ]
        int colIdx = rand() % 7;
        float cr = RAINBOW_COLORS[colIdx][0];
        float cg = RAINBOW_COLORS[colIdx][1];
        float cb = RAINBOW_COLORS[colIdx][2];

        sp->Material->FrontProperties->Diffuse->Color = VectorMake(cr, cg, cb, 1.0f);
        sp->Material->FrontProperties->Emission->Color = VectorMake(cr * 0.4f, cg * 0.4f, cb * 0.4f, 1.0f);

        m_spheres.push_back(sp);
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::btnDrawClick(TObject* Sender)
{
    int count = seNStars->Value;
    int container = rgBlock->ItemIndex;
    int mode = rgMode->ItemIndex;

    ClearScene();

    unsigned int start = clock();

    if (mode == 0) {
        GenerateStarsPoints(count, container);
    } else {
        GenerateStarsSpheres(count, container);
    }

    unsigned int end = clock();
    double ex_time = (end - start) / (double)CLOCKS_PER_SEC;

    String modeStr = (mode == 0) ? "точек" : "сфер";
    StatusBar1->Panels->Items[0]->Text =
        Format("Создано %d %s в контейнере [%s]. Время генерации: %.4f с",
               ARRAYOFCONST((count, modeStr, rgBlock->Items->Strings[container], ex_time)));

    GLSceneViewer1->Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClearClick(TObject* Sender)
{
    ClearScene();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::rgModeClick(TObject* Sender)
{
    if (rgMode->ItemIndex == 1) {
        // Режим сфер: устанавливаем удобное число сфер
        if (seNStars->Value > 300) {
            seNStars->Value = 150;
        }
    } else {
        // Режим точек: устанавливаем требуемые 100 000 точек
        if (seNStars->Value < 10000) {
            seNStars->Value = 100000;
        }
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewer1MouseDown(
    TObject* Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
    mx = X;
    my = Y;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GLSceneViewer1MouseMove(
    TObject* Sender, TShiftState Shift, int X, int Y)
{
    if (Shift.Contains(ssLeft)) {
        GLCamera1->MoveAroundTarget(my - Y, mx - X);
        mx = X;
        my = Y;
    } else if (Shift.Contains(ssRight)) {
        GLCamera1->AdjustDistanceToTarget(1.0 + (my - Y) * 0.01);
        mx = X;
        my = Y;
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject* Sender, TShiftState Shift,
    int WheelDelta, TPoint &MousePos, bool &Handled)
{
    if (GLSceneViewer1->MouseInControl) {
        GLCamera1->AdjustDistanceToTarget(pow(1.1, -WheelDelta / 120.0));
        Handled = true;
    }
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject* Sender)
{
    StatusBar1->Panels->Items[1]->Text =
        Format("FPS: %.2f", ARRAYOFCONST((GLSceneViewer1->FramesPerSecond())));
    GLSceneViewer1->ResetPerformanceMonitor();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GLCadencer1Progress(
    TObject* Sender, const double deltaTime, const double newTime)
{
    // Моделирование длительности свечения точек [1-100] секунд
    if (chbLifetime->Checked && !m_starsLife.empty() && Stars && Stars->Colors->Count > 0) {
        float dt = (float)deltaTime;
        int n = (int)m_starsLife.size();
        for (int i = 0; i < n; i++) {
            m_starsLife[i].curLife -= dt;
            if (m_starsLife[i].curLife <= 0.0f) {
                // Перезапуск свечения (рождение новой звезды)
                m_starsLife[i].maxLife = 1.0f + (float)(rand() % 100);
                m_starsLife[i].curLife = m_starsLife[i].maxLife;
            }
            float factor = m_starsLife[i].curLife / m_starsLife[i].maxLife;
            // Плавное мерцание/затухание
            Stars->Colors->Items[i] = VectorMake(m_starsLife[i].r * factor, m_starsLife[i].g * factor, m_starsLife[i].b * factor, 1.0f);
        }
    }

    GLSceneViewer1->Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::miFileClearClick(TObject* Sender)
{
    ClearScene();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::miFileExitClick(TObject* Sender)
{
    Close();
}

//---------------------------------------------------------------------------
void __fastcall TForm1::miHelpAboutClick(TObject* Sender)
{
    ShowMessage(
        "Лабораторная работа №1\n"
        "Тема: Генерация точек со случайным равномерным распределением в объёме контейнера\n\n"
        "Дисциплина: Теоретические основы компьютерного моделирования\n"
        "Студент: Сиденко Валерия (2 курс, гр. 12002531)\n"
        "Преподаватель: доц. Васильев Павел Владимирович\n"
        "НИУ «БелГУ», 2026"
    );
}

//---------------------------------------------------------------------------
void TForm1::SaveFormCapture(String fullPath)
{
    Application->ProcessMessages();
    Sleep(150);
    Application->ProcessMessages();
    Vcl::Graphics::TBitmap *bmp = GetFormImage();
    if (bmp) {
        bmp->SaveToFile(fullPath);
        delete bmp;
    }
}

//---------------------------------------------------------------------------
void TForm1::AutoCaptureSuite(String outDir)
{
    ForceDirectories(outDir);

    Show();
    Update();
    Application->ProcessMessages();

    // 1. Точки в Кубе (100 000 точек)
    rgBlock->ItemIndex = 0;
    rgMode->ItemIndex = 0;
    seNStars->Value = 100000;
    GLCamera1->Position->SetPoint(1450.0f, 1150.0f, 1750.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\01_cube_points.bmp");

    // 2. Точки в объеме шара
    rgBlock->ItemIndex = 1;
    rgMode->ItemIndex = 0;
    seNStars->Value = 100000;
    GLCamera1->Position->SetPoint(1350.0f, 1050.0f, 1650.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\02_sphere_volume_points.bmp");

    // 3. Точки на поверхности сферы
    rgBlock->ItemIndex = 2;
    rgMode->ItemIndex = 0;
    seNStars->Value = 100000;
    GLCamera1->Position->SetPoint(1300.0f, 1200.0f, 1700.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\03_sphere_surface_points.bmp");

    // 4. Точки в объеме цилиндра
    rgBlock->ItemIndex = 3;
    rgMode->ItemIndex = 0;
    seNStars->Value = 100000;
    GLCamera1->Position->SetPoint(1400.0f, 1300.0f, 1600.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\04_cylinder_volume_points.bmp");

    // 5. Точки на поверхности цилиндра
    rgBlock->ItemIndex = 4;
    rgMode->ItemIndex = 0;
    seNStars->Value = 100000;
    GLCamera1->Position->SetPoint(1450.0f, 1100.0f, 1650.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\05_cylinder_surface_points.bmp");

    // 6. Точки в объеме конуса
    rgBlock->ItemIndex = 5;
    rgMode->ItemIndex = 0;
    seNStars->Value = 100000;
    GLCamera1->Position->SetPoint(1350.0f, 1250.0f, 1750.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\06_cone_points.bmp");

    // 7. Сферы 7 цветов [КОЖЗГСФ] в Кубе
    rgBlock->ItemIndex = 0;
    rgMode->ItemIndex = 1;
    seNStars->Value = 150;
    GLCamera1->Position->SetPoint(1400.0f, 1100.0f, 1700.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\07_spheres_rainbow_cube.bmp");

    // 8. Сферы в объеме шара
    rgBlock->ItemIndex = 1;
    rgMode->ItemIndex = 1;
    seNStars->Value = 150;
    GLCamera1->Position->SetPoint(1300.0f, 1150.0f, 1600.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\08_spheres_rainbow_sphere.bmp");

    // 9. Сферы в конусе
    rgBlock->ItemIndex = 5;
    rgMode->ItemIndex = 1;
    seNStars->Value = 150;
    GLCamera1->Position->SetPoint(1350.0f, 1200.0f, 1650.0f);
    btnDrawClick(NULL);
    SaveFormCapture(outDir + "\\09_spheres_rainbow_cone.bmp");

    Application->Terminate();
    ExitProcess(0);
}
//---------------------------------------------------------------------------
