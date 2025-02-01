#pragma once
#include "Tickets.h"
const int N = 100;
struct Table
{
	int n;
	Tickets data[N];
	Table();
};

int input_from_file(Table& arr, string file_name);
int input_table(Table& arr, int n);
int output_table(Table arr);
int find_train_number(Table arr, int key);
int append_ticket(Table& arr, Tickets t);
int number_sold_tickets_by_train_number(Table arr, int key, string date);
int delete_ticket(Table& arr, int key);
int insert_ticket(Table& arr, int pos, Tickets t);
int number_sold_tickets_by_car_number(Table arr, int key);