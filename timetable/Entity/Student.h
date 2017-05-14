#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Student {
	string id;
	string full_name;  
public:
	Group();
	Group(string f_n, string i);
	Group(const Student& obj);
	void set_full_name(string);
	string get_full_name();
	void set_id(string);
	string get_id();
};