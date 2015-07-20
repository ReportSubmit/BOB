// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <Windows.h>
#include <stdlib.h>
#include <stdint.h>
#include <Strsafe.h>
#include <atlstr.h>
#include <crtdbg.h>
#include <string>
#include <handleapi.h>
#include "StopWatch.h"
#include "mmio.h"
#include "StatusCode.h"
#include "FileIoHelperClass.h"


void print(_In_ const char* fmt, _In_ ...);
int is_file_existsW(const wchar_t * file);

