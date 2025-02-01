#include "Table.h"
#include <iostream>
#include <fstream>
using namespace std;

Table::Table()
{
	n = 0;
}

int input_table(Table& arr, int n)
{
	if (n >= 0 and n <= N)
	{
		arr.n = 0;
		for (int i = 0; i < n; i++)
		{
			cout << " Введите информацию о(об) " << (i + 1) << " - ом(ем) проданном билете:\n";
			arr.data[i] = input_ticket(arr.data[i]);
			arr.n++;
		}
		return 0;
	}
	return 1;
}

int input_from_file(Table& arr, string file_name)
{
	ifstream itf(file_name);
	if (itf.is_open())
	{
		int i = 0;
		while (!itf.eof())
		{
			itf >> arr.data[i].train_number >> arr.data[i].car_number >> arr.data[i].seat_number >> arr.data[i].departure_date >> arr.data[i].ticket_price;
			i++;
		}
		arr.n = i;
		itf.close();
		return 0;
	}
	return 1;
}

int output_table(Table arr)
{
	if (arr.n > 0 and arr.n <= N)
	{
		cout << "---------------------------------------------------------------------------------------------------------------|\n";
		cout << "Номер поезда" << "     |   " << "Номер вагона" << "    |     " << "Номер места" << "     |     " << "Дата отправления" << "     |    " << "Стоимость билета" << "    |" << "\n";
		cout << "-----------------|-------------------|---------------------|--------------------------|------------------------" << "|" << endl;
		for (int i = 0; i < arr.n; i++)
		{
			cout.width(10);
			cout << arr.data[i].train_number;
			cout.width(8);
			cout << "|";

			cout.width(10);
			cout << arr.data[i].car_number;
			cout.width(10);
			cout << "|";

			cout.width(12);
			cout << arr.data[i].seat_number;
			cout.width(10);
			cout << "|";

			cout.width(18);
			cout << arr.data[i].departure_date;
			cout.width(9);
			cout << "|";

			cout.width(14);
			cout << arr.data[i].ticket_price;
			cout.width(11);
			cout << "|" << endl;
			cout << "---------------------------------------------------------------------------------------------------------------|\n";
		}
		return 0;
	}
	return 1;
}

int find_train_number(Table arr, int key)
{
	for (int i = 0; i < arr.n; i++)
	{
		if (arr.data[i].train_number == key)
		{
			return i;
		}
	}
	return -1;
}

int append_ticket(Table& arr, Tickets t)
{
	if (arr.n >= 0 and arr.n < N)
	{
		arr.data[arr.n++] = t;
		return 0;
	}
	return 1;
}

int number_sold_tickets_by_train_number(Table arr, int key,string date)
{
	int count = 0;
	for (int i = 0; i < arr.n; i++)
	{
		if (arr.data[i].train_number == key and arr.data[i].departure_date == date)
		{
			count++;
		}
	}
	return count;
}

int delete_ticket(Table& arr, int key)
{
	if (arr.n > 0 and arr.n <= N)
	{
		int pos = find_train_number(arr, key);
		if (pos != -1)
		{ 
			for (int i = pos + 1; i < arr.n; i++)
			{
				arr.data[i-1] = arr.data[i];
			}
			arr.n--;
			return 0;
		}
		return 1;
	}
	return 1;
}

int insert_ticket(Table& arr, int pos, Tickets t)
{
	if (pos >= 0 and pos <= arr.n)
	{
		for (int i = arr.n; i > pos; i--)
		{
			arr.data[i] = arr.data[i - 1];
		}
		arr.data[pos] = t;
		arr.n++;
		return 0;
	}
	return 1;
}

int number_sold_tickets_by_car_number(Table arr, int key)
{
	int temp[512]{0};
	if (arr.n > 0 and arr.n <= N)
	{
		for (int i = 0; i < arr.n; i++)
		{
			if (arr.data[i].train_number == key)
			{
				temp[arr.data[i].car_number] ++;
			}
		}
		for (int i = 0; i < 500; i++)
		{
			if (temp[i] > 0)
			{
				cout << " В вагон номер " << i << " было продано " << temp[i] << " билетов\n";
			}
		}
		return 0;
	}
	return 1;
}
