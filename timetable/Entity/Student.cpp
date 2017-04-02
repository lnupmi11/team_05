#include "Student.h"

Student::Student() {
	this->name = "";
	this->surname = "";
    this->groupname = "";
}

Student::Student(const Student& obj) {
	this->name = obj.name;
	this->surname = obj.surname;
    this->groupname = obj.groupname;
}

Student::Student(string name, string surname, string groupname) {
	this->name = name;
	this->surname = surname;
    this->groupname = groupname;
}

string Student::return_name() {
	return this->name;
}

string Student::return_groupname() {
	return this->groupname;
}

string Student::return_surname() {
	return this->surname;
}

void Student::set_groupname(string groupname_def) {
	this->groupname = groupname_def;
}

void Student::set_name(string name_def) {
	this->name = name_def;
}

void Student::set_surname(string surname_def) {
	this->surname = surname_def;
}