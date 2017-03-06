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
public:
	void set_number(string);
	string get_number();
	void save_room();
	friend void get_data(string name , string lesson , string teacher, float time);
	
	Room()
	{
		this->number = "";
	}

	/*Room(string number) 
	{
		this->nubmer = number;
	}
	*/
	
	Room(const Room& obj) {
		this->number = obj.number;
		
	}
	
	~Room();
};



