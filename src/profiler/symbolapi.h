/*=====================================================================
symbolapi.h
------------
This file is public domain and may be used for any purpose whatsoever.

Usage instructions:

Include this in your program, and define the following symbol:

int verysleepy__useSendMessage = 1;

Handle the WM_VERYSLEEPY_MSG message from your standard message loop,
as follows:

switch (wParam)
{
case VERYSLEEPY_WPARAM_SUPPORTED:
	return TRUE;

case VERYSLEEPY_WPARAM_GETADDRINFO:
	{
		VerySleepy_AddrInfo *info = (VerySleepy_AddrInfo *)lParam;
		if (IsMySpecialJitFunction())
		{
			wcscpy_s(info->name, L"Function name");
			return TRUE;
		}
	}
	return FALSE;

default:
	return FALSE;
}

=====================================================================*/

#pragma once

#include <winuser.h>

const UINT WM_VERYSLEEPY_MSG = WM_APP + 0x3117;
// Respond TRUE to a message with this param value to indicate support.
const WPARAM VERYSLEEPY_WPARAM_SUPPORTED = 0;
// Respond TRUE to a message wit this param value after filling in the addr name.
const WPARAM VERYSLEEPY_WPARAM_GETADDRINFO = 1;

struct VerySleepy_AddrInfo
{
	// Always zero for now.
	int flags;
	// This is the code pointer (always passed as 64 bits.)
	unsigned long long addr;
	// Write the name here.
	wchar_t name[256];
};