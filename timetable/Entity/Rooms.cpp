#include "Rooms.h"

Room::Room() {
	this->number = "";
	this->number_subject = 0;
	this->groups = "";
}

Room::Room(const Room& obj) {
	this->number = obj.number;
	this->number_subject = obj.number_subject;
	this->groups = obj.groups;
}

Room::Room(string number, string groups, int number_subject) {
	this->number = number;
	this->number_subject = number_subject;
	this->groups = groups;
}

string Room::return_number() {
	return this->number;
}

int Room::return_number_subject() {
	return this->number_subject;
}

string Room::return_groups() {
	return this->groups;
}