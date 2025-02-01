#pragma once
#include "Point.h"
#include <iostream>
using namespace std;
struct Triangle
{
	Point A;
	Point B;
	Point C;
};

void generate_permutations(vector <Triangle>& figures,vector <Point> data, int M);
void output_permutations(vector <Triangle> figures);
bool compare_triangles(Triangle ABC, Triangle CDE);
bool check_segments(Point a, Point b, Point c, Point d);
bool check_inside(Triangle ABC, Triangle CDE);
void create_set(vector <Triangle>& figures,vector <Triangle>& new_set);