//---------------------------------------------------------------------------

#ifndef fcStarsCSVH
#define fcStarsCSVH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>

//---------------------------------------------------------------------------
struct CSVStarItem {
    int id;
    AnsiString proper;
    float mag;
    float absmag;
    AnsiString spect;
    char spectClass;
    float x, y, z;
    float vx, vy, vz;
    float dist;
};

//---------------------------------------------------------------------------
class TFormStarsCSV : public TForm
{
__published:	// IDE-managed Components
	TPanel *PanelTop;
	TLabel *lblFilter;
	TComboBox *cbClassFilter;
	TLabel *lblSearch;
	TEdit *edtSearch;
	TButton *btnSearch;
	TButton *btnReset;
	TLabel *lblTotalInfo;
	TListView *lvStars;
	TStatusBar *StatusBarCSV;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall cbClassFilterChange(TObject *Sender);
	void __fastcall btnSearchClick(TObject *Sender);
	void __fastcall btnResetClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);

private:	// User declarations
	std::vector<CSVStarItem> m_csvStars;
	void __fastcall PopulateListView();

public:		// User declarations
	__fastcall TFormStarsCSV(TComponent* Owner);
	void __fastcall LoadFromFile(String filePath);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormStarsCSV *FormStarsCSV;
//---------------------------------------------------------------------------
#endif
