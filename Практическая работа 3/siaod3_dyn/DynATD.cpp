#include "DynATD.h"
#include <ctime>

DynATD::DynATD()
{
	n = 0;
}

DynATD :: ~DynATD()
{
	for (int i = 0; i < n; i++)
	{
		if (X[i] != nullptr)
		{
			delete[] X[i];
		}
	}
	if (X != nullptr)
	{
		delete[] X;
	}
}

void create_array(DynATD& data)
{
	data.X = new typeitem * [data.n];
	for (int i = 0; i < data.n; i++)
	{
		data.X[i] = new typeitem[data.n];
	}
}

void input_array(DynATD& data)
{
	for (int i = 0; i < data.n; i++)
	{
		for (int j = 0; j < data.n; j++)
		{
			cin >> data.X[i][j];
		}
	}
}

void random_input_array(DynATD& data)
{
	srand(time(NULL));
	for (int i = 0; i < data.n; i++)
	{
		for (int j = 0; j < data.n; j++)
		{
			data.X[i][j] = rand() % 100;
		}
	}
}

void output_array(DynATD& data)
{
	for (int i = 0; i < data.n; i++)
	{
		for (int j = 0; j < data.n; j++)
		{
			cout << data.X[i][j] << "  ";
		}
		cout << '\n';
	}
}

int find_min_elem(DynATD& data)
{
	int mini = INT_MAX;
	for (int i = 0; i < data.n; i++)
	{
		for (int j = 0; j < data.n; j++)
		{
			if (i > j)
			{
				if (mini > data.X[i][j])
				{
					mini = data.X[i][j];
				}
			}
		}
	}
	return mini;
}