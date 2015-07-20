// stdafx.cpp : source file that includes just the standard includes
// ConsoleApplication1.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
void print(_In_ const char* fmt, _In_ ...)
{
	char log_buffer[2048];
	va_list args;

	va_start(args,fmt);
	HRESULT hRes = StringCbVPrintfA(log_buffer, sizeof(log_buffer), fmt, args);
	if (S_OK != hRes)
	{
		fprintf(
			stderr,
			"%s, StringCbVPrintfA() failed. res = 0x%08x",
			__FUNCTION__,
			hRes
			);
		return;
	}

	OutputDebugStringA(log_buffer);
	fprintf(stdout, "%s \n", log_buffer);
}
int is_file_existsW(const wchar_t * file)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE handle = FindFirstFile(file, &FindFileData) ;
	int found = handle != INVALID_HANDLE_VALUE;
	if(found) 
	{
		//FindClose(&handle); this will crash
		FindClose(handle);
	}
	return found;
}
