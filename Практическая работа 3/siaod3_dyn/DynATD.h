#pragma once
#include <iostream>
using namespace std;
typedef int typeitem;
struct DynATD
{
	int n;
	typeitem **X = nullptr;
	DynATD();
	~DynATD();
};
void create_array(DynATD& data);
void input_array(DynATD& data);
void random_input_array(DynATD& data);
void output_array(DynATD& data);
int find_min_elem(DynATD& data);