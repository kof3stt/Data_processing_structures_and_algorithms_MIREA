#pragma once
#include <string>
#include <vector>
using namespace std;
struct Tickets
{
	int train_number; // номер поезда
	int car_number; // номер вагона
	int seat_number; // номер места
	string departure_date; // дата отправления
	int ticket_price; // стоимость билета
	Tickets();
};

Tickets input_ticket(Tickets t);