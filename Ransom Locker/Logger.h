#ifndef LOGGER_H
#define LOGGER_H
#include <wx/wx.h> 

enum LibErrors  
{
    wxWidgetsLibError = -1, 
    GuiInitSuccess = 0 
};

enum FileErrors { 
    emptyFileError = -1,
    fileDoesNotExistError = -2,
    fileSelectedMessage = 0,
};

class Logger
{
public:
    int OnGuiSuccess();
    int OnFileOpenSuccess(const wxString& filename); 
};


#endif 