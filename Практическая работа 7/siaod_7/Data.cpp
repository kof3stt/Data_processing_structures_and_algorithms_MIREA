#include "Data.h"

long long int c = 0, m_m = 0;
void create_array(Data &data, int n)
{
	data.n = n;
	data.data = new int[n];
}

void input_array(Data& data)
{
	for (int i = 0; i < data.n; i++)
	{
		cin >> data.data[i];
	}
}

void output_array(Data data)
{
	for (int i = 0; i < data.n; i++)
	{
		cout << data.data[i] << " ";
	}
	cout << endl;
}

void random_input_array(Data& data)
{
	srand(time(NULL));
	for (int i = 0; i < data.n; i++)
	{
		data.data[i] = rand()%1000;
	}
}

void input_by_descending_order(Data& data)
{
	for (int i = 0; i < data.n; i++)
	{
		data.data[data.n - i - 1] = i + 1;
	}
}

void input_by_ascending_order(Data& data)
{
	for (int i = 0; i < data.n; i++)
	{
		data.data[i] = i + 1;
	}
}

void insert_sort(Data& data)
{
	auto begin = std::chrono::high_resolution_clock::now();
	long long c = 0, m = 0;
	for (int i = 1; i < data.n; i++)
	{
		c++;
		m++;
		int x = data.data[i];
		m++;
		int j = i - 1;
		m++;
		while (j >= 0 and data.data[j] >= x)
		{
			c ++;
			data.data[j + 1] = data.data[j];
			m++;
			j--;
			m++;
		}
		c++;
		data.data[j + 1] = x;
		m++;
	}
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
	cout << "The time: " << elapsed_ms.count()/1e6 << " ms\n";
	cout << "Количество операций сравнения: " << c << "\n";
	cout << "Количество операций перемещения: " << m << "\n";
	cout << "Общее количество операций: " << c + m << "\n";
}

int pow_of_two(int n)
{
	int k = 1;
	while (k > 0 && k < n)
	{
		k = k << 1;
	}
	return k >> 1;
}

void merge(int* data, int low, int n, bool dir)
{
	c++;
	if (n > 1)
	{
		int m = pow_of_two(n);
		c++;
		for (int i = low; i < low + n - m; i++)
		{
			m_m++;
			c += 2;
			if (dir == (data[i] > data[i + m]))
			{
				swap(data[i], data[i + m]);
				m_m++;
			}
			m_m++;
		}
		c++;
		m_m++;
		merge(data, low, m, dir);
		merge(data, low + m, n - m, dir);
	}
}

void bitonic_sort(int* data, int low, int n, bool dir)
{
	int m;
	c++;
	if (n > 1)
	{
		m = n / 2;
		m_m++;
		bitonic_sort(data, low, m, !dir);
		bitonic_sort(data, low + m, n - m, dir);
		merge(data, low, n, dir);
	}
}

void sort(int* data, int low, int n, bool dir)
{
	c = 0, m_m = 0;
	auto begin = std::chrono::high_resolution_clock::now();
	bitonic_sort(data, 0, n, 1);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cout << "The time: " << elapsed_ms.count()/1e6 << " ms\n";
	cout << "Количество операций сравнения: " << c << "\n";
	cout << "Количество операций перемещения: " << m_m << "\n";
	cout << "Общее количество операций: " << c + m_m << "\n";
}

void quick_random_sort(Data& data, int low, int high)
{
	srand(time(NULL));
	c++;
	if (low < high) 
	{
		int pivotIndex = low + rand() % (high - low + 1);
		m_m++;
		int pivotValue = data.data[pivotIndex];
		m_m++;
		swap(data.data[pivotIndex], data.data[high]);
		m_m++;
		int i = low - 1;
		m_m++;
		for (int j = low; j < high; j++)
		{
			c += 2;
			m_m++;
			if (data.data[j] < pivotValue) 
			{
				i++;
				m_m++;
				swap(data.data[i], data.data[j]);
				m_m++;
			}
		}
		c++;
		m_m+=2;
		swap(data.data[i + 1], data.data[high]);
		quick_random_sort(data, low, i);
		quick_random_sort(data, i + 2, high);
	}
}

void fast_sort(Data& data, int low, int high)
{
	c = 0, m_m = 0;
	auto begin = std::chrono::high_resolution_clock::now();
	quick_random_sort(data, 0, data.n - 1);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cout << "The time: " << elapsed_ms.count() / 1e6 << " ms\n";
	cout << "Количество операций сравнения: " << c << "\n";
	cout << "Количество операций перемещения: " << m_m << "\n";
	cout << "Общее количество операций: " << c + m_m << "\n";
}


