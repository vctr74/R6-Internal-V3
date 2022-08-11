// dllmain.cpp  
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include "XorString.h"
#include "Cheat.h"
BOOL DoOnce = false;
BOOL __stdcall DllMain( HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved )
{
    if ( !DoOnce )
    {
        DoOnce = true;
        CreateThread( 0, 0, ( LPTHREAD_START_ROUTINE ) Cheat::Run, 0, 0, 0 ); // detected
    }
    return TRUE;
}

