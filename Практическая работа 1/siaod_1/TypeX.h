#pragma once
#include <iostream>
using namespace std;
typedef int typeitem;
const unsigned int N = 100;
struct TypeX
{
	unsigned int n = 0;
	unsigned int Pos = -1;
	typeitem X[N];
	TypeX();
};
void input_data(TypeX& data);
void Random_input_data(TypeX& data);
void output_data(TypeX& data);
int deleteElem(TypeX& data, int pos);
int insertElem(TypeX& data, typeitem n, int pos);
bool check_palindrom(typeitem n);
int special_findElem(TypeX& data);
void special_deleteElem(TypeX& data);
void special_insertElem(TypeX& data, typeitem n);


