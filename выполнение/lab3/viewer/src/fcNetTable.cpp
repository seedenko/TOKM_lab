//---------------------------------------------------------------------------

#include <vcl.h>
#include <typeinfo>
#include <fstream>

#pragma hdrstop

#include "fcNetScene.h"
#include "fcNetTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

String GetDataPath(String filename)
{
    String dir = ExtractFilePath(Application->ExeName);
    String candidates[] = {
        dir + "data\\" + filename,
        dir + filename,
        dir + "..\\..\\data\\" + filename,
        dir + "..\\data\\" + filename,
        "d:\\ForWorkStudy\\Projects\\bsu\\sidenko_tokm\\lab3\\data\\" + filename,
        "d:\\ForWorkStudy\\Projects\\bsu\\sidenko_tokm\\lab3\\viewer\\data\\" + filename,
        ".\\data\\" + filename
    };
    for (int i = 0; i < 7; i++) {
        if (FileExists(candidates[i])) return candidates[i];
    }
    return filename;
}

TFormNetTable *FormNetTable;
static String prefix = "";
int TablesCount;
String DBname, TableName;
//---------------------------------------------------------------------------
__fastcall TFormNetTable::TFormNetTable(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormNetTable::GetTables()
{
	DBname = RadioGroup1->Items->Strings[RadioGroup1->ItemIndex];
	RadioGroup2->Caption = DBname + " (таблицы):";

	// Connect to selected database
	FDConnection1->Connected = False;
	FDConnection1->DriverName = "SQLite";
	FDConnection1->LoginPrompt = False;
	FDConnection1->Params->DriverID = "SQLite";
	FDConnection1->Params->Database = GetDataPath(DBname + ".sqlite");
	FDConnection1->Connected = True;

    // Get tables list
	FDQuery1->Close();
	FDQuery1->Connection = FDConnection1;
	FDQuery1->SQL->Clear();
	FDQuery1->SQL->Text = \
	"SELECT name FROM sqlite_master WHERE type ='table' AND name NOT LIKE 'sqlite_%'";
	FDQuery1->Open();

	// Count tables in DB
	FDQuery1->Last();
	TablesCount = FDQuery1->RecordCount;
	FDQuery1->First();

	// Add tables list to RadioGroup
	if (TablesCount > 0) {
		RadioGroup2->Items->Clear();
		for (int i = 0; i < TablesCount; i++)
		{
			RadioGroup2->Items->Add(FDQuery1->FieldByName("name")->AsString);
			FDQuery1->Next();
		}
	}

	RadioGroup2->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormNetTable::GetTablesData()
{
	TableName = RadioGroup2->Items->Strings[RadioGroup2->ItemIndex];

    // Get all data from selected table
	FDQuery2->Close();
	FDQuery2->Connection = FDConnection1;
	FDQuery2->SQL->Clear();
	FDQuery2->SQL->Text = "SELECT * FROM " + TableName;
	FDQuery2->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFormNetTable::FormCreate(TObject *Sender)
{
	RadioGroup1->ItemIndex = 0;

	GetTables();
	GetTablesData();
}
//---------------------------------------------------------------------------
void __fastcall TFormNetTable::RadioGroup1Click(TObject *Sender)
{
	GetTables();
	GetTablesData();
}
//---------------------------------------------------------------------------
void __fastcall TFormNetTable::RadioGroup2Click(TObject *Sender)
{
    GetTablesData();
}
//---------------------------------------------------------------------------

