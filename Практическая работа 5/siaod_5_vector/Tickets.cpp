#include "Tickets.h"
#include <iostream>
using namespace std;
Tickets::Tickets()
{
	train_number = 0;
	car_number = 0;
	seat_number = 0;
	departure_date = "";
	ticket_price = 0;
}

Tickets input_ticket(Tickets t)
{
	cout << " ������� ����� ������: ";
	cin >> t.train_number;
	cout << " ������� ����� ������: ";
	cin >> t.car_number;
	cout << " ������� ����� �����: ";
	cin >> t.seat_number;
	cout << " ������� ���� �����������: ";
	cin >> t.departure_date;
	cout << " ������� ��������� ������: ";
	cin >> t.ticket_price;
	return t;
}
