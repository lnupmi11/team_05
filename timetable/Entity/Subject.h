#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Subject {
private:
	string id;
	string course_title; 
public:
	void set_course_title(string);
	string get_course_title();
	void set_id(string);
	string get_id();
Subject();
Subject(string course_title1,string id1); 
Subject(const Subject &object); 
};
