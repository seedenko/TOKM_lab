//---------------------------------------------------------------------------

#ifndef fcHygViewerH
#define fcHygViewerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.CheckLst.hpp>
#include <Data.DB.hpp>
#include "GLS.BaseClasses.hpp"
#include "GLS.Cadencer.hpp"
#include "GLS.Coordinates.hpp"
#include "GLS.GeomObjects.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.VectorFileObjects.hpp"
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Phys.SQLite.hpp>
#include <FireDAC.Phys.SQLiteDef.hpp>
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <vector>

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
#include <FireDAC.Phys.SQLiteWrapper.Stat.hpp>
#include <FireDAC.Stan.ExprFuncs.hpp>

#include "GLS.Cadencer.hpp"
#include "GLS.Objects.hpp"
#include "GLS.Scene.hpp"
#include "GLS.SceneViewer.hpp"
#include "GLS.GeomObjects.hpp"
#include "GLS.VectorFileObjects.hpp"
#include "GLS.Mesh.hpp"
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

struct StarCatalogRecord
{
	int id;
	char proper[32];
	float x, y, z;
	float curX, curY, curZ;
	float vx, vy, vz;
	float mag;
	float absmag;
	char spectClass; // 'O', 'B', 'A', 'F', 'G', 'K', 'M'
	float r, g, b;
};

class TFormViewerHYG : public TForm
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
	TOpenTextFileDialog *OpenTextFileDialog;
	TGLPoints *pointStars;
	TMenuItem *Mode1;
	TMenuItem *Points1;
	TMenuItem *Delaunay1;
	TMenuItem *Voronoi1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TFDConnection *FDConnection1;
	TFDQuery *FDQuery1;
	TFDPhysSQLiteDriverLink *FDPhysSQLiteDriverLink1;
	TGLLines *GLLines1;
	TGLPolygon *GLPolygon1;
	TGLTetrahedron *GLTetrahedron1;
	TGLFreeForm *GLFreeForm1;
	TMenuItem *Data1;
	TPanel *PanelRight;
	TCheckListBox *CheckListBox1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Open1;
	TMenuItem *Save1;
	TMenuItem *SaveAs1;
	TMenuItem *Exit2;
	TMenuItem *N2;
	TMenuItem *OpenStarsCSV1;
	TMenuItem *N3;
	TMenuItem *Dynamics1;
	TMenuItem *DataTablesSQLite1;
	TMenuItem *DataStarsCSV1;
	TMenuItem *Help1;
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
	DelaunayBase __fastcall InitDelaunay(String filename, float color[]);
	VoronoiBase __fastcall InitVoronoi(String filename, float color[]);
	void __fastcall InitDraw();
	void __fastcall DrawPoints();
	void __fastcall DrawDelaunay();
	void __fastcall DrawVoronoi();
	void __fastcall CheckListBox1ClickCheck(TObject *Sender);
	void __fastcall Data1Click(TObject *Sender);
	void __fastcall New1Click(TObject *Sender);
	void __fastcall Exit2Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	void __fastcall OpenStarsCSV1Click(TObject *Sender);
	void __fastcall Dynamics1Click(TObject *Sender);
	void __fastcall DataStarsCSV1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
private:
	TStringList *tl; //
	TStringList *sl; //
	int CurrStarID; // Current star;
	int NumStars; // Number of stars in catalog
	float X, Y, Z, // Current coordinates for stars
	 R, G, B; // Current grade of star
	TVector3f Color;   // colors of spectral class

	std::vector<StarCatalogRecord> m_stars;
	bool m_bDynamicsActive;
	double m_simulatedYears;
	float m_timeScale;

	void __fastcall LoadStarsCSV(String filename);
	void __fastcall DrawCatalogStars();
	void __fastcall ResetDynamicPositions();

public:
	__fastcall TFormViewerHYG(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TFormViewerHYG *FormViewerHYG;
extern TFileName datapath;
//---------------------------------------------------------------------------
#endif
