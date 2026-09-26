object FormStarsCSV: TFormStarsCSV
  Left = 0
  Top = 0
  Caption = 'Stars Catalog (Stars.csv) - Sidenko Valeria'
  ClientHeight = 520
  ClientWidth = 980
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  TextHeight = 15
  object PanelTop: TPanel
    Left = 0
    Top = 0
    Width = 980
    Height = 48
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object lblFilter: TLabel
      Left = 12
      Top = 16
      Width = 63
      Height = 15
      Caption = 'Class Filter:'
    end
    object lblSearch: TLabel
      Left = 240
      Top = 16
      Width = 69
      Height = 15
      Caption = 'Search Name:'
    end
    object lblTotalInfo: TLabel
      Left = 600
      Top = 16
      Width = 120
      Height = 15
      Caption = 'Total Stars Loaded: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object cbClassFilter: TComboBox
      Left = 82
      Top = 12
      Width = 140
      Height = 23
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = 'All Classes'
      OnChange = cbClassFilterChange
      Items.Strings = (
        'All Classes'
        'Class O (Blue)'
        'Class B (Sky Blue)'
        'Class A (White)'
        'Class F (Yellow-White)'
        'Class G (Yellow, Sol)'
        'Class K (Orange)'
        'Class M (Red)')
    end
    object edtSearch: TEdit
      Left = 315
      Top = 12
      Width = 120
      Height = 23
      TabOrder = 1
    end
    object btnSearch: TButton
      Left = 442
      Top = 11
      Width = 65
      Height = 25
      Caption = 'Filter'
      TabOrder = 2
      OnClick = btnSearchClick
    end
    object btnReset: TButton
      Left = 512
      Top = 11
      Width = 65
      Height = 25
      Caption = 'Reset'
      TabOrder = 3
      OnClick = btnResetClick
    end
  end
  object lvStars: TListView
    Left = 0
    Top = 48
    Width = 980
    Height = 449
    Align = alClient
    Columns = <
      item
        Caption = 'ID'
        Width = 60
      end
      item
        Caption = 'Proper Name'
        Width = 110
      end
      item
        Caption = 'Spectral Type'
        Width = 90
      end
      item
        Caption = 'Class'
        Width = 50
      end
      item
        Caption = 'AppMag'
        Width = 70
      end
      item
        Caption = 'AbsMag'
        Width = 70
      end
      item
        Caption = 'Dist [pc]'
        Width = 75
      end
      item
        Caption = 'X [pc]'
        Width = 75
      end
      item
        Caption = 'Y [pc]'
        Width = 75
      end
      item
        Caption = 'Z [pc]'
        Width = 75
      end
      item
        Caption = 'Vx [pc/yr]'
        Width = 85
      end
      item
        Caption = 'Vy [pc/yr]'
        Width = 85
      end
      item
        Caption = 'Vz [pc/yr]'
        Width = 85
      end>
    GridLines = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 1
    ViewStyle = vsReport
  end
  object StatusBarCSV: TStatusBar
    Left = 0
    Top = 497
    Width = 980
    Height = 23
    Panels = <
      item
        Text = 'Student: Sidenko Valeria (Group 12002531)'
        Width = 320
      end
      item
        Text = 'Records in view: 0'
        Width = 200
      end
      item
        Text = 'Catalog: HYG v3 / Hipparcos (Stars.csv)'
        Width = 300
      end>
  end
end
