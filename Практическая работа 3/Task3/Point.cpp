#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double x1, double y1)
{
	x = x1;
	y = y1;
}

void input_points(vector <Point>& data,int N)
{
	data.resize(N);
	for (int i = 0; i < N; i++)
	{
		cout << " Введите абсциссу и ординату " << i + 1 << " точки\n";
		cin >> data[i].x >> data[i].y;
	}
}

void output_points(vector <Point> data, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << '(' << data[i].x << ',' << data[i].y << ')' << endl;
	}
}

bool on_the_line(Point a, Point b,Point c)
{
	bool rule_1 = (c.x - a.x) / (b.x - a.x) == (c.y - a.y) / (b.y - a.y);
	bool rule_2 = (a.x == b.x and b.x == c.x) or (a.y == b.y and b.y == c.y);
	return rule_1 + rule_2;
}

bool check_all_points(vector<Point> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = i+1; j < data.size(); j++)
		{
			for (int x = j + 1; x < data.size(); x++)
			{
				if (on_the_line(data[i],data[j],data[x]))
				{
					cout << " Точки " << i + 1 << ", " << j + 1 << ", " << x + 1 << " лежат на одной прямой\n";
					return 1;
				}
			}
		}
	}
	return 0;
}