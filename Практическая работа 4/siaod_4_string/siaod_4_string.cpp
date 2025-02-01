#include <iostream>
#include <string>
using namespace std;

string transform_N(string &str)
{
    string str_N, str_N_num;
    string numbers = "0123456789";
    for (int i = 0; i < str.length(); i++)
    {
        if (numbers.find(str[i]) == string::npos)
        {
            str_N += str[i];
        }
        else
        {
            str_N_num += str[i];
        }
    }
    if (str_N_num.length() != 0)
    {
        char temp = str_N_num[0];
        str_N_num[0] = str_N_num[str_N_num.length() - 1];
        str_N_num[str_N_num.length() - 1] = temp;
    }
    return str = str_N + str_N_num;
}

string transform_Y(string &str)
{
    string str_Y;
    string numbers = "0123456789";
    for (int i = 0; i < str.length(); i++)
    {
        if (numbers.find(str[i]) == string::npos)
        {
            str_Y += str[i];
        }
    }
    return str = str_Y;
}

int main()
{
    system("chcp 1251");
    int num;
    string str;
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
            getline(cin, str);
            break;
        case 2:
            if (str.length() != 0)
            {
                cout << str << endl;
            }
            else
            {
                cout << " Пустая строка\n";
            }
            break;
        case 3:
            if (str.length() != 0)
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
                    str.length() == 0 ? cout << " В результате преобразования получилась пустая строка\n" : cout << str << endl;
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
