#include "node.h"

void input_list(node* p_head)
{
	node* q;
	string str;
	cout << " ¬ведите строку, каждый символ которой будет сохранен в отдельном узле: ";
	cin.ignore();
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		q = new node();
		q -> data = str[i];
		insert_begin(p_head,q);
	}
}

void create_list(node*& p_head)
{
	node* q, * q1 = nullptr;
	string str;
	cout << " ¬ведите строку, каждый символ которой будет сохранен в отдельном узле: ";
	cin.ignore();
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		q = new node();
		q->data = str[i];
		q->next = nullptr;
		if (p_head == nullptr)
		{
			p_head = q; 
			q1 = p_head;
		}
		else
		{
			q1->next = q;
			q1 = q;
		}
	}
}

int output_list(node* p_head)
{
	if (p_head == nullptr)
		return 1;
	node* q = p_head;
	while (q != nullptr)
	{
		cout << q->data;
		q = q->next;
	}
	cout << endl;
	return 0;
}

void rec_output(node* p_head)
{
	node* q = p_head->next;
	if (p_head->next != nullptr)
	{
		rec_output(p_head->next);
	}
	if (p_head->next != nullptr)
	{
		cout << p_head->data;
	}
	else
	{
		cout << p_head->data;
	}
}

int insert_begin(node* p_head, node* x)
{
	if (p_head == nullptr)
	{
		return 1;
	}
	x->next = p_head->next;
	p_head->next = x;
	return 0;
}

void insert(node*& p_head, int position) 
{
	node* q = p_head;
	node* pos_node = nullptr;
	node* prev_pos = nullptr;
	int i = 1;
	while (q->next != nullptr) 
	{
		if ((i + 1) == position) 
		{
			pos_node = q->next;
			prev_pos = q;
		}
		q = q->next;
		i++;
	}
	if (pos_node != nullptr) 
	{
		prev_pos->next = nullptr;
		q->next = pos_node;
		node* temp = pos_node->next;
		pos_node->next = p_head;
		p_head = temp;
	}
}

int move_last(node*& p_head) 
{
	if (p_head == nullptr or find_space(p_head) == 0)
	{
		return 1;
	}
	node* q = p_head;
	int last_space = 1;
	int i = 1;
	while (q->next != nullptr)
	{
		if (q->data == ' ')
		{
			last_space = i;
		}
		q = q->next;
		i++;
	}
	insert(p_head, last_space);
	return 0;
}

int find_space(node* p_head)
{
	if (p_head == nullptr)
		return 0;
	node* q = p_head->next;
	int count = 0;
	int i = 0;
	while (q != nullptr)
	{
		if (q->data == ' ')
		{
			count++;
		}
		q = q->next;
		i++;
	}
	return count;
}


int delete_second_word(node* p_head) 
{
	if (find_space(p_head) != 0)
	{
		if (find_space(p_head) == 1)
		{
			while (p_head->next->data != ' ')
			{
				p_head = p_head->next;
			}
			p_head->next = nullptr;
			return 0;
		}
		else
		{
			while (p_head->next != nullptr)
			{
				if (p_head->data == ' ')
				{
					node* space = p_head;
					node* tmp1 = p_head->next;
					if (find_space(p_head) != 0)
					{
						while (tmp1->data != ' ')
						{
							node* tmp2 = tmp1;
							tmp1 = tmp1->next;
							delete tmp2;
						}
						space->next = tmp1->next;
						delete tmp1;
						return 0;
					}
					else
					{
						p_head->next = nullptr;
						return 0;
					}
				}
				p_head = p_head->next;
			}
		}
	}
	return 1;
}

int replace_word(node*& p_head, int k) 
{
	if (k <= 1 or k > (find_space(p_head) + 1))
	{
		return 1;
	}
	node* q1 = p_head;
	int i = 1;
	while (q1->next != nullptr) 
	{
		if (q1->data == ' ') 
		{
			i++;
			if (i == k) 
			{
				node* first_space = q1;
				q1 = q1->next;
				while (q1 != nullptr) 
				{
					if (q1->data != ' ') 
					{
						node* tmp = q1;
						q1 = q1->next;
						delete tmp;
					}
					else 
					{
						break;
					}
				}
				string data;
				cout << " ¬ведите новое слово: ";
				cin >> data;
				node* first = nullptr;
				node* last = nullptr;
				for (int i = 0; i < data.size(); i++)
				{
					node* q = new node;
					q->data = data[i];
					if (first == nullptr) 
					{
						first = q;
						last = first;
					}
					else 
					{
						last->next = q;
						last = q;
					}
				}
				first_space->next = first;
				last->next = q1;
				return 0;
			}
		}
		q1 = q1->next;
	}
	return 0;
}