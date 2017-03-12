#pragma once
#ifndef _Teacher_
#define _Teacher_
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Teacher {
private:
	string name;
	string last_name;
	vector<string> subject;
	int age;
	string identification_code;
public:
	Teacher() {
		this->name = "";
		this->last_name = "";
		this->age = 0;
		this->identification_code = "";
	}
	Teacher(string name1, string last_name1, string subject1, int age1,string identification_code1) {
		this->name = name1;
		this->last_name = last_name1;
		this->subject.push_back(subject1);
		this->age = age1;
		this->identification_code = identification_code1;
	}
	Teacher(string name1, string last_name1, vector<string> subject1, int age1, string identification_code1) {
		this->name = name1;
		this->last_name = last_name1;
		this->subject = subject1;
		this->age = age1;
		this->identification_code = identification_code1;
	}
	Teacher(const Teacher &object) {
		this->name = object.name;
		this->last_name = object.last_name;
		this->subject = object.subject;
		this->age = object.age;
		this->identification_code = object.identification_code;
	}
	Teacher& operator() (string name1, string last_name1, vector<string> subject1, int age1, string identification_code1) {
		this->name = name1;
		this->last_name = last_name1;
		this->subject = subject1;
		this->age = age1;
		this->identification_code = identification_code1;
		return *this;
	}
	void set_age(int age);
	void set_name(string name);
	void set_last_name(string last_name);
	void add_subject(string subject);
	void set_identification_code(string identification_code);
	void delete_subject(string subject);
	string return_name();
	string return_last_name();
	int return_age();
	string return_identification_code();
	int number_of_subjects();
	string subject_return(int i);
};

#endif