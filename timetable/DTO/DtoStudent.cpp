#include "DtoStudent.h"

void DTO_Student::save_new_student_date(Student object)
{
	ofstream out;
	string way = "student\\" + object.get_id() + "\\date.txt";
	out.open(way, ios_base::trunc);
	out << object.get_full_name() << endl;
	out << object.get_id() << endl;
	out.close();
}
void DTO_Student::create_new_student(Student object)
{
	ofstream out;
	string folder_name = "student\\" + object.get_id();
	_mkdir(folder_name.c_str());
	string way = folder_name + "\\date.txt";
	out.open(way, ios_base::app);
	out << object.get_full_name() << endl;
	out << object.get_id() << endl;
	out.close();
	out.open("student\\student.txt", ios_base::app);
	out << object.get_id() << endl;
	out.close();
}
bool DTO_Student::is_student(string id)
{
	ifstream in("student\\student.txt");
	string line;
	while (!in.eof())  //
	{
		getline(in, line);
		if (line == id)
		{
			return true;
		}
		if (line == "")
		{
			return false;
		}
	}
	return false;
};
Student DTO_Student::find_date_student(string id)
{
	ifstream in;
	string way = "student\\" + id + "\\student.txt";
	in.open(way);
	if (in.is_open())
	{
		string line;
		Student obj;
		getline(in, line);
		obj.set_full_name(line);
		getline(in, line);
		obj.set_id(line);
		in.close();
		return obj;
	}
	else
	{
		cout << "This student not found" << endl;
		Student object;
		return object;
	}
}
vector<Student> DTO_Student::all_student_date()
{
	vector<Student> objects;
	ifstream students;
	ifstream in;
	string line, student_id;
	students.open("student\\student.txt");
	while (true)
	{
		getline(students, student_id);
		if (student_id == "") {
			break;
		}
		string way = "student\\" + student_id + "\\student.txt";
		in.open(way);
		Student object;
		getline(in, line);
		object.set_full_name(line);
		getline(in, line);
		object.set_id(line);
		in.close();
		objects.push_back(object);
	}
	return objects;
}
void DTO_Student::delete_student(string id)
{
	string way = "student\\" + id;
	string first = way + "\\date.txt";
	remove(first.c_str());
	_rmdir(way.c_str());
	ifstream students;
	vector<string>id_students;
	string line;
	students.open("student\\student.txt");
	while (true)
	{
		getline(students, line);
		if (line == "") {
			break;
		}
		if (line == id) {
			continue;
		}
		id_students.push_back(line);
	}
	students.close();
	ofstream out;
	way = "student\\student.txt";
	out.open(way, ios_base::trunc);
	for (int i = 0; i < id_students.size(); i++) {
		out << id_students[i] << endl;
	}
	out.close();
}