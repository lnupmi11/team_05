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
	string type;
	int capacity;
public:
	Room();
	Room(string number, string type, int capacity);
	Room(const Room& obj);
	string return_number();
	string return_type();
	int return_capacity();
	void set_type(string type);
	void set_capacity(int capacity);
};



