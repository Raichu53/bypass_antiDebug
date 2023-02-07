#pragma once

#include <iostream>
#include <windows.h>
#include <TlHelp32.h>
//IDP => IsDebuggerPresent()
#define ORDINAL_NUMBER_IDP 384

typedef BOOL(__stdcall* f_is_debugger_present)();

bool disableDebuggerChecks();
void resetPBE(PVOID ptrPEB);
PVOID GetPEB();


typedef struct _PEB {
    BYTE Reserved1[2];
    BYTE BeingDebugged;
    /*BYTE Reserved2[21];
    PPEB_LDR_DATA LoaderData;
    PRTL_USER_PROCESS_PARAMETERS ProcessParameters;
    BYTE Reserved3[520];
    PPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
    BYTE Reserved4[136];
    ULONG SessionId;*/
} PEB;