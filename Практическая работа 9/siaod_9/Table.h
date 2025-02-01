#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

struct Data
{
	int key;
	string company;
	string surname;
};

struct Table
{
	Data* table;
	long long int n;
	Table();
};

int input_table(Table& arr, int n, string polis_file, string company_file, string surname_file);
int output_table(Table arr);
int simple_search(Table arr,long long int key);
int bareer_search(Table arr, long long int key);
void insert_sort(Table& arr);
int fibbonachi_search(Table arr, long long int key);