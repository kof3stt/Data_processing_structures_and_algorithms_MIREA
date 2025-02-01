#include <iostream>
using namespace std;
#include "TypeX.h"
#include <ctime>
int main()
{
    system("chcp 1251");
    int n, pos,num;
    typeitem x;
    TypeX arr;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Заполнить множество с клавиатуры\n";
        cout << " 2. Заполнить множество случайными числами\n";
        cout << " 3. Вывести множество\n";
        cout << " 4. Удалить элемент в позиции\n";
        cout << " 5. Вставить элемент в позицию\n";
        cout << " 6. Найти позицию элемента, который является палиндромом\n";
        cout << " 7. Удалить элементы массива, расположенные непосредственно перед элементом, содержащим число палиндром\n";
        cout << " 8. Вставить новый элемент в массив после элемента массива, который является палиндромом\n";
        cout << " 9. Завершить работу\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите размер множества: ";
            cin >> n;
            arr.n = n;
            if (n == 0 or n > N)
            {
                cout << " Неккоректный размер множества" << endl;
            }
            else
            {
                input_data(arr);
            }
            break;
        case 2:
            cout << " Введите размер множества: ";
            cin >> n;
            arr.n = n;
            if (n == 0 or n > N)
            {
                cout << " Неккоректный размер множества" << endl;
            }
            else
            {
                Random_input_data(arr);
            }
            break;
        case 3:
            if (arr.n == 0)
            {
                cout << " пустое множество" << endl;
            }
            else
            {
                output_data(arr);
            }
            break;
        case 4:
            if (arr.n == 0)
            {
                cout << " пустое множество" << endl;
            }
            else
            {
                cout << " Введите позицию удаляемого элемента: " << endl;
                cin >> pos;
                if (deleteElem(arr, pos))
                {
                    cout << " Удалить элемент не удалось " << endl;
                }
                else
                {
                    output_data(arr);
                }
            }
            break;
        case 5:
            if (arr.n == 0)
            {
                cout << " пустое множество" << endl;
            }
            else
            {
                cout << " введите элемент для вставки: " << endl;
                cin >> x;
                cout << " Введите позицию вставляемого элемента: " << endl;
                cin >> pos;
                if (insertElem(arr, x, pos))
                {
                    cout << " Невозможно вставить элемент " << endl;
                }
                else
                {
                    output_data(arr);
                }
            }
            break;
        case 6:
            if (arr.n == 0)
            {
                cout << " пустое множество" << endl;
            }
            else
            {
                if (special_findElem(arr) != 1)
                {
                    cout << " Позиция элемента палиндрома: " << arr.Pos << endl;
                }
                else
                {
                    cout << " Элемента палиндрома не найдено!" << endl;
                }
            }
            break;
        case 7:
            if (arr.n == 0)
            {
                cout << " пустое множество" << endl;
            }
            else if (special_findElem(arr) == 1)
            {
                cout << " элемента - палиндрома не найдено! " << endl;
            }
            else
            {
                special_deleteElem(arr);
                output_data(arr);
            }
            break;
        case 8:
            if (arr.n == 0)
            {
                cout << " пустое множество" << endl;
            }
            else if (special_findElem(arr) == 1)
            {
                cout << " элемента - палиндрома не найдено! " << endl;
            }
            else
            {
                cout << " Введите элемент для вставки: " << endl;
                cin >> x;
                special_insertElem(arr, x);
                output_data(arr);
            }
            break;
        case 9:
            return 0;
        default: cout << " Нет такого пункта" << endl;
        }
    }
    return 0;
}
