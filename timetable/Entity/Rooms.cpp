#include "Rooms.h"

Room::Room() {
	this->number = "";
	this->capacity = 0;
	this->type = "";
}

Room::Room(const Room& obj) {
	this->number = obj.number;
	this->capacity = obj.capacity;
	this->type = obj.type;
}

Room::Room(string number, string type, int capacity) {
	this->number = number;
	this->capacity = capacity;
	this->type = type;
}

string Room::return_number() {
	return this->number;
}

int Room::return_capacity() {
	return this->capacity;
}

string Room::return_type() {
	return this->type;
}

void Room::set_capacity(int capacity) {
	this->capacity = capacity;
}

void Room::set_number(string number) {
	this->number = number;
}

void Room::set_type(string type) {
	this->type = type;
}