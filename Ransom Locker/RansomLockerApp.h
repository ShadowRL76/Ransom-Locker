#ifndef RANSOM_LOCKER_APP_H 
#define RANSOM_LOCKER_APP_H

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include "Logger.h"

constexpr u_int FRAME_WIDTH = 800;
constexpr u_int FRAME_HEIGHT = 600; 
constexpr auto DARK_THEME_GREY = "#161616";
constexpr auto LIGHT_THEME_WHITE = "white";
constexpr auto LIGHT_GREEN = "#00CB7A";
constexpr auto CREAMY_WHITE = "#FDEDEC";
constexpr auto RED = "#ED2A25";
constexpr auto PINKISH_RED = "#F03B4A";
constexpr auto BOLD = "bold"; 

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
    wxStaticText* selectEncryptionTitle;
    wxStaticText* progressBarTitle;
    std::vector<wxButton*> buttons;
    wxGauge* progressBar;
    wxToggleButton* toggleThemeButton;
    Logger logger;


private:
    void SetupUI(); 
    void BindEvents(); 
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
