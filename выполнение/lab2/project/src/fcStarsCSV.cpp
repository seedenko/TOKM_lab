//---------------------------------------------------------------------------

#include <vcl.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#pragma hdrstop

#include "fcStarsCSV.h"
#include "fcHygViewer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormStarsCSV *FormStarsCSV;

// Helper to extract n-th comma-separated field safely
static void GetField(const char* line, int targetIdx, char* outBuf, int maxLen)
{
    outBuf[0] = '\0';
    int curIdx = 0;
    const char* p = line;
    while (*p && curIdx < targetIdx) {
        if (*p == ',') {
            curIdx++;
        }
        p++;
    }
    if (curIdx != targetIdx || !*p) return;
    
    int len = 0;
    while (*p && *p != ',' && *p != '\r' && *p != '\n' && len < maxLen - 1) {
        outBuf[len++] = *p++;
    }
    outBuf[len] = '\0';
}

//---------------------------------------------------------------------------
__fastcall TFormStarsCSV::TFormStarsCSV(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormStarsCSV::FormCreate(TObject *Sender)
{
    Caption = "Каталог звёзд (Stars.csv) — Сиденко Валерия (гр. 12002531)";
    if (StatusBarCSV->Panels->Count > 0)
        StatusBarCSV->Panels->Items[0]->Text = "Студентка: Сиденко Валерия (гр. 12002531)";
    
    // Auto-detect and load Stars.csv or Stars_mag65.csv
    String path1 = datapath + "Stars_mag65.csv";
    String path2 = datapath + "Stars.csv";
    if (FileExists(path1)) {
        LoadFromFile(path1);
    } else if (FileExists(path2)) {
        LoadFromFile(path2);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormStarsCSV::FormDestroy(TObject *Sender)
{
    m_csvStars.clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormStarsCSV::LoadFromFile(String filePath)
{
    m_csvStars.clear();
    FILE* fp = fopen(AnsiString(filePath).c_str(), "r");
    if (!fp) return;

    char line[1024];
    // Read header line
    if (!fgets(line, sizeof(line), fp)) {
        fclose(fp);
        return;
    }

    int offset = (strstr(line, "proper_ru") != NULL) ? 1 : 0;

    char fBuf[64];
    while (fgets(line, sizeof(line), fp)) {
        CSVStarItem star;
        
        // id (col 0)
        GetField(line, 0, fBuf, sizeof(fBuf));
        star.id = atoi(fBuf);
        
        // proper (col 6)
        GetField(line, 6, fBuf, sizeof(fBuf));
        star.proper = AnsiString(fBuf);
        
        // dist (col 9 + offset)
        GetField(line, 9 + offset, fBuf, sizeof(fBuf));
        star.dist = (float)atof(fBuf);
        
        // mag (col 13 + offset)
        GetField(line, 13 + offset, fBuf, sizeof(fBuf));
        star.mag = (float)atof(fBuf);
        
        // absmag (col 14 + offset)
        GetField(line, 14 + offset, fBuf, sizeof(fBuf));
        star.absmag = (float)atof(fBuf);
        
        // spect (col 15 + offset)
        GetField(line, 15 + offset, fBuf, sizeof(fBuf));
        star.spect = AnsiString(fBuf);
        char sc = (fBuf[0] != '\0') ? (char)toupper(fBuf[0]) : '?';
        star.spectClass = sc;
        
        // x, y, z (cols 17, 18, 19 + offset)
        GetField(line, 17 + offset, fBuf, sizeof(fBuf));
        star.x = (float)atof(fBuf);
        GetField(line, 18 + offset, fBuf, sizeof(fBuf));
        star.y = (float)atof(fBuf);
        GetField(line, 19 + offset, fBuf, sizeof(fBuf));
        star.z = (float)atof(fBuf);
        
        // vx, vy, vz (cols 20, 21, 22 + offset)
        GetField(line, 20 + offset, fBuf, sizeof(fBuf));
        star.vx = (float)atof(fBuf);
        GetField(line, 21 + offset, fBuf, sizeof(fBuf));
        star.vy = (float)atof(fBuf);
        GetField(line, 22 + offset, fBuf, sizeof(fBuf));
        star.vz = (float)atof(fBuf);
        
        m_csvStars.push_back(star);
    }
    fclose(fp);

    lblTotalInfo->Caption = Format("Загружено звёзд: %d", ARRAYOFCONST(((int)m_csvStars.size())));
    PopulateListView();
}
//---------------------------------------------------------------------------
void __fastcall TFormStarsCSV::PopulateListView()
{
    lvStars->Items->BeginUpdate();
    lvStars->Items->Clear();

    int filterClassIdx = cbClassFilter->ItemIndex;
    char targetClass = 0;
    switch (filterClassIdx) {
        case 1: targetClass = 'O'; break;
        case 2: targetClass = 'B'; break;
        case 3: targetClass = 'A'; break;
        case 4: targetClass = 'F'; break;
        case 5: targetClass = 'G'; break;
        case 6: targetClass = 'K'; break;
        case 7: targetClass = 'M'; break;
        default: targetClass = 0;   break;
    }

    AnsiString searchStr = AnsiString(edtSearch->Text).Trim().LowerCase();
    bool hasSearch = (searchStr.Length() > 0);

    const size_t maxDisplay = 2000;
    size_t displayed = 0;

    for (size_t i = 0; i < m_csvStars.size(); i++) {
        const CSVStarItem& s = m_csvStars[i];

        if (targetClass != 0 && s.spectClass != targetClass)
            continue;

        if (hasSearch) {
            AnsiString propLow = s.proper.LowerCase();
            if (propLow.Pos(searchStr) == 0)
                continue;
        }

        TListItem* item = lvStars->Items->Add();
        item->Caption = IntToStr(s.id);
        item->SubItems->Add(s.proper.IsEmpty() ? AnsiString("-") : s.proper);
        item->SubItems->Add(s.spect.IsEmpty() ? AnsiString("-") : s.spect);
        item->SubItems->Add(AnsiString(s.spectClass));
        item->SubItems->Add(FormatFloat("0.00", s.mag));
        item->SubItems->Add(FormatFloat("0.00", s.absmag));
        item->SubItems->Add(FormatFloat("0.0", s.dist));
        item->SubItems->Add(FormatFloat("0.000", s.x));
        item->SubItems->Add(FormatFloat("0.000", s.y));
        item->SubItems->Add(FormatFloat("0.000", s.z));
        item->SubItems->Add(FormatFloat("0.000000", s.vx));
        item->SubItems->Add(FormatFloat("0.000000", s.vy));
        item->SubItems->Add(FormatFloat("0.000000", s.vz));

        displayed++;
        if (displayed >= maxDisplay)
            break;
    }

    lvStars->Items->EndUpdate();

    if (StatusBarCSV->Panels->Count > 1) {
        StatusBarCSV->Panels->Items[1]->Text = 
            Format("Показано записей: %d из %d", ARRAYOFCONST(((int)displayed, (int)m_csvStars.size())));
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormStarsCSV::cbClassFilterChange(TObject *Sender)
{
    PopulateListView();
}
//---------------------------------------------------------------------------
void __fastcall TFormStarsCSV::btnSearchClick(TObject *Sender)
{
    PopulateListView();
}
//---------------------------------------------------------------------------
void __fastcall TFormStarsCSV::btnResetClick(TObject *Sender)
{
    cbClassFilter->ItemIndex = 0;
    edtSearch->Text = "";
    PopulateListView();
}
