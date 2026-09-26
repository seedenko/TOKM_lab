object FormViewerHYG: TFormViewerHYG
  Left = 0
  Top = 0
  Caption = 'Viewer HYG'
  ClientHeight = 652
  ClientWidth = 1086
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  Position = poScreenCenter
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  TextHeight = 16
  object StatusBar1: TStatusBar
    Left = 0
    Top = 633
    Width = 1086
    Height = 19
    Panels = <
      item
        Text = 'Total stars: 0'
        Width = 200
      end
      item
        Text = 'FPS: 0.0'
        Width = 80
      end
      item
        Text = 'Dynamics: OFF'
        Width = 200
      end
      item
        Text = 'Sidenko Valeria (gr. 12002531)'
        Width = 250
      end>
  end
  object GLSceneViewer1: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 944
    Height = 633
    Camera = GLCamera1
    Buffer.BackgroundColor = clBlack
    FieldOfView = 151.629547119140600000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    TabOrder = 1
  end
  object PanelRight: TPanel
    Left = 944
    Top = 0
    Width = 142
    Height = 633
    Align = alRight
    TabOrder = 2
    object CheckListBox1: TCheckListBox
      Left = 6
      Top = 64
      Width = 123
      Height = 161
      Hint = 'Spectral classes'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 18
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemHeight = 18
      Items.Strings = (
        '"A"'
        '"B"'
        '"F"'
        '"G"'
        '"K"'
        '"M"'
        '"O"')
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClickCheck = CheckListBox1ClickCheck
    end
  end
  object GLScene1: TGLScene
    Left = 136
    Top = 16
    object GLCamera1: TGLCamera
      DepthOfView = 1000.000000000000000000
      FocalLength = 80.000000000000000000
      TargetObject = GLDummyCube1
      Position.Coordinates = {0000004100000041000000410000803F}
    end
    object GLDummyCube1: TGLDummyCube
      ShowAxes = True
      CubeSize = 1.000000000000000000
      VisibleAtRunTime = True
      object GLLines1: TGLLines
        Visible = False
        NodeColor.Color = {0000803F0000803F0000803F0000803F}
        Nodes = <>
        Options = []
      end
      object pointStars: TGLPoints
        Visible = False
        NoZWrite = False
        Static = False
      end
      object GLPolygon1: TGLPolygon
        Nodes = <>
      end
      object GLTetrahedron1: TGLTetrahedron
        Material.Texture.BorderColor.Color = {9A93133FE4DB5B3FEBE0E03E0000803F}
        Direction.Coordinates = {000000000000803F0000000000000000}
        Position.Coordinates = {0000803F0000803F0000803F0000803F}
        Up.Coordinates = {8B8F67BF000000004A51DABE00000000}
        Visible = False
      end
      object GLFreeForm1: TGLFreeForm
        Material.FrontProperties.Diffuse.Color = {EBE0E03EE4DB5B3F9A93133F0000803F}
      end
    end
    object GLLightSource1: TGLLightSource
      ConstAttenuation = 1.000000000000000000
      Position.Coordinates = {0000000000000000000040400000803F}
      LightStyle = lsParallel
      Specular.Color = {0000803F0000803F0000803F0000803F}
      SpotCutOff = 180.000000000000000000
    end
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene1
    OnProgress = GLCadencer1Progress
    Left = 304
    Top = 16
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 448
    Top = 16
  end
  object MainMenu1: TMainMenu
    Left = 296
    Top = 120
    object File1: TMenuItem
      Caption = '&File'
      object New1: TMenuItem
        Caption = '&New (Load Models)'
        OnClick = New1Click
      end
      object Open1: TMenuItem
        Caption = '&Open...'
        OnClick = Open1Click
      end
      object OpenStarsCSV1: TMenuItem
        Caption = 'Open Stars &CSV...'
        OnClick = OpenStarsCSV1Click
      end
      object Save1: TMenuItem
        Caption = '&Save'
      end
      object SaveAs1: TMenuItem
        Caption = 'Save &As...'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Exit2: TMenuItem
        Caption = 'E&xit'
        OnClick = Exit2Click
      end
    end
    object Mode1: TMenuItem
      Caption = 'Mode'
      object Points1: TMenuItem
        Caption = 'Points (HYG Catalog)'
        RadioItem = True
        OnClick = Points1Click
      end
      object Delaunay1: TMenuItem
        Caption = 'Delaunay'
        RadioItem = True
        OnClick = Delaunay1Click
      end
      object Voronoi1: TMenuItem
        Caption = 'Voronoi'
        RadioItem = True
        OnClick = Voronoi1Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Dynamics1: TMenuItem
        Caption = 'Proper Motion (Dynamics)'
        OnClick = Dynamics1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        OnClick = Exit1Click
      end
    end
    object Data1: TMenuItem
      Caption = 'Data'
      object DataTablesSQLite1: TMenuItem
        Caption = 'SQLite Tables (Delaunay & Voronoi)'
        OnClick = Data1Click
      end
      object DataStarsCSV1: TMenuItem
        Caption = 'Stars Catalog (Stars.csv)'
        OnClick = DataStarsCSV1Click
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object About1: TMenuItem
        Caption = 'About...'
        OnClick = About1Click
      end
    end
  end
  object OpenTextFileDialog: TOpenTextFileDialog
    Filter = 'Comma delimiter|*.csv|Data ASCII|*.dat|All|*.*'
    Left = 136
    Top = 112
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      
        'Database=C:\Users\dgoni\Documents\Embarcadero\Studio\STARS_DB\DA' +
        'TA\A_Delaunay.sqlite'
      'DriverID=SQLite')
    Left = 648
    Top = 32
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    Left = 648
    Top = 120
  end
  object FDPhysSQLiteDriverLink1: TFDPhysSQLiteDriverLink
    Left = 800
    Top = 32
  end
end
