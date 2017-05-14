#include "Student.h"

Student::Student() {
	id = "";
	full_name = "";
}
Student::Student(string f_n, string i) {
	id = i;
	full_name = f_n;
}
Student::Student(const Student& obj) {
	id = obj.id;
	full_name = obj.full_name;
}
void Student::set_full_name(string f_n) {
	full_name = f_n;
}
string Student::get_full_name() {
	return full_name;
}
void Student::set_id(string i) {
	id = i;
}
string Student::get_id() {
	return id;
}