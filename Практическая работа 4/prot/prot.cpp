#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;


void deleteSubString(char* s, char* start, char* end)
{
	s[start - s] = '\0';
	strcat(s, end);
}


int main()
{
	setlocale(LC_ALL, "rus");
	char s[1024];

	cout << "Введите строку: ";
	gets_s(s);

	char* start = s, * end;
	while (start - s < strlen(s))
	{
		end = strchr(start, ' ');
		if (end == nullptr) end = s + strlen(s);
		int len = end - start;
		if (strtod(start, &end))
		{
			deleteSubString(s, start, end);
			start += 1;
		}
		else start += len + 1;
	}
	cout << s;
}