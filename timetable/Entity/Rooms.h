#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <string>
using namespace std;

class Room {
private:
	string number;
	string subject;
	string name, last_name;
	int number_subject;
public:
	Room();
	Room(string number, string subject, string name, string last_name, int number_subject);
	Room(const Room& obj);
	string return_number();
	string return_subject();
	string return_name();
	string return_last_name();
	int return_number_subject();
};



