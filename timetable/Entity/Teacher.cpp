#include "Teacher.h"

void Teacher::Edit_age(int age) {
	this->age = age;
}

void Teacher::Edit_identification_code(string identification_code) {
	this->identification_code = identification_code;
}

void Teacher::Edit_last_name(string last_name) {
	this->last_name = last_name;
}

void Teacher::Edit_name(string name) {
	this->name = name;
}

void Teacher::Edit_subject(string subject, int n) {
	this->subject[n] = subject;
}

string Teacher::set_name() {
	return this->name;
}

string Teacher::set_last_name() {
	return this->last_name;
}

string Teacher::set_identification_code() {
	return this->identification_code;
}

int Teacher::set_age() {
	return this->age;
}

int Teacher::number_of_subjects() {
	return this->subject.size();
}

string Teacher::subject_return(int i) {
	return this->subject[i - 1];
}