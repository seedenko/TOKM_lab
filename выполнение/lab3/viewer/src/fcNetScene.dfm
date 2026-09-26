object FormNetScene: TFormNetScene
  Left = 0
  Top = 0
  Caption = 'Сетки TetGen 1.5 (Делоне / Вороной) — Сиденко Валерия (гр. 12002531)'
  ClientHeight = 512
  ClientWidth = 925
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  Position = poScreenCenter
  OnCreate = FormCreate
  OnMouseWheel = FormMouseWheel
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 493
    Width = 925
    Height = 19
    Panels = <
      item
        Text = 'Total points:'
        Width = 250
      end
      item
        Text = 'FPS:'
        Width = 50
      end>
    ExplicitTop = 468
    ExplicitWidth = 917
  end
  object GLSceneViewer1: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 739
    Height = 493
    Camera = GLCamera1
    Buffer.BackgroundColor = clBlack
    FieldOfView = 157.067413330078100000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    TabOrder = 1
  end
  object PanelRight: TPanel
    Left = 739
    Top = 0
    Width = 186
    Height = 493
    Align = alRight
    Caption = 'PanelRight'
    ShowCaption = False
    TabOrder = 2
    ExplicitLeft = 731
    ExplicitHeight = 468
    DesignSize = (
      186
      493)
    object chlbStarTypes: TCheckListBox
      Left = 8
      Top = 24
      Width = 170
      Height = 129
      Anchors = [akTop, akRight]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = 15
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemHeight = 15
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
      ShowHint = False
      TabOrder = 0
      OnClickCheck = chlbStarTypesClickCheck
    end
    object rgrContainer: TRadioGroup
      Left = 19
      Top = 167
      Width = 149
      Height = 114
      Caption = 'Container'
      ItemIndex = 0
      Items.Strings = (
        'Cube'
        'Sphere'
        'Sphere Surface')
      TabOrder = 1
    end
    object btnDraw: TButton
      Left = 38
      Top = 309
      Width = 116
      Height = 25
      Caption = 'Draw random stars'
      TabOrder = 2
    end
  end
  object GLScene1: TGLScene
    Left = 48
    Top = 16
    object GLCamera1: TGLCamera
      DepthOfView = 200.000000000000000000
      FocalLength = 50.000000000000000000
      TargetObject = GLDummyCube1
      Position.Coordinates = {0000004000000040000000400000803F}
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
      object GLPoints1: TGLPoints
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
    Left = 48
    Top = 80
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 632
    Top = 80
  end
  object MainMenu1: TMainMenu
    Left = 632
    Top = 16
    object Start1: TMenuItem
      Caption = 'Start'
      OnClick = Start1Click
    end
    object Mode1: TMenuItem
      Caption = 'Mode'
      object Points1: TMenuItem
        Caption = 'Points'
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
      OnClick = Data1Click
    end
    object About1: TMenuItem
      Caption = 'О программе'
      OnClick = About1Click
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 432
    Top = 8
  end
  object FDConnection1: TFDConnection
    Params.Strings = (
      
        'Database=C:\Users\dgoni\Documents\Embarcadero\Studio\STARS_DB\DA' +
        'TA\A_Delaunay.sqlite'
      'DriverID=SQLite')
    Left = 528
    Top = 88
  end
  object FDQuery1: TFDQuery
    Connection = FDConnection1
    Left = 424
    Top = 80
  end
  object FDPhysSQLiteDriverLink1: TFDPhysSQLiteDriverLink
    Left = 520
    Top = 160
  end
end
