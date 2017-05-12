/*
This script is only used for removing specific parts of a large text file.
Specifically for SourcePawn code that executes CS:GO server commands (ie. ServerCommand("server_cmd_here");)
This will remove everything but the "server_cmd_here" part.
Useful if you need to convert a large ammount of SourcePawn code into a .cfg file
*/

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	ifstream fix;
	fix.open("fix.txt");
	ofstream temp;
	temp.open("temp.txt");
	if (fix.is_open())
	{
		string line;
		while (getline(fix, line))
		{
			bool startCount = false;
			bool secondQuote = false;
			int firstSub = 0;
			int length = 0;
			string subStrLine;
			char* tempCharA = new char[line.length() + 1];
			strcpy_s(tempCharA, line.length() + 1, line.c_str());
			for (int i = 0; i < line.length(); i++)
			{
				if (tempCharA[i] == '\"')
				{
					if (!secondQuote)
					{
						firstSub = i + 1;
						secondQuote = true;
					}
					else
					{
						subStrLine = line.substr(firstSub, length - 1);
						break;
					}
					startCount = true;
				}
				if (startCount)
				{
					length++;
				}
			}
			temp << subStrLine << endl;
		}
	}
	temp.close();
	fix.close();
	remove("fix.txt");
	rename("temp.txt", "fix.txt");
	cout << "Done." << endl;
}

