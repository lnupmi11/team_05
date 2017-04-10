#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <string>
using namespace std;

class Student {
private:
	string name;
	string surname;
	string groupname;
	
public:
	Student();
	Student(string name, string surname, string groupname);
	Student(const Student& obj);
	string return_name();
	string return_surname();
	string return_groupname();
	void set_name(string name);
	void set_surname(string surname);
	void set_groupname(string groupname);
};



