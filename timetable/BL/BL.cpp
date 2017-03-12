#include "BL.h"

void print_all_teachers_date() {
	vector<Teacher> objects = all_teachers_date();
	cout << "All teachers information :" << endl;
	for (int i = 0; i < objects.size(); i++) {
		cout << "Teacher number " << i + 1 << endl;
		cout << "Name and last name :" << objects[i].return_name() << " " << objects[i].return_last_name() << endl;
		cout << "Age :" << objects[i].return_age() << endl;
		cout << "Identification Code :" << objects[i].return_identification_code() << endl;
		cout << "Subjects : " << endl;
		for (int j = 1; j <= objects[i].number_of_subjects(); j++) {
			cout << j << ": " << objects[i].subject_return(j) << endl;
		}
	}
}

void create_new_teacher() {
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
	Save_new_teacher(name, last_name, subject, age, identification_code);
}

void replacemant_date_teacher() {
	system("cls");
	cout << "Enter ID which teacher you want to edit" << endl;
	string ID;
	cin >> ID;
	Teacher object;
	object = find_teacher(ID);
	if (object.return_identification_code() == "") {
		cout << "This teacher was not found." << endl;
	}
	else {
		string name, last_name;
		int age;
		cout << "You can change this data:" << endl;
		cout << "1) Name" << endl;
		cout << "2) Last name" << endl;
		cout << "3) Age" << endl;
		cout << "4) Subjects" << endl;
		cout << "PLease make your choice ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Enter a new name "; cin >> name; object.set_last_name(name); break;
		case 2: cout << "Enter a new last name "; cin >> last_name; object.set_last_name(last_name); break;
		case 3: cout << "Enter a new age "; cin >> age; object.set_age(age); break;
		default:
			break;
		}
		if (choice == 4) {
			cout << "You can choose this function :" << endl;
			cout << "1) Add new subject" << endl;
			cout << "2) Delete subject" << endl;
			int choice;
			cin >> choice;
			if (choice == 1) {
				string new_subject;
				cout << "Enter new subject ";
				cin >> new_subject;
				object.add_subject(new_subject);
			}
			if (choice == 2) {
				string delete_subject;
				cout << "Enter the subject you want to delete ";
				cin >> delete_subject;
				object.delete_subject(delete_subject);
			}
			update_teacher_subject(object);
			return;
		}
		update_teacher(object);
	}
}