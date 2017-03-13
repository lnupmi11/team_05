#include "Teacher.h"

void Teacher::set_age(int age) {
	this->age = age;
}

void Teacher::set_identification_code(string identification_code) {
	this->identification_code = identification_code;
}

void Teacher::set_last_name(string last_name) {
	this->last_name = last_name;
}

void Teacher::set_name(string name) {
	this->name = name;
}

void Teacher::add_subject(string subject) {
	this->subject.push_back(subject);
}

string Teacher::return_name() {
	return this->name;
}

string Teacher::return_last_name() {
	return this->last_name;
}

string Teacher::return_identification_code() {
	return this->identification_code;
}

int Teacher::return_age() {
	return this->age;
}

int Teacher::number_of_subjects() {
	return this->subject.size();
}

string Teacher::subject_return(int i) {
	return this->subject[i - 1];
}

void Teacher::delete_subject(string subject) {
	for (int i = 0; i < this->subject.size(); i++) {
		if (this->subject[i] == subject) {
			this->subject.erase(this->subject.begin() + i);
			break;
		}
	}
}

Teacher::Teacher() {
	{
		this->name = "";
		this->last_name = "";
		this->age = 0;
		this->identification_code = "";
	}
}

Teacher::Teacher(string name, string last_name, string subject, int age, string identification_code) {
		this->name = name;
		this->last_name = last_name;
		this->subject.push_back(subject);
		this->age = age;
		this->identification_code = identification_code;
}

Teacher::Teacher(string name, string last_name, vector<string> subject, int age, string identification_code) {
	this->name = name;
	this->last_name = last_name;
	this->subject = subject;
	this->age = age;
	this->identification_code = identification_code;
}

Teacher::Teacher(const Teacher &object) {
	this->name = object.name;
	this->last_name = object.last_name;
	this->subject = object.subject;
	this->age = object.age;
	this->identification_code = object.identification_code;
}