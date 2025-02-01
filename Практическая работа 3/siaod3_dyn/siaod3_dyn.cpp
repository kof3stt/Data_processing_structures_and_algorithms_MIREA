#include <iostream>
#include "DynATD.h"
using namespace std;
int main()
{
    system("chcp 1251");
    int num, n;
    DynATD data;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Заполнить матрицу с клавиатуры\n";
        cout << " 2. Заполнить матрицу случайными числами\n";
        cout << " 3. Вывести матрицу\n";
        cout << " 4. Найти минимальное значение среди элементов, расположенных под главной диагональю матрицы\n";
        cout << " 5. Завершение работы программы\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите размер матрицы: ";
            cin >> n;
            data.n = n;
            if (n == 0)
            {
                cout << " Матрица некоректного размера\n";
            }
            else
            {
                create_array(data);
                input_array(data);
            }
            break;
        case 2:
            cout << " Введите размер матрицы: ";
            cin >> n;
            data.n = n;
            if (n == 0)
            {
                cout << " Матрица некоректного размера\n";
            }
            else
            {
                create_array(data);
                random_input_array(data);
            }
            break;
        case 3:
            if (data.n == 0)
            {
                cout << " Матрица нулевого размера\n";
            }
            else
            {
                cout << "Data:\n";
                output_array(data);
            }
            break;
        case 4:
            if (data.n == 0)
            {
                cout << " Матрица нулевого размера\n";
            }
            else if (data.n == 1)
            {
                cout << " Под диагональю нету элементов - матрица размера 1\n";
            }
            else
            {
                cout << " Min Value is " << find_min_elem(data) << endl;
            }
            break;
        case 5:
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }
    return 0;
}