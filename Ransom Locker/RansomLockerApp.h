#ifndef RANSOM_LOCKER_APP_H 
#define RANSOM_LOCKER_APP_H

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include "Logger.h"




class RansomLockerApp : public wxApp {
public:
    bool OnInit() override;
};

class AppFrame : public wxFrame
{

private:
    wxMenu* menuFile;
    wxMenu* menuHelp;
    wxMenuBar* menuBar;
    wxButton* button1;
    wxButton* button2;
    wxButton* button3;
    wxButton* button4;
    wxStaticText* selectEncryptiontitle;
    wxStaticText* progressBarTitle;
    std::vector<wxButton*> buttons = { button1, button2, button3, button4 }; 
    wxGauge* progressBar;
    wxToggleButton* toggleThemeButton;
    wxButton* selectFileButton;
    Logger logger;


private:
    void onAbout(wxCommandEvent& event);
    void OnButtonHover(wxMouseEvent& event);
    void OnButtonLeave(wxMouseEvent& event);
    void OnToggle(wxCommandEvent& event);
    void FileSelector(wxCommandEvent& event);

public:
    AppFrame();
    Logger& GetLogger(); 
};



#endif 
