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
	cout << " ¬ведите номер поезда: ";
	cin >> t.train_number;
	cout << " ¬ведите номер вагона: ";
	cin >> t.car_number;
	cout << " ¬ведите номер места: ";
	cin >> t.seat_number;
	cout << " ¬ведите дату отправлени€: ";
	cin >> t.departure_date;
	cout << " ¬ведите стоимость билета: ";
	cin >> t.ticket_price;
	return t;
}
