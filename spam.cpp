// spam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

void typeKey(WORD key, int delay)
{
	INPUT input;
	WORD vkey = key; 
	input.type = INPUT_KEYBOARD;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;
	input.ki.wVk = vkey;
	input.ki.dwFlags = 0; 
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));

	input.ki.wVk = VK_RETURN;
	input.ki.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));
	input.ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(1, &input, sizeof(INPUT));
	Sleep(delay);
}


int main()
{
	cout << "Press Numpad 1 to enable spamming (500ms start delay)" << endl;
	cout << "Press Numpad 9 to stop spamming" << endl;
	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			cout << "Spam Enabled" << endl;
			Sleep(500);
			while (!GetAsyncKeyState(VK_NUMPAD9))
			{
				typeKey(VK_DECIMAL, 10);
			}
			cout << "Spam Disabled" << endl;
		}
	}
}

