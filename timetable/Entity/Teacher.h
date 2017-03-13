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
	Teacher();
	Teacher(string name, string last_name, string subject, int age, string identification_code);
	Teacher(string name, string last_name, vector<string> subject, int age, string identification_code);
	Teacher(const Teacher &object);
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