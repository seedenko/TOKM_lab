//---------------------------------------------------------------------------

#ifndef fcNetSceneH
#define fcNetSceneH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "GLS.Cadencer.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.CheckLst.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
//#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include "GLS.GeomObjects.hpp"
#include "GLS.VectorFileObjects.hpp"
#include "GLS.Mesh.hpp"
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include "uContainers.h"
#include "GLS.BaseClasses.hpp"
#include "GLS.Coordinates.hpp"
//---------------------------------------------------------------------------
struct DelaunayBase
{
	float *color;
	int nodeCount;
	double **node;
	int edgeCount;
	int **edge;
	//int faceCount;
	//int **face;
	//int tetraCount;
    //int **tetra;
};

struct VoronoiBase
{
	float *color;
	int nodeCount;
	double **node;
	int edgeCount;
	double **edge;
	//int faceCount;
	//int **face;
};

class TFormNetScene : public TForm
{
__published:	// IDE-managed Components
	TStatusBar *StatusBar1;
	TGLSceneViewer *GLSceneViewer1;
	TGLScene *GLScene1;
	TGLCadencer *GLCadencer1;
	TTimer *Timer1;
	TMainMenu *MainMenu1;
	TGLDummyCube *GLDummyCube1;
	TGLLightSource *GLLightSource1;
	TGLCamera *GLCamera1;
	TOpenTextFileDialog *OpenTextFileDialog1;
	TGLPoints *GLPoints1;
	TMenuItem *Mode1;
	TMenuItem *Points1;
	TMenuItem *Delaunay1;
	TMenuItem *Voronoi1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TMenuItem *Start1;
	TFDPhysSQLiteDriverLink *FDPhysSQLiteDriverLink1;
	TGLLines *GLLines1;
	TGLPolygon *GLPolygon1;
	TGLTetrahedron *GLTetrahedron1;
	TGLFreeForm *GLFreeForm1;
	TMenuItem *Data1;
	TPanel *PanelRight;
	TCheckListBox *chlbStarTypes;
	TRadioGroup *rgrContainer;
	TButton *btnDraw;
	TMenuItem *About1;
	void __fastcall GLSceneViewer1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall GLSceneViewer1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall GLCadencer1Progress(TObject *Sender, const double deltaTime, const double newTime);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Points1Click(TObject *Sender);
	void __fastcall Delaunay1Click(TObject *Sender);
	void __fastcall Voronoi1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Start1Click(TObject *Sender);
	void __fastcall chlbStarTypesClickCheck(TObject *Sender);
	void __fastcall Data1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);

private:	// User declarations
	DelaunayBase __fastcall InitDelaunay(String filename, float color[]);
	VoronoiBase __fastcall InitVoronoi(String filename, float color[]);
	void __fastcall InitDraw();
	void __fastcall DrawPoints();
	void __fastcall DrawDelaunay();
	void __fastcall DrawVoronoi();

public:		// User declarations
	__fastcall TFormNetScene(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormNetScene *FormNetScene;
extern String prefix;
//---------------------------------------------------------------------------
#endif
