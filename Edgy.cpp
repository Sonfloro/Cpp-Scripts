// Edgy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <random>
#include <time.h>

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
	Sleep(delay);
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
	Sleep(delay + 50);
}




int main()
{
	srand(time(NULL));
	cout << "Enable Edgy typing with Numpad 1 (500ms start delay) " << endl;
	cout << "Disable Edgy typing with Numpad 9 " << endl;

	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			cout << "Edgy typing enabled" << endl;
			Sleep(500);
			while (!GetAsyncKeyState(VK_NUMPAD9))
			{
				int time = rand() % 100 + 51;
				typeKey(VK_SHIFT, time);
			}
			cout << "Edgy typing disabled" << endl;
		}
	}
}

