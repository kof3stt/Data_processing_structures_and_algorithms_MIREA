#pragma once
#include <string>

using namespace std;
struct Tickets
{
	int train_number; // ����� ������
	int car_number; // ����� ������
	int seat_number; // ����� �����
	string departure_date; // ���� �����������
	int ticket_price; // ��������� ������
	Tickets();
};

Tickets input_ticket(Tickets t);
void output_ticket(Tickets t);