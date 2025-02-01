#include "Table.h"
#include <iostream>
#include <fstream>
using namespace std;

Table::Table()
{
	data = vector <Tickets> ();
}

int input_table(Table& arr, int n)
{
	arr.data.clear();
	for (int i = 0; i < n; i++)
	{
		cout << " Введите информацию о(об) " << (i + 1) << " - ом(ем) проданном билете:\n";
		arr.data.push_back(input_ticket(Tickets()));
	}
	return 0;
}

int input_from_file(Table& arr, string file_name)
{
	ifstream itf(file_name);
	if (itf.is_open())
	{
		arr.data.clear();
		int i = 0;
		while (!itf.eof())
		{
			Tickets t;
			itf >> t.train_number >> t.car_number >> t.seat_number >> t.departure_date >> t.ticket_price;
			arr.data.push_back(t);
		}
		itf.close();
		return 0;
	}
	return 1;
}

int output_table(Table arr)
{
	if (arr.data.size() > 0)
	{
		cout << "---------------------------------------------------------------------------------------------------------------|\n";
		cout << "Номер поезда" << "     |   " << "Номер вагона" << "    |     " << "Номер места" << "     |     " << "Дата отправления" << "     |    " << "Стоимость билета" << "    |" << "\n";
		cout << "-----------------|-------------------|---------------------|--------------------------|------------------------" << "|" << endl;
		for (int i = 0; i < arr.data.size(); i++)
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
	for (int i = 0; i < arr.data.size(); i++)
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
	arr.data.push_back(t);
	return 0;
}

int number_sold_tickets_by_train_number(Table arr, int key, string date)
{
	int count = 0;
	for (int i = 0; i < arr.data.size(); i++)
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
	if (arr.data.size()!=0)
	{
		int pos = find_train_number(arr, key);
		if (pos != -1)
		{
			arr.data.erase(arr.data.begin() + pos);
			return 0;
		}
		return 1;
	}
	return 1;
}

int insert_ticket(Table& arr, int pos, Tickets t)
{
	if (pos >= 0 and pos <= arr.data.size())
	{
		arr.data.insert(arr.data.begin() + pos, t);
		return 0;
	}
	return 1;
}

int number_sold_tickets_by_car_number(Table arr, int key)
{
	const int N = 500;
	int temp[N]{ 0 };
	if (arr.data.size()!=0)
	{
		for (int i = 0; i < arr.data.size(); i++)
		{
			if (arr.data[i].train_number == key)
			{
				temp[arr.data[i].car_number] ++;
			}
		}
		for (int i = 0; i < N; i++)
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