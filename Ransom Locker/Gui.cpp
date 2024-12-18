#include "RansomLockerApp.h"
#include <memory>
#include <string>

bool RansomLockerApp::OnInit()
{ 
    AppFrame* frame = new AppFrame();
    frame->SetSize(800, 600); 
    frame->SetBackgroundColour("#161616");  
    frame->Show(true);  
    wxIcon icon;
    icon.LoadFile("C:\\Users\\Shadow\\source\\repos\\Ransom Locker\\Images\\logo.ico", wxBITMAP_TYPE_ICO);
    frame->SetIcon(icon);  
    frame->GetLogger().OnGuiSuccess(); 
    return true; 
}


enum
{
    ID_Hello = 1,
    ID_FileSelector = 2
};

AppFrame::AppFrame() :
    wxFrame(nullptr, wxID_ANY, "Ransom Locker"),
    menuFile(new wxMenu),
    menuBar(new wxMenuBar),
    menuHelp(new wxMenu),
    button1(new wxButton(this, wxID_ANY, "RCA Encryption")),
    button2(new wxButton(this, wxID_ANY, "AES Encryption")),
    button3(new wxButton(this, wxID_ANY, "DES Encryption")),
    button4(new wxButton(this, wxID_ANY, "Blowfish Encryption")),
    toggleThemeButton(new wxToggleButton(this, wxID_ANY, "")),
    selectFileButton(new wxButton(this, ID_FileSelector, "Select File")), 
    selectEncryptiontitle(new wxStaticText(this, wxID_ANY, "Select Encryption Method", wxPoint(270, 40), wxSize(NULL, NULL))),
    progressBarTitle(new wxStaticText(this, wxID_ANY, "Encryption Progress 50%", wxPoint(300, 210), wxSize(NULL, NULL))),
    progressBar(new wxGauge(this, wxID_ANY, 100, wxPoint(165, 150), wxSize(400, 25), wxGA_HORIZONTAL, wxDefaultValidator, "Progress"))

{

    wxFont headerFont(wxFontInfo(14).Bold());
    wxFont headerThreeFont(wxFontInfo(10).Bold());
    selectEncryptiontitle->SetForegroundColour("white");
    selectEncryptiontitle->SetFont(headerFont);
    progressBarTitle->SetForegroundColour("white");
    progressBarTitle->SetFont(headerThreeFont); 

    progressBar->SetBackgroundColour("#FDEDEC");
    progressBar->SetValue(50);


    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
   

    for (auto* button : buttons) 
    {
        button->Bind(wxEVT_ENTER_WINDOW, &AppFrame::OnButtonHover, this); 
        button->Bind(wxEVT_LEAVE_WINDOW, &AppFrame::OnButtonLeave, this); 

        button->SetForegroundColour("#FDEDEC"); 
        button->SetBackgroundColour("#ED2A25"); 
    }

    toggleThemeButton->SetBackgroundColour("#00CB7A"); 
    selectFileButton->SetBackgroundColour("#ED2A25");
    selectFileButton->SetPosition(wxPoint(300, 230)); 


    sizer->Add(button1, 0, wxALL, 20);  
    sizer->Add(button2, 0, wxALL, 20);
    sizer->Add(button3, 0, wxALL, 20);
    sizer->Add(button4, 0, wxALL, 20);
    sizer->Add(toggleThemeButton, 0, wxALL, 20); 


    mainSizer->Add(0, 70, 0, wxEXPAND); 
    mainSizer->Add(sizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);   
    mainSizer->AddStretchSpacer();
    this->SetSizer(mainSizer); 


    toggleThemeButton->Bind(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, &AppFrame::OnToggle, this);
    selectFileButton->Bind(wxEVT_BUTTON, &AppFrame::FileSelector, this, ID_FileSelector);



    menuFile->Append(ID_Hello, "& Hello...\tCtrl + H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT); 
    menuHelp->Append(wxID_ABOUT); 

    menuBar->Append(menuFile, "&File"); 
    menuBar->Append(menuHelp, "&Help"); 

    SetMenuBar(menuBar);

    Bind(wxEVT_MENU, [=](wxCommandEvent&) { wxLogMessage("Hello from a lambda!"); }, ID_Hello); 
    Bind(wxEVT_MENU, &AppFrame::onAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, [=](wxCommandEvent&) { Close(true); }, wxID_EXIT);
    
}



void AppFrame::onAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}


void AppFrame::OnButtonHover(wxMouseEvent& event)
{
    for (auto* button : buttons)
    {
        button->SetForegroundColour("#ED2A25");
        button->SetBackgroundColour("#FDEDEC");
        button->Refresh(); 
    }
}

void AppFrame::OnButtonLeave(wxMouseEvent& event)
{

    for (auto* button : buttons) 
    {
        button->SetForegroundColour("#FDEDEC");
        button->SetBackgroundColour("#ED2A25");
        button->Refresh();
    }
} 

void AppFrame::OnToggle(wxCommandEvent& event)
{

    wxColor darkTheme("#161616");
    wxColor lightTheme("white");
    wxColor CurrentState = GetBackgroundColour();

    if (CurrentState != darkTheme) 
    {
        SetBackgroundColour(darkTheme);
        toggleThemeButton->SetBackgroundColour("#00CB7A");
        selectEncryptiontitle->SetForegroundColour("bold");
        selectEncryptiontitle->SetForegroundColour("white");
        progressBarTitle->SetForegroundColour("bold");
        progressBarTitle->SetForegroundColour("white");
    }
    else 
    {
        
        SetBackgroundColour(lightTheme);
        toggleThemeButton->SetBackgroundColour("#F03B4A");
        selectEncryptiontitle->SetForegroundColour("bold"); 
        progressBarTitle->SetForegroundColour("bold"); 
    }
    Refresh(); 
}

void AppFrame::FileSelector(wxCommandEvent& event)
{
    wxString filename = wxFileSelector("Choose a file to open"); 
    int result = logger.OnFileOpenSuccess(filename); 

    switch (result)
    {
    case FileErrors::emptyFileError:
        break;
    case FileErrors::fileDoesNotExistError:
        break;
    case FileErrors::fileSelectedMessage:
        break;
    }
}

Logger& AppFrame::GetLogger()
{
    return logger;
}

 