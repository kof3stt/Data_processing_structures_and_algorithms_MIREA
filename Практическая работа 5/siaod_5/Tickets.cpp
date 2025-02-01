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
	cout << " Введите номер поезда: ";
	cin >> t.train_number;
	cout << " Введите номер вагона: ";
	cin >> t.car_number;
	cout << " Введите номер места: ";
	cin >> t.seat_number;
	cout << " Введите дату отправления: ";
	cin >> t.departure_date;
	cout << " Введите стоимость билета: ";
	cin >> t.ticket_price;
	return t;
}

void output_ticket(Tickets t)
{
	cout << " Номер поезда: " << t.train_number << endl << " Номер вагона: " << t.car_number << endl << " Номер места: " << t.seat_number << endl << " Дата отправления: " << t.departure_date << endl << " Стоимость билета: " << t.ticket_price << endl;
}
