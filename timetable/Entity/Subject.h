#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Subject {
private:
	string course_title; // íàçâà ïðåäìåòó
public:
	void set_course_title(string);
	string get_course_title();
Subject();
Subject(string course_title1); 
Subject(const Subject &object); 
};
