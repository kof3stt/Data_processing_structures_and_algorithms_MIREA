#include "Table.h"

int main()
{
	system("chcp 1251");
	Table arr;
	long long int pos, number, n;
	while (true)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << " Меню\n";
		cout << " 1. Создать и заполнить таблицу\n";
		cout << " 2. Вывести таблицу\n";
		cout << " 3. Отсортировать таблицу по ключам\n";
		cout << " 4. Провести линейный поиск\n";
		cout << " 5. Провести линейный поиск с барьером\n";
		cout << " 6. Провести Фибоначчи поиск\n";
		cout << " 7. Завершить выполнение программы\n";
		cin >> number;
		switch (number)
		{
		case 1:
		{
			cout << "Введите количество элементов: ";
			cin >> n;
			if (input_table(arr, n,"Polis.txt","Company.txt","Surname.txt") == 1)
			{
				cout << " Произошла ошибка при чтении из файлов\n";
			}
			else
			{
				if (output_table(arr) == 1)
				{
					cout << " Пустая таблица\n";
				}
				break;
			}
			break;
		}
		case 2:
		{
			if (output_table(arr) == 1)
			{
				cout << " Пустая таблица\n";
			}
			break;
		}
		case 3:
		{
			insert_sort(arr);
			if (output_table(arr) == 1)
			{
				cout << " Пустая таблица\n";
			}
			break;
		}
		case 4:
		{
			if (arr.n != 0)
			{
				cout << " Введите ключ поиска: ";
				cin >> pos;
				cout << " Позиция записи с заданным ключем: " << simple_search(arr, pos) << endl;
			}
			else
			{
				cout << " Пустая таблица\n";
			}
			break;
		}
		case 5:
		{

			if (arr.n != 0)
			{
				cout << " Введите ключ поиска: ";
				cin >> pos;
				cout << " Позиция записи с заданным ключем: " << bareer_search(arr, pos) << endl;
			}
			else
			{
				cout << " Пустая таблица\n";
			}
			break;
		}
		case 6:
		{
			cout << " Введите ключ поиска: ";
			cin >> pos;
			cout << " Позиция записи с заданным ключем: " << fibbonachi_search(arr, pos) << endl;
			break;
		}
		case 7:
		{
			return 0;
		}
		default:
			cout << " Нет такого пункта\n";
		}
	}
}
