#include "BL.h"

void print_all_teachers_date() {
	vector<Teacher> objects = all_teachers_date();
	cout << "All teachers information :" << endl;
	for (int i = 0; i < objects.size(); i++) {
		cout << "Teacher number " << i + 1 << endl;
		cout << "Name and last name :" << objects[i].set_name() << " " << objects[i].set_last_name() << endl;
		cout << "Age :" << objects[i].set_age() << endl;
		cout << "Identification Code :" << objects[i].set_identification_code() << endl;
		cout << "Subjects : " << endl;
		for (int j = 1; j <= objects[i].number_of_subjects(); j++) {
			cout << j << ": " << objects[i].subject_return(j) << endl;
		}
	}
}

vector<Teacher> create_new_teacher(vector<Teacher> teachers) {
	string name;
	string last_name;
	vector<string> subject;
	int age;
	string identification_code;
	cout << "You create a new teacher" << endl << "Enter your Name\t";
	cin >> name;
	cout << "Enter your LastName\t";
	cin >> last_name;
	cout << "Enter your Age\t";
	cin >> age;
	cout << "Enter your Identification code\t";
	cin >> identification_code;
	cout << "How many items is teacher? ";
	int coll;
	cin >> coll;
	for (int i = 0; i < coll; i++) {
		cout << "Enter subject " << i + 1 << "  ";
		string subj;
		cin >> subj;
		subject.push_back(subj);
	}
	teachers.emplace_back(name, last_name, subject, age, identification_code);
	Save_new_teacher(name, last_name, subject, age, identification_code);
	return teachers;
}