#include "Table.h"

Table::Table()
{
	n = 0;
}

int input_table(Table& arr, int n, string polis_file, string company_file, string surname_file)
{
	ifstream if_polis(polis_file);
	ifstream if_company(company_file);
	ifstream if_surname(surname_file);
	if (if_polis.is_open() and if_company.is_open() and if_surname.is_open())
	{
		arr.n = n;
		arr.table = new Data[n + 1];
		int i = 0;
		while (!if_polis.eof() and !if_company.eof() and !if_surname.eof() and i < n)
		{
			Data t;
			if_polis >> t.key;
			if_company >> t.company;
			if_surname >> t.surname;
			arr.table[i] = t;
			i++;
		}
		if_polis.close();
		if_company.close();
		if_surname.close();
		return 0;
	}
	return 1;
}

int output_table(Table arr)
{
	if (arr.n > 0)
	{
		cout << "------------------------------------------------------------------|\n";
		cout << "   Номер полиса" << "  |         " << "Компания" << "        |   " << "Фамилия владельца" << "  |"<< "\n";
		cout << "-----------------|-------------------------|----------------------" << "|" << endl;
		for (int i = 0; i < arr.n; i++)
		{
			cout.width(12);
			cout << arr.table[i].key;
			cout.width(6);
			cout << "|";

			cout.width(22);
			cout << arr.table[i].company;
			cout.width(4);
			cout << "|";

			cout.width(16);
			cout << arr.table[i].surname;
			cout.width(8);
			cout << "|\n";
		}
		return 0;
	}
	return 1;
}

int simple_search(Table arr, long long int key)
{
	int compare = 0; int move = 0;
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < arr.n; i++)
	{
		move++;
		compare++;
		if (arr.table[i].key == key)
		{
			compare++;
			cout << " Компания: " << arr.table[i].company << " \n Фамилия владельца: " << arr.table[i].surname << endl;
			auto end = chrono::high_resolution_clock::now();
			auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
			cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
			cout << "Количество операций перемещения: " << move << endl;
			cout << "Количество операций сравнения: " << compare << endl;
			cout << "Общее количество операций: " << compare + move << endl;
			return i;
		}
		compare++;
	}
	compare++;
	move++;
	auto end = chrono::high_resolution_clock::now();
	auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
	cout << "Количество операций перемещения: " << move << endl;
	cout << "Количество операций сравнения: " << compare << endl;
	cout << "Общее количество операций: " << compare + move << endl;
	return -1;
}

int bareer_search(Table arr, long long int key)
{
	int compare = 0; int move = 0;
	auto start = chrono::high_resolution_clock::now();
	int i = 0;
	move++;
	arr.table[arr.n + 1].key = key;
	move++;
	while (key != arr.table[i].key)
	{
		compare++;
		i++;
		move++;
	}
	compare+=2;
	if (i <= arr.n)
	{
		cout << " Компания: " << arr.table[i].company << " \n Фамилия владельца: " << arr.table[i].surname << endl;
		auto end = chrono::high_resolution_clock::now();
		auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
		cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
		cout << "Количество операций перемещения: " << move << endl;
		cout << "Количество операций сравнения: " << compare << endl;
		cout << "Общее количество операций: " << compare + move << endl;
		return i;
	}
	else
	{
		auto end = chrono::high_resolution_clock::now();
		auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
		cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
		cout << "Количество операций перемещения: " << move << endl;
		cout << "Количество операций сравнения: " << compare << endl;
		cout << "Общее количество операций: " << compare + move << endl;
		return -1;
	}
}

void insert_sort(Table& arr)
{
	for (int i = 1; i < arr.n; i++)
	{
		long long int x = arr.table[i].key;
		int j = i - 1;
		while (j >= 0 and arr.table[j].key >= x)
		{
			swap(arr.table [j] , arr.table[j + 1]);
			j--;
		}
		arr.table[j + 1].key = x;
	}
}

int fibbonachi_search(Table arr, long long int key)
{
	int compare = 0; int move = 0;
	auto start = chrono::high_resolution_clock::now();
	long long int fib2 = 0;
	long long int fib1 = 1;
	long long int fibM = fib2 + fib1;
	move += 3;
	while (fibM < arr.n) 
	{
		compare++;
		fib2 = fib1;
		fib1 = fibM;
		fibM = fib2 + fib1;
		move += 3;
	}
	compare++;
	int offset = -1;
	move++;
	while (fibM > 1) 
	{
		compare++;
		int i = min(offset + fib2, arr.n - 1);
		move++;
		if (arr.table[i].key < key) 
		{
			compare++;
			fibM = fib1;
			fib1 = fib2;
			fib2 = fibM - fib1;
			offset = i;
			move += 4;
		}
		else if (arr.table[i].key > key) 
		{
			compare++;
			fibM = fib2;
			fib1 = fib1 - fib2;
			fib2 = fibM - fib1;
			move += 3;
		}
		else
		{
			auto end = chrono::high_resolution_clock::now();
			auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
			cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
			cout << "Количество операций перемещения: " << move << endl;
			cout << "Количество операций сравнения: " << compare << endl;
			cout << "Общее количество операций: " << compare + move << endl;
			return i;
		}
	}
	compare++;
	if (fib1 && arr.table[offset + 1].key == key)
	{
		compare++;
		auto end = chrono::high_resolution_clock::now();
		auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
		cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
		cout << "Количество операций перемещения: " << move << endl;
		cout << "Количество операций сравнения: " << compare << endl;
		cout << "Общее количество операций: " << compare + move << endl;
		return offset + 1;
	}
	auto end = chrono::high_resolution_clock::now();
	auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
	cout << "Время выполнения: " << len.count() / 1e6 << " мс\n";
	cout << "Количество операций перемещения: " << move << endl;
	cout << "Количество операций сравнения: " << compare << endl;
	cout << "Общее количество операций: " << compare + move << endl;
	return -1;
}










