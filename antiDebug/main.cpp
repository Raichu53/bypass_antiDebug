#include "antiDebug.h"



DWORD WINAPI hack(HMODULE hMod)
{
    /*AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);*/
    disableDebuggerChecks();

    /*fclose(f);
    FreeConsole();*/
    FreeLibraryAndExitThread(hMod, 0);
    return 0;
}

BOOL WINAPI DllMain(
    HMODULE hDllModule,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved)  // reserved
{
    HANDLE hThread = nullptr;
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        hThread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)hack, hDllModule, 0, nullptr);
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:

        if (lpvReserved != nullptr)
        {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
    }
    if (hThread) {
        CloseHandle(hThread);
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}