#include "StatATD.h"
#include <ctime>
StatATD::StatATD()
{
	n = 0;
}

void input_array(StatATD& data)
{
	for (int i = 0; i < data.n; i++)
	{
		for (int j = 0; j < data.n; j++)
		{
			cin >> data.X[i][j];
		}
	}
}

void random_input_array(StatATD& data)
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

void output_array(StatATD& data)
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

int find_min_elem(StatATD& data)
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