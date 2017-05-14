#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Group {
	string id;
	string name; //(ПМІ-11)
public:
	Group();
	Group(string n, string i);
	Group(const Group& obj);
	void set_name(string);
	string get_name();
	void set_id(string);
	string get_id();
};
