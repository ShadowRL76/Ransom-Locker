#include "Logger.h"

int Logger::OnGuiSuccess()
{
    {
        wxInitializer initializer;
        if (!initializer.IsOk())
        {
            wxLogError("Failed to initialize the wxWidgets library!");
            return LibErrors(wxWidgetsLibError);
        }
        wxLogMessage("Gui Initialized Successfully!");
        return LibErrors(GuiInitSuccess);
    }
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

    wxLogMessage("Selected file is: %s", filename);
    const wxString m_file = filename;
    return FileErrors(fileSelectedMessage);
}