; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "CodeZ"
#define MyAppVersion "1.0"
#define MyAppPublisher "Idleman, Valentin CARRUESCO."
#define MyAppURL "http://blog.idleman.fr"
#define MyAppExeName "CodeZ.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{4176E61C-2425-4A3C-AA8B-B036477082BF}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
InfoBeforeFile=C:\Workpaces\QT\CodeZ\deploy\README.txt
OutputDir=C:\Workpaces\QT\CodeZ\deploy
OutputBaseFilename=CodeZ-setup
SetupIconFile=C:\Workpaces\QT\CodeZ\deploy\favicon.ico
Compression=lzma
SolidCompression=yes
WizardImageFile=C:\Workpaces\QT\CodeZ\deploy\presentation.bmp
WizardSmallImageFile=C:\Workpaces\QT\CodeZ\deploy\presentationMini.bmp

[Languages]
Name: "french"; MessagesFile: "compiler:Languages\French.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "C:\Workpaces\QT\CodeZ\release\CodeZ.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Workpaces\QT\CodeZ\deploy\libgcc_s_dw2-1.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Workpaces\QT\CodeZ\deploy\mingwm10.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Workpaces\QT\CodeZ\deploy\QtCore4.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Workpaces\QT\CodeZ\deploy\QtGui4.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\Workpaces\QT\CodeZ\deploy\QtNetwork4.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
