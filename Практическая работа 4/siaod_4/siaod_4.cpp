#include <iostream>
#include <string.h>
#include <stdio.h>
#pragma warning(disable : 4996)
using namespace std;

char* transform_N(char *str)
{
    char str_N_num[512]{ '\0' };
    char str_N[512]{ '\0' };
    char numbers[11]{ '0','1','2','3','4','5','6','7','8','9','\0' };
    for (int i = 0; i < strlen(str); i++)
    {
        char temp[2]{ str[i],'\0' };
        if (strchr(numbers, str[i]) == NULL)
        {
            strcat(str_N, temp);
        }
        else
        {
            strcat(str_N_num, temp);
        }
    }
    strcpy(str, str_N);
    if (strlen(str_N_num) != 0)
    {
        char s = str_N_num[0];
        str_N_num[0] = str_N_num[strlen(str_N_num) - 1];
        str_N_num[strlen(str_N_num) - 1] = s;
    }
    strcat(str, str_N_num);
    return str;
}

char* transform_Y(char *str)
{
    char* str_Y = new char [strlen(str)] { '\0' };
    char numbers[11]{ '0','1','2','3','4','5','6','7','8','9','\0' };
    for (int i = 0; i < strlen(str); i++)
    {
        char temp[2]{ str[i],'\0' };
        if (strchr(numbers, str[i]) == NULL)
        {
            strcat(str_Y, temp);
        }
    }
    strcpy(str, str_Y);
    if (str_Y != nullptr)
    {
        delete[] str_Y;
    }
    return str;
}

int main()
{
    system("chcp 1251");
    int num;
    char str[1024]{'\0'};
    char symbol;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Ввести строку\n";
        cout << " 2. Вывести строку\n";
        cout << " 3. Преобразовать строку в соответсвии с управляющим символом\n";
        cout << " 4. Завершить работу\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите строку\n";
            cin.ignore();
            gets_s(str);
            break;
        case 2:
            if (strlen(str)!=0)
            {
                cout << str << endl;
            }
            else
            {
                cout << " Пустая строка\n";
            }
            break;
        case 3:
            if (strlen(str) != 0)
            {
                cout << " Введите один из возможных символов управления - N (перенести все цифры текста в конец предложения так, чтобы первая встреченная в исходном тексте цифра была последней цифрой, а последняя первой и был сохранен порядок следования остальных цифр) или Y (вывод текста без входящих в него цифр)\n";
                cin >> symbol;
                if (symbol == 'N')
                {
                    transform_N(str);
                    cout << str << endl;
                }
                else if (symbol == 'Y')
                {
                    transform_Y(str);
                    strlen(str) == 0 ? cout << " В результате преобразования получилась пустая строка\n" : cout << str << endl;
                }
                else
                {
                    cout << " Нет операции для введённого символа управления\n";
                }
            }
            else
            {
                cout << " Пустая строка\n";
            }
            break;
        case 4:
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }
    return 0;
}