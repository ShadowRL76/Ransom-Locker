#include "RansomLockerApp.h"

IMPLEMENT_APP_NO_MAIN(RansomLockerApp) 


//Note: This is needed for the wxWidgets library to work with a custom Main Function!
extern "C" int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, wxCmdLineArgType lpCmdLine, int nCmdShow) {
    return wxEntry(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

int main(int argc, char* argv[])
{
   Logger logger;

   if (!wxEntryStart(argc, argv)) {
       logger.OnGuiFailure("wxEntryStart failed");
   }

   if (!wxTheApp || !wxTheApp->CallOnInit()) {
       logger.OnGuiFailure("CallOnInit failed");
   }

    int result = wxTheApp->OnRun();
    wxTheApp->OnExit();
    wxEntryCleanup();
    return result;
}
