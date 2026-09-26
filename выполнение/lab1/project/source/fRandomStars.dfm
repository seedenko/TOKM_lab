object Form1: TForm1
  Left = 0
  Top = 0
  Margins.Left = 2
  Margins.Top = 2
  Margins.Right = 2
  Margins.Bottom = 2
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#8470'1 '#8212' '#1057#1080#1076#1077#1085#1082#1086' '#1042#1072#1083#1077#1088#1080#1103
  ClientHeight = 720
  ClientWidth = 1000
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
  object GLSceneViewer1: TGLSceneViewer
    Left = 0
    Top = 0
    Width = 790
    Height = 701
    Camera = GLCamera1
    Buffer.BackgroundColor = clBlack
    FieldOfView = 140.000000000000000000
    PenAsTouch = False
    Align = alClient
    OnMouseDown = GLSceneViewer1MouseDown
    OnMouseMove = GLSceneViewer1MouseMove
    TabOrder = 0
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 701
    Width = 1000
    Height = 19
    Panels = <
      item
        Text = #1042#1088#1077#1084#1103' '#1075#1077#1085#1077#1088#1072#1094#1080#1080':'
        Width = 700
      end
      item
        Text = 'FPS:'
        Width = 100
      end>
  end
  object PanelLeft: TPanel
    Left = 790
    Top = 0
    Width = 210
    Height = 701
    Align = alRight
    TabOrder = 2
    object StaticText1: TStaticText
      Left = 16
      Top = 18
      Width = 80
      Height = 17
      Caption = #1063#1080#1089#1083#1086' '#1079#1074#1105#1079#1076':'
      TabOrder = 0
    end
    object seNStars: TSpinEdit
      Left = 105
      Top = 15
      Width = 90
      Height = 22
      MaxValue = 1000000
      MinValue = 1
      TabOrder = 1
      Value = 10000
    end
    object rgBlock: TRadioGroup
      Left = 12
      Top = 50
      Width = 185
      Height = 195
      Caption = #1050#1086#1085#1090#1077#1081#1085#1077#1088
      ItemIndex = 0
      Items.Strings = (
        #1050#1091#1073' (1024x1024x1024)'
        #1064#1072#1088' ('#1086#1073#1098#1077#1084' '#1089#1092#1077#1088#1099')'
        #1057#1092#1077#1088#1072' ('#1087#1086#1074#1077#1088#1093#1085#1086#1089#1090#1100')'
        #1062#1080#1083#1080#1085#1076#1088' ('#1086#1073#1098#1077#1084')'
        #1055#1086#1074#1077#1088#1093#1085#1086#1089#1090#1100' '#1094#1080#1083#1080#1085#1076#1088#1072
        #1050#1086#1085#1091#1089)
      TabOrder = 2
    end
    object rgMode: TRadioGroup
      Left = 12
      Top = 255
      Width = 185
      Height = 85
      Caption = #1056#1077#1078#1080#1084' '#1086#1090#1086#1073#1088#1072#1078#1077#1085#1080#1103
      ItemIndex = 0
      Items.Strings = (
        #1058#1086#1095#1082#1080' (TGLPoints)'
        #1057#1092#1077#1088#1099' (TGLSphere 7 '#1094#1074#1077#1090#1086#1074')')
      TabOrder = 3
      OnClick = rgModeClick
    end
    object chbLifetime: TCheckBox
      Left = 14
      Top = 350
      Width = 180
      Height = 17
      Caption = #1042#1088#1077#1084#1103' '#1089#1074#1077#1095#1077#1085#1080#1103' (1-100 '#1089')'
      Checked = True
      State = cbChecked
      TabOrder = 4
    end
    object btnDraw: TButton
      Left = 12
      Top = 385
      Width = 185
      Height = 32
      Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 5
      OnClick = btnDrawClick
    end
    object ButtonClear: TButton
      Left = 12
      Top = 425
      Width = 185
      Height = 28
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1089#1094#1077#1085#1091
      TabOrder = 6
      OnClick = ButtonClearClick
    end
  end
  object GLScene1: TGLScene
    Left = 24
    Top = 16
    object dcBlock: TGLDummyCube
      ShowAxes = True
      CubeSize = 1024.000000000000000000
      VisibleAtRunTime = True
      object Stars: TGLPoints
        NoZWrite = False
        Static = False
      end
    end
    object GLLightSource1: TGLLightSource
      Ambient.Color = {0000803F0000803F0000803F0000803F}
      ConstAttenuation = 1.000000000000000000
      SpotCutOff = 180.000000000000000000
      Position.Coordinates = {0000004500000045000000450000803F}
    end
    object GLCamera1: TGLCamera
      DepthOfView = 15000.000000000000000000
      FocalLength = 50.000000000000000000
      TargetObject = dcBlock
      Position.Coordinates = {0000C8440000C8440000C8440000803F}
    end
  end
  object GLCadencer1: TGLCadencer
    Scene = GLScene1
    OnProgress = GLCadencer1Progress
    Left = 206
    Top = 28
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 348
    Top = 28
  end
  object MainMenu1: TMainMenu
    Left = 549
    Top = 32
    object miFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object miFileClear: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100
        OnClick = miFileClearClick
      end
      object miFileExit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = miFileExitClick
      end
    end
    object miHelp: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object miHelpAbout: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = miHelpAboutClick
      end
    end
  end
end
