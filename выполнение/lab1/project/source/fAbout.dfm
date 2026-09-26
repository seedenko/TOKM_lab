object FormAbout: TFormAbout
  Left = 0
  Top = 0
  Caption = 'About'
  ClientHeight = 283
  ClientWidth = 468
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poScreenCenter
  TextHeight = 15
  object Memo1: TMemo
    Left = 60
    Top = 50
    Width = 350
    Height = 120
    Alignment = taCenter
    Lines.Strings = (
      #1051#1072#1073#1086#1088#1072#1090#1086#1088#1085#1072#1103' '#1088#1072#1073#1086#1090#1072' '#8470'1'
      #1057#1090#1091#1076#1077#1085#1090#1082#1072': '#1057#1080#1076#1077#1085#1082#1086' '#1042#1072#1083#1077#1088#1080#1103
      #1043#1088#1091#1087#1087#1072': 12002531, '#1053#1048#1059' '#171#1041#1077#1083#1043#1059#187
      #1055#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1100': '#1076#1086#1094'. '#1042#1072#1089#1080#1083#1100#1077#1074' '#1055'.'#1042'.')
    TabOrder = 0
  end
  object ButtonClose: TButton
    Left = 195
    Top = 200
    Width = 80
    Height = 28
    Caption = 'Close'
    TabOrder = 1
    OnClick = ButtonCloseClick
  end
end
