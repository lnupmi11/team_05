#pragma once
#ifndef _DTOSTUDENT_H_
#define _DTOSTUDENT_H_
#include "../Entity/Student.h"
#include <direct.h>
#include <fstream>
#include <string>
using namespace std;

class DTO_Student
{
public:
	void save_new_student_date(Student obj);
	void create_new_student(Student obj);
	bool is_student(string id);
	Student find_date_student(string id);
	vector<Student> all_student_date();
	void delete_student(string id);
};
#endif