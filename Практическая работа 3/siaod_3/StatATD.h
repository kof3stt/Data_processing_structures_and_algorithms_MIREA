#pragma once
#include <iostream>
using namespace std;
const unsigned int N = 100;
typedef int typeitem;
struct StatATD
{
	int n = 0;
	typeitem X[N][N];
	StatATD();
};
void input_array(StatATD& data);
void random_input_array(StatATD& data);
void output_array(StatATD& data);
int find_min_elem(StatATD& data);