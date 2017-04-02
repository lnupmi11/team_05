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


class Room {
private:
	string number;
	string type;
	int capacity;
public:
	Room();
	Room(string number, string type, int capacity);
	Room(const Room& obj);
	string return_number();
	string return_type();
	int return_capacity();
	void set_number(string number);
	void set_type(string type);
	void set_capacity(int capacity);
};

