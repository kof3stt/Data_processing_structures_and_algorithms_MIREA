#include <iostream>
#include "Data.h"
using namespace std;

int main()
{
    system("chcp 1251");
    Data array;
    int n;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Заполнить массив с клавиатуры\n";
        cout << " 2. Заполнить массив случайными числами\n";
        cout << " 3. Заполнить массив числами по возрастанию\n";
        cout << " 4. Заполнить массив числами по убыванию\n";
        cout << " 5. Вывести массив\n";
        cout << " 6. Выполнить сортировку простой вставки\n";
        cout << " 7. Выполнить битонную сортировку\n";
        cout << " 8. Выполнить рандомизированную быструю сортировку\n";
        cout << " 9. Завершить работу\n";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            cout << " Введите количество элементов в массиве: ";
            cin >> n;
            create_array(array, n);
            cout << " Введите " << array.n << " чисел\n";
            input_array(array);
            break;
        }
        case 2:
        {
            cout << " Введите количество элементов в массиве: ";
            cin >> n;
            create_array(array, n);
            random_input_array(array);
            break;
        }
        case 3:
        {
            cout << " Введите количество элементов в массиве: ";
            cin >> n;
            create_array(array, n);
            input_by_ascending_order(array);
            break;
        }
        case 4:
        {
            cout << " Введите количество элементов в массиве: ";
            cin >> n;
            create_array(array, n);
            input_by_descending_order(array);
            break;
        }
        case 5:
        {
            output_array(array);
            break;
        }
        case 6:
        {
            insert_sort(array);
            cout << " Отсортированный массив: \n";
            //output_array(array);
            break;
        }
        case 7:
        {
            sort(array.data,0,array.n,1);
            cout << " Отсортированный массив: \n";
            //output_array(array);
            break;
        }
        case 8:
        {
            fast_sort(array,0,array.n - 1);
            cout << " Отсортированный массив: \n";
            //output_array(array);
            break;
        }
        case 9:
        {
            delete[] array.data;
            return 0;
        }
        default:
            cout << " Нет такого пункта\n";
            break;
        }
    }
}
