#include <iostream>
#include "node.h"
using namespace std;
int main()
{
    system("chcp 1251");
    node* q = nullptr;
    node* qq = new node;
    int number;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Заполнить список с вставкой новых узлов в начало списка\n";
        cout << " 2. Заполнить список вставкой новых узлов в конец списка\n";
        cout << " 3. Вывести список\n";
        cout << " 4. Переместить последнее слово в начало списка\n";
        cout << " 5. Удалить второе слово\n";
        cout << " 6. Заменить k - ое слово на новое слово\n";
        cout << " 7. Завершить работу\n";
        cin >> number;
        switch (number)
        {
        case 1:
            qq = new node;
            input_list(qq);
            rec_output(qq->next);
            cout << endl;
            break;
        case 2:
            q = nullptr;
            create_list(q);
            break;
        case 3:
            if (output_list(q))
            {
                cout << " Пустой список\n";
            }
            break;
        case 4:
            if (move_last(q))
            {
                cout << " Список пустой или содержит одно слово\n";
            }
            else
            {
                output_list(q);
            }
            break;
        case 5:
            if (delete_second_word(q))
            {
                cout << " Ошибка - список содержит одно слово или он пустой\n";
            }
            else
            {
                output_list(q);
            }
            break;
        case 6:
            cout << " Введите позицию слова, которое необходимо заменить на новое: ";
            cin >> number;
            if (replace_word(q, number))
            {
                cout << " Ошибка - слово с таким порядковым номером не найдено\n";
            }
            else
            {
                output_list(q);
            }
            break;
        case 7:
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }

}
