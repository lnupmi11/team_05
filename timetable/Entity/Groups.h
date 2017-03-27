#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Group {
private:
	string name; //(ПМІ-11)
public:
	Group();
	Group(string n);
	Group(const Group& obj);
	void set_name(string n);
	string get_name();
};
