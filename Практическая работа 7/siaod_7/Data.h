#pragma once
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

struct Data
{
	int* data = new int;
	int n;
};

void create_array(Data &data, int n);
void input_array(Data &data);
void output_array(Data data);
void random_input_array(Data& data);
void input_by_descending_order(Data& data);
void input_by_ascending_order(Data& data);
void insert_sort(Data& data);
int pow_of_two(int n);
void merge(int* data, int low, int n, bool dir);
void bitonic_sort(int* data, int low, int n, bool dir);
void quick_random_sort(Data& data,int low, int high);

void sort(int* data, int low, int n, bool dir);
void fast_sort(Data& data, int low, int high);