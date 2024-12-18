#include "RansomLockerApp.h"

IMPLEMENT_APP_NO_MAIN(RansomLockerApp)

extern "C" int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, wxCmdLineArgType lpCmdLine, int nCmdShow) {
    return wxEntry(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}

int main(int argc, char* argv[])
{
    if (!wxEntryStart(argc, argv)) {
        return -1; // Initialization failed
    }

    if (!wxTheApp || !wxTheApp->CallOnInit()) {
        return -1; // Initialization failed
    }

    int result = wxTheApp->OnRun();
    wxTheApp->OnExit();
    wxEntryCleanup();
    return result;
}
