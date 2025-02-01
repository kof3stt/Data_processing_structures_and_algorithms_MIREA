#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

void delete_substring(char* s, char* old_pos, char* pos)
{
	s[old_pos - s] = '\0';
	strcat(s, pos);
}

int main()
{
	system("chcp 1251");
	
	char s[512]{'\0'};
	cout << " Введите строку: ";
	gets_s(s);
	char* s1 = s;
	char* s2;

	while (s1 - s < strlen(s))
	{
		bool flag = 0;
		s2 = strchr(s1, ' ');
		if (s2 == nullptr)
		{
			s2 = s + strlen(s);
			flag = 1;
		}
		int size_s = s2 - s1;
		if (strtod(s1, &s2))
		{
			if (flag)
			{
				delete_substring(s, s1, s2);
			}
			else
			{
				delete_substring(s, s1, s2 + 1);
			}
			s1 += 1;
		}
		else
		{
			s1 += size_s + 1;
		}
	}
	cout << " Новая строка: " << s;
	return 0;
}