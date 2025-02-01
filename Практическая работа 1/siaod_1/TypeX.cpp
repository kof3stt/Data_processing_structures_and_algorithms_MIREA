#include "TypeX.h"
TypeX::TypeX()
{
	n = 0;
}
void input_data(TypeX& data)
{
	cout << "¬ведите " << data.n <<" "<< "чисел: ";
	for (int i = 0; i < data.n; i++)
	{
		cin >> data.X[i];
	}
}
void Random_input_data(TypeX& data)
{
	srand(time(NULL));
	for (int i = 0; i < data.n; i++)
	{
		data.X[i] = rand() % 100;
	}
}
void output_data(TypeX& data)
{
	cout << "Data is " << data.n << " numbers: ";
	for (int i = 0; i < data.n; i++)
	{
		cout << data.X[i] << " ";
	}
	cout << endl;
}
int deleteElem(TypeX& data, int pos)
{
	if (pos >= 0 and pos < data.n)
	{
		for (int i = pos + 1; i < data.n; i++)
		{
			data.X[i - 1] = data.X[i];
		}
		data.n--;
		return 0;
	}
	else
	{
		return 1;
	}
}
int insertElem(TypeX& data, typeitem n, int pos)
{
	if (pos >= 0 and pos <= data.n)
	{
		for (int i = data.n; i > pos; i--)
		{
			data.X[i] = data.X[i - 1];
		}
		data.X[pos] = n;
		data.n++;
		return 0;
	}
	else
	{
		return 1;
	}
}
bool check_palindrom(typeitem n)
{
	int copy_n = n, last_digit,res = 0;
	while (n > 0)
	{
		last_digit = n % 10;
		res = (res * 10) + last_digit;
		n /= 10;
	}
	return res == copy_n;
}
int special_findElem(TypeX& data)
{
	for (int i = 0; i < data.n; i++)
	{
		if (check_palindrom(data.X[i]))
		{
			data.Pos = i;
			return 0;
		}
	}
	return 1;
}
void special_deleteElem(TypeX& data)
{
	while (data.Pos != 0) { deleteElem(data, --data.Pos); }
}
void special_insertElem(TypeX& data,typeitem n)
{
	insertElem(data, n, data.Pos + 1);
}