#pragma once
#include <vector>
#include <iostream>
using namespace std;
struct Point
{
	double x, y;
	Point();
	Point(double x1,double y1);
};

void input_points(vector <Point>& data,int N);
void output_points(vector <Point> data, int N);
bool on_the_line(Point a, Point b, Point c);
bool check_all_points(vector <Point> data);