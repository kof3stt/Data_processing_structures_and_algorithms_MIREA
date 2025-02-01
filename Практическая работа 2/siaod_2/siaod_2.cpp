#include <iostream>
#include "Header.h"
int main()
{
	int n;
	int* array = NULL;
	setlocale(LC_ALL, "rus");
	cout << " Введите размер динамического массива: ";
	cin >> n;
	if (n <= 0) exit(1);
	if (create(array, n) == 1) {
		cout << " Нет достаточного объема памяти "; exit(2);
	}
	input_array(array, n);
	output_array(array, n);
	if (insert_array(array, n, 2, 199)==0)
	{
		cout << " Новый адрес array " << array<<endl;
		output_array(array,n);
	}
	else
	{
		cout << " Нет достаточного объема памяти " << endl;
	}


	free(array);

}
