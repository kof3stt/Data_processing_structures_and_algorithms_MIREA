#include <iostream>
#include <string>
using namespace std;

int is_number(string s)
{
    for (int i = 0; i < size(s); i++)
    {
        if (int(s[i]) < 48 or int(s[i]) > 57)
            return 0;
    }
    return 1;
}

string substring(string s, int old_pos, int pos)
{
    string word = "";
    for (int i = old_pos; i < pos; i++)
        word += s[i];
    return word;
}

int main()
{
    system("chcp 1251");
    string s;
    cout << " Введите строку: ";
    getline(cin, s);
    int pos = 0, old_pos = 0;
    for (int i = 0; i < size(s); i++)
    {
        if (s[i] == ' ')
        {
            if (pos == 0 and old_pos == 0)
            {
                old_pos = pos;
                pos = i;
            }
            else
            {
                old_pos = pos + 1;
                pos = i;
            }
            if (pos - old_pos > 0 and is_number(substring(s,old_pos, pos)))
            {
                s.erase(s.begin()+old_pos, s.begin()+pos+1);
                i -= (pos - old_pos);
                pos = old_pos - 1;
                old_pos = 0;
            }
        }
    }
    if (s.find(' ') == string::npos and is_number(s))
        s.erase(s.begin(), s.begin() + size(s));
    if (s.find(' ') != string::npos and is_number(substring(s, pos + 1, size(s))))
        s.erase(s.begin() + pos + 1, s.begin() + size(s));
    cout << " Новая строка: " << s;
    return 0;
}


