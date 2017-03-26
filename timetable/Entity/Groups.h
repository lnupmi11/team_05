#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Group {
private:
	string name; // назва спеціальності ( ПМІ)
	int number; // група ( 11 -- 15)
public:
	Group();

	Group(string n, int numb);
	Group(const Group& obj);
	void set_name(string n);
	string get_name();
	void set_number(int n);
	int get_number();
};
