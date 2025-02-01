#pragma once
#include <iostream>
#include <string>
using namespace std;
typedef char typeitem;
struct node
{
	typeitem data;
	node* next = nullptr;
};

void input_list(node* p_head);
void create_list(node*& p_head);
int output_list(node* p_head);
void rec_output(node* p_head);
int insert_begin(node* p_head, node* x);
void insert(node*& p_head, int position);
int move_last(node*& p_head);
int find_space(node* p_head);
int delete_second_word(node* p_head);
int replace_word(node*& p_head, int k);