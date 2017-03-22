#include "Rooms.h"

Room::Room() {
	this->last_name = "";
	this->name = "";
	this->number = "";
	this->number_subject = 0;
	this->subject = "";
}

Room::Room(const Room& obj) {
	this->last_name = obj.last_name;
	this->name = obj.name;
	this->number = obj.number;
	this->number_subject = obj.number_subject;
	this->subject = obj.subject;
}

Room::Room(string number, string subject, string name, string last_name, int number_subject) {
	this->last_name = last_name;
	this->name = name;
	this->number = number;
	this->number_subject = number_subject;
	this->subject = subject;
}

string Room::return_name() {
	return this->name;
}

string Room::return_last_name() {
	return this->last_name;
}

string Room::return_number() {
	return this->number;
}

int Room::return_number_subject() {
	return this->number_subject;
}

string Room::return_subject() {
	return this->subject;
}