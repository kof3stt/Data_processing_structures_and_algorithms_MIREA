#pragma once
#include <iostream>
using namespace std;
//создание динамического массива языка Си
//void* malloc (объем памяти для структуры в байтах)
int create(int*& x, int n)
{
	x = (int*)malloc(n * sizeof(int));
	if (x == NULL) return 1; //нет достаточного объема
	return 0;
}

void input_array(int* x, int n)
{
	cout << "Введите " << n << " чисел ";
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
}

void output_array(int* x, int n)
{
	cout << "Массив X\n";
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << ' ';
	}
	cout << "\n\n";
}

//вставить значение в заданную позицию
//предусловие: 0<=pos<n, n>0
// 1 2 3 4 5 n=5 pos=2 val=100
// 1 2 100 3 4 5 
int insert_array(int*& x, int& n, int pos, int value) 
{
	if ((x = (int*)realloc(x, (n + 1) * sizeof(int))) == NULL) return 1;
	for (int i = n; i >= pos; i--)
		x[i] = x[i - 1];
	x[pos] = value;
	n++;
	return 0;
}

//удалить значение в заданной позиции
//предусловие: 0<=pos<n, n>0
void delete_array(int*& x, int& n, int pos) 
{
	for (int i = pos; i < n - 1; i++)
		x[i] = x[i + 1];
	x = (int*)realloc((int*)x, (n - 1) * sizeof(int));
	n--;
}



