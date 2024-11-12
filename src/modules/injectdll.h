#pragma once

#include <windows.h>

typedef void (*DllMain)(HMODULE hModule, DWORD dwReason, void *lpReserved);

int injection() {
    // Load the DLL
    HMODULE hDll = LoadLibrary(TEXT("Sinum.dll"));
    if (hDll == NULL) {
        // Handle the error
        return -1;
    }

    // Get the function address
    DllMain func = (DllMain)GetProcAddress(hDll, "DllMain");
    if (func == NULL) {
        // Handle the error
        FreeLibrary(hDll);
        return -1;
    }

    // Call the function

    DWORD dwReason = DLL_PROCESS_ATTACH;

    func(hDll, dwReason, NULL);

    // Free the DLL after use
    FreeLibrary(hDll);

    return 0;
}