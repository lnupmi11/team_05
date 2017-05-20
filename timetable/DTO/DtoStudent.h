#pragma once
#include <fstream>
#include <string>
#include <direct.h>
#include "../Entity/Student.h"

using namespace std;

class DTO_Student{
public:
	void create_new_student(Student object);
	void save_new_student_data(Student object);
	Student find_student(string name , string surname);
	vector<Student> all_student_date();
	void delete_student(string name , string surname); 
};
