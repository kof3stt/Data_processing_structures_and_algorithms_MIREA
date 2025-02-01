#include <iostream>
#include "Table.h"
#include "Tickets.h"
using namespace std;

int main()
{
    system("chcp 1251");
    Table arr;
    int num;
    string date;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Заполнить информацию о проданных билетах с клавиатуры\n";
        cout << " 2. Заполнить информацию о проданных билетах из файла\n";
        cout << " 3. Вывести таблицу проданных билетов\n";
        cout << " 4. Добавить запись о продаже билета\n";
        cout << " 5. Определить количество билетов, проданных на поезд заданного номера и дате отправления\n";
        cout << " 6. Удалить запись о продаже билета\n";
        cout << " 7. Вывести сведения о количестве проданных билетов в каждый вагон поезда\n";
        cout << " 8. Вставить запись о продаже билета\n";
        cout << " 9. Завершение работы программы\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите количество проданных билетов\n";
            cin >> num;
            if (input_table(arr, num) == 1)
            {
                cout << " Неверное количество проданных билетов\n";
            }
            break;
        case 2:
            if (input_from_file(arr, "Tickets.txt") == 1)
            {
                cout << " Произошла ошибка при чтении из файла\n";
            }
            else
            {
                output_table(arr);
            }
            break;
        case 3:
            if (output_table(arr) == 1)
            {
                cout << " Пустая таблица\n";
            }
            break;
        case 4:
            if (append_ticket(arr, input_ticket(Tickets())) == 1)
            {
                cout << " Невозможно добавить запись о продаже билета\n";
            }
            else
            {
                output_table(arr);
            }
            break;
        case 5:
            cout << " Введите номер поезда: ";
            cin >> num;
            cout << " Введите дату отправления: ";
            cin >> date;
            if (number_sold_tickets_by_train_number(arr, num, date) == 0)
            {
                cout << " Не найдено билетов, проданных на поезд с заданным номером и датой отправления\n";
            }
            else
            {
                cout << " Было продано " << number_sold_tickets_by_train_number(arr, num, date) << " билетов на поезд с заданным номером и датой отправления" << endl;
            }
            break;
        case 6:
            cout << " Введите номер поезда, для которого будет удалена запись о проданном билете\n";
            cin >> num;
            if (delete_ticket(arr, num) == 1)
            {
                cout << " Не удалось удалить запись о билете по заданному номеру поезда\n";
            }
            else
            {
                output_table(arr);
            }
            break;
        case 7:
            cout << " Введите номер поезда, для которого нужно найти количество проданных билетов в каждый вагон\n";
            cin >> num;
            if (number_sold_tickets_by_car_number(arr, num) == 1)
            {
                cout << " Не найдено записей по продаже билетов в вагоны поезда с заданным номером\n";
            }
            break;
        case 8:
            cout << " Введите позицию вставляемой записи о продаже билета\n";
            cin >> num;
            if (insert_ticket(arr, num, input_ticket(Tickets())) == 1)
            {
                cout << " Невозможно вставить элемент\n";
            }
            else
            {
                output_table(arr);
            }
            break;
        case 9:
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }
    return 0;
}