#include "Point.h"
#include "Triangle.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    system("chcp 1251");
    vector <Point> data;
    vector <Triangle> figures, new_set;
    int N,num, n = 0;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Задать координаты точек\n";
        cout << " 2. Вывести координаты всех точек\n";
        cout << " 3. Составить множество треугольников\n";
        cout << " 4. Завершение работы программы\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите значение переменной n для задания 3n точек\n";
            cin >> n;
            N = 3 * n;
            if (n == 0)
            {
                cout << " Пустое множество точек\n";
            }
            else
            {
                input_points(data,N);
            }
            break;
        case 2:
            if (n == 0)
            {
                cout << " Пустое множество точек\n";
            }
            else
            {
                output_points(data, N);
            }
            break;
        case 3:
            if (n == 0)
            {
                cout << " Пустое множество точек\n";
            }
            else
            {
                if (check_all_points(data) != 1)
                {
                    generate_permutations(figures, data, 3);
                    create_set(figures,new_set);
                }
            }
            break;
        case 4:
            data.clear();
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }
    return 0;
   
}