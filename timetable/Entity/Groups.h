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
	vector<string> subject; // предмети які вивчають
public:
	Group() {
		name = "";
		number = 0;
	}
	Group(string n, int numb, string s) {
		name = n;
		number = numb;
		subject.push_back(s);
	}
	Group(string n, int numb, vector<string> s) {
		name = n;
		number = numb;
		subject = s;
	}
	Group(const Group& obj) {
		name = obj.name;
		number = obj.number;
		subject = obj.subject;
	}
	void set_name(string n);
	string get_name();
	void set_number(int n);
	int get_number();
	void save_group();
};
