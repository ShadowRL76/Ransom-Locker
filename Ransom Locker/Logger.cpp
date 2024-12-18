#include "Logger.h"

int Logger::OnGuiSuccess()
{
    wxLogMessage("Gui Initialized Successfully!"); 
    return LibErrors(GuiInitSuccess); 
}

int Logger::OnGuiFailure(const wxString& error)
{
    wxLogError("Failed to initialize the wxWidgets library: %s", error); 
    return wxWidgetsLibError;
}

int Logger::OnFileOpenSuccess(const wxString& filename) 
{

    if (filename.IsEmpty()) 
    {
        wxLogError("No file selected or filename is empty!");
        return FileErrors(emptyFileError); 
    }

    if (!wxFileExists(filename)) 
    { 
        wxLogError("The file '%s' does not exist.", filename); 
        return FileErrors(fileDoesNotExistError); 
    }
    if(wxFileExists(filename)) 
	{
        std::unique_ptr<wxString> m_file = std::make_unique<wxString>(filename); 
        wxLogMessage("Selected file is: %s", *m_file); 
	} 
    return FileErrors(fileSelectedMessage);
}