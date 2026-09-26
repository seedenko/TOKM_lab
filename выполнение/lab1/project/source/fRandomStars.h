//---------------------------------------------------------------------------

#ifndef fRandomStarsH
#define fRandomStarsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "GLS.SceneViewer.hpp"
#include "GLS.Cadencer.hpp"
#include "GLS.Scene.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "GLS.Objects.hpp"
#include <Vcl.Menus.hpp>
#include <Vcl.Samples.Spin.hpp>
#include "GLS.BaseClasses.hpp"
#include "GLS.Coordinates.hpp"
#include "GLS.Color.hpp"
#include <vector>
#include "uContainers.h"

// Структура для хранения информации о времени свечения точки
struct StarLifeData {
    float maxLife;
    float curLife;
    float r, g, b, a;
};

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGLSceneViewer *GLSceneViewer1;
	TGLScene *GLScene1;
	TGLCadencer *GLCadencer1;
	TTimer *Timer1;
	TStatusBar *StatusBar1;
	TGLCamera *GLCamera1;
	TGLLightSource *GLLightSource1;
	TGLDummyCube *dcBlock;
	TGLPoints *Stars;
	TPanel *PanelLeft;
	TButton *ButtonClear;
	TRadioGroup *rgBlock;
	TRadioGroup *rgMode;
	TCheckBox *chbLifetime;
	TButton *btnDraw;
	TMainMenu *MainMenu1;
	TSpinEdit *seNStars;
	TStaticText *StaticText1;
	TMenuItem *miFile;
	TMenuItem *miFileClear;
	TMenuItem *miFileExit;
	TMenuItem *miHelp;
	TMenuItem *miHelpAbout;

	void __fastcall GLSceneViewer1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall GLCadencer1Progress(TObject *Sender, const double deltaTime, const double newTime);
	void __fastcall btnDrawClick(TObject *Sender);
	void __fastcall ButtonClearClick(TObject *Sender);
	void __fastcall miFileClearClick(TObject *Sender);
	void __fastcall miFileExitClick(TObject *Sender);
	void __fastcall miHelpAboutClick(TObject *Sender);
	void __fastcall rgModeClick(TObject *Sender);

private:	// User declarations
	int mx, my;
	std::vector<StarLifeData> m_starsLife;
	std::vector<TGLSphere*> m_spheres;

	void ClearScene();
	void GenerateStarsPoints(int count, int containerType);
	void GenerateStarsSpheres(int count, int containerType);
	void SaveFormCapture(String fullPath);
	void AutoCaptureSuite(String outDir);

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
