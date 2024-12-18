#include "RansomLockerApp.h"
#include <memory>
#include <string>

bool RansomLockerApp::OnInit()
{ 
    AppFrame* frame = new AppFrame();
    frame->SetSize(FRAME_WIDTH, FRAME_HEIGHT);  
    frame->SetBackgroundColour(DARK_THEME_GREY); 
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
    selectEncryptionTitle(new wxStaticText(this, wxID_ANY, "Select Encryption Method", wxPoint(270, 40), wxSize(NULL, NULL))),
    progressBarTitle(new wxStaticText(this, wxID_ANY, "Encryption Progress 50%", wxPoint(300, 210), wxSize(NULL, NULL))),
    progressBar(new wxGauge(this, wxID_ANY, 100, wxPoint(165, 150), wxSize(400, 25), wxGA_HORIZONTAL, wxDefaultValidator, "Progress"))

{
    buttons = { button1, button2, button3, button4 }; 

    SetupUI(); 
    BindEvents(); 
}

void AppFrame::SetupUI()
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL); 
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxFont headerFont(wxFontInfo(14).Bold());
    wxFont headerThreeFont(wxFontInfo(10).Bold());
    
    selectEncryptionTitle->SetForegroundColour("white");
    selectEncryptionTitle->SetFont(headerFont);

    progressBarTitle->SetForegroundColour("white");
    progressBarTitle->SetFont(headerThreeFont);  

    progressBar->SetBackgroundColour(CREAMY_WHITE);
    progressBar->SetValue(50);

    for (auto* button : buttons) 
    {
        button->SetForegroundColour(CREAMY_WHITE); 
        button->SetBackgroundColour(RED);  
    }

    toggleThemeButton->SetBackgroundColour(LIGHT_GREEN);  

    for(auto* button : buttons)
	{
		sizer->Add(button, 0, wxALL, 20); 
	}

    sizer->Add(toggleThemeButton, 0, wxALL, 20); 
    mainSizer->Add(0, 70, 0, wxEXPAND); 
    mainSizer->Add(sizer, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 0);   
    mainSizer->AddStretchSpacer();

    this->SetSizer(mainSizer); 

    for (auto* menuFile : { menuFile })
    {
        menuFile->Append(ID_Hello, "& Hello...\tCtrl + H", "Help string shown in status bar for this menu item"); 
        menuFile->AppendSeparator(); 
        menuFile->Append(ID_FileSelector, "&Select File...\tCtrl + S", "Select a file to encrypt");
        menuFile->AppendSeparator(); 
        menuFile->Append(wxID_EXIT); 
    }

    menuHelp->Append(wxID_ABOUT);
    menuBar->Append(menuFile, "&File"); 
    menuBar->Append(menuHelp, "&Help"); 

    SetMenuBar(menuBar);

}


void AppFrame::BindEvents()
{
    for (auto* button : buttons)
    {
        button->Bind(wxEVT_ENTER_WINDOW, &AppFrame::OnButtonHover, this); 
        button->Bind(wxEVT_LEAVE_WINDOW, &AppFrame::OnButtonLeave, this);
    }

    toggleThemeButton->Bind(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, &AppFrame::OnToggle, this); 


    Bind(wxEVT_MENU, [=](wxCommandEvent&) { wxLogMessage("Hello from a lambda!"); }, ID_Hello);
    Bind(wxEVT_MENU, &AppFrame::onAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, [=](wxCommandEvent&) { Close(true); }, wxID_EXIT);
    Bind(wxEVT_MENU, &AppFrame::FileSelector, this, ID_FileSelector);

}

void AppFrame::onAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}


void AppFrame::OnButtonHover(wxMouseEvent& event)
{
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    if(button)
    {
        button->SetForegroundColour(RED); 
        button->SetBackgroundColour(CREAMY_WHITE); 
        button->Refresh(); 
    }
    event.Skip();
}

void AppFrame::OnButtonLeave(wxMouseEvent& event)
{

    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    if (button)
    {
        button->SetForegroundColour(CREAMY_WHITE); 
        button->SetBackgroundColour(RED);
        button->Refresh(); 
    } 
    event.Skip();
} 

void AppFrame::OnToggle(wxCommandEvent& event)
{


    wxColor lightTheme(LIGHT_THEME_WHITE); 
    wxColor CurrentState = GetBackgroundColour();

    if (CurrentState != DARK_THEME_GREY)
    {
        SetBackgroundColour(DARK_THEME_GREY);
        toggleThemeButton->SetBackgroundColour(LIGHT_GREEN);
        selectEncryptionTitle->SetForegroundColour(BOLD);
        selectEncryptionTitle->SetForegroundColour(LIGHT_THEME_WHITE); 
        progressBarTitle->SetForegroundColour(BOLD);
        progressBarTitle->SetForegroundColour(LIGHT_THEME_WHITE); 
    }
    else 
    {
        SetBackgroundColour(LIGHT_THEME_WHITE); 
        toggleThemeButton->SetBackgroundColour(PINKISH_RED);
        selectEncryptionTitle->SetForegroundColour(BOLD); 
        progressBarTitle->SetForegroundColour(BOLD);
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

 