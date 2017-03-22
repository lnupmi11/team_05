#include "BL.h"

bool start_login() {
	Login object;
	string login, password;
	cin >> login >> password;
	if (object.check_login(login, password)) {
		return true;
	}
	else
	{
		return false;
	}
}

void Start() {
	cout << "Enter your login and password" << endl;
	int count_try = 0;
	while (!start_login()) {
		cout << "Error. Please try again" << endl;
		count_try++;
		if (count_try == 5) {
			cout << "Limit attempts exhausted. Please try again later";
			return;
		}
	}
	while (true)
	{
		cout << "Available menu items :" << endl;
		cout << "1. Teacher;" << endl << "2. Groups" << endl << "3. Rooms" << endl << "4. Subject" << endl << "5. Exit" << endl;
		int i;
		cin >> i;
		switch (i)
		{
			case 1: teacher_menu(); break;
			case 5: return;
			default:
				break;
		}
	}
}

void teacher_menu() {
	while (true) {
		int i;
		cout << "1-create; 2-print_all; 3-information about teacher; 4-edit; 5-delete; 6-exit;" << "\nset option: ";
		cin >> i;
		switch (i)
		{
		case 1: create_new_teacher(); break;
		case 2: print_all_teachers_date(); break;
		case 3: find_information_about_teacher(); break;
		case 4: replacemant_date_teacher(); break;
		case 5: delete_teacher(); break;
		default:
			break;
		}
		if (i == 6) {
			break;
		}
	}
}

void print_all_teachers_date() {
	system("cls");
	DTO_Teacher dto;
	vector<Teacher> objects = dto.all_teachers_date();
	cout << "All teachers information :" << endl;
	cout << endl;
	for (int i = 0; i < objects.size(); i++) {
		cout << "Teacher number " << i + 1 << endl;
		cout << "Name and last name :" << objects[i].return_name() << " " << objects[i].return_last_name() << endl;
		cout << "Age :" << objects[i].return_age() << endl;
		cout << "Identification Code :" << objects[i].return_identification_code() << endl;
		cout << "Subjects : " << endl;
		for (int j = 1; j <= objects[i].number_of_subjects(); j++) {
			cout << j << ": " << objects[i].subject_return(j) << endl;
		}
		cout << endl;
	}
}

void create_new_teacher() {
	system("cls");
	DTO_Teacher dto;
	string name;
	string last_name;
	vector<string> subject;
	string age;
	string identification_code;
	cout << "You create a new teacher" << endl << "Enter your Name\t";
	cin >> name;
	cout << "Enter your LastName\t";
	cin >> last_name;
	cout << "Enter your Age\t";
	cin >> age;
	while (true)
	{
		if (is_number(age))
		{
			break;
		}
		else {
			cout << "You entered incorrect data. Please try again " << endl;
			cin >> age;
		}
	}
	cout << "Enter your Identification code\t";
	cin >> identification_code;
	while (true) {
		bool result = dto.check_ID(identification_code);
		if (result == true) {
			cout << "PLease enter new ID, because this ID exist" << endl;
			cin >> identification_code;
		}
		else {
			break;
		}
	}
	cout << "How many items is teacher? ";
	int coll;
	cin >> coll;
	for (int i = 0; i < coll; i++) {
		cout << "Enter subject " << i + 1 << "  ";
		string subj;
		cin >> subj;
		subject.push_back(subj);
	}
	Login log;
	log.save_new_user(identification_code);
	Teacher object(name, last_name, subject, stoi(age), identification_code);
	dto.Save_new_teacher(object);
}

void replacemant_date_teacher() {
	system("cls");
	DTO_Teacher dto;
	cout << "1) Enter ID which teacher you want to edit" << endl;
	cout << "2) If you do not remember your ID, you can find by typing name and last name.\n But this search can be inaccurate" << endl;
	cout << "set option: ";
	int i;
	cin >> i;
	if (i == 1) {
		cout << "Enter ID" << endl;
		string ID;
		cin >> ID;
		Teacher object;
		object = dto.find_teacher(ID);
		if (object.return_identification_code() == "") {
			cout << "This teacher was not found." << endl;
		}
		else {
			string name, last_name;
			string age;
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
			case 1: cout << "Enter a new name "; cin >> name; object.set_name(name); break;
			case 2: cout << "Enter a new last name "; cin >> last_name; object.set_last_name(last_name); break;
			default:
				break;
			}
			if (choice == 3) {
				cout << "Enter a new age ";
				cin >> age;
				while (!is_number(age))
				{
					cout << "Try again" << endl;
					cin >> age;
				}
				object.set_age(stoi(age));
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
				dto.update_teacher_subject(object);
				return;
			}
			dto.update_teacher(object);
		}
	}
	if (i == 2) {
		cout << "Enter name and last name" << endl;
		string name, last_name;
		cin >> name >> last_name;
		Teacher object = dto.find_teacher(name, last_name);
		if (object.return_identification_code() == "") {
			cout << "This teacher was not found." << endl;
		}
		else {
			string name, last_name;
			string age;
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
			case 1: cout << "Enter a new name "; cin >> name; object.set_name(name); break;
			case 2: cout << "Enter a new last name "; cin >> last_name; object.set_last_name(last_name); break;
			default:
				break;
			}
			if (choice == 3) {
				cout << "Enter a new age ";
				cin >> age;
				while (!is_number(age))
				{
					cout << "Try again" << endl;
					cin >> age;
				}
				object.set_age(stoi(age));
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
				dto.update_teacher_subject(object);
				return;
			}
			dto.update_teacher(object);
		}
	}
	else {
		cout << "You entered incorrect data. Please try again" << endl;
	}
}

bool is_number(string number) {
	for (int i = 0; i < number.size(); i++) {
		if (int(number[i] - '0') >= 0 && int(number[i] - '0') <= 9) {
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

void delete_teacher() {
	system("cls");
	DTO_Teacher dto;
	cout << "You can delete teacher account. Please enter ID whose teacher you will be deleted: \t";
	string Id;
	cin >> Id;
	dto.delete_teach(Id);
}

void find_information_about_teacher() {
	system("cls");
	DTO_Teacher dto;
	cout << "1) Enter ID which teacher you want to find" << endl;
	cout << "2) If you do not remember your ID, you can find by typing name and last name.\n But this search can be inaccurate" << endl;
	cout << "set option: ";
	int i;
	cin >> i;
	if (i == 1) {
		cout << "Enter ID" << endl;
		string ID;
		cin >> ID;
		Teacher object;
		object = dto.find_teacher(ID);
		if (object.return_identification_code() == "") {
			cout << "This teacher was not found." << endl;
			return;
		}
		cout << "Name and last name :" << object.return_name() << " " << object.return_last_name() << endl;
		cout << "Age :" << object.return_age() << endl;
		cout << "Identification Code :" << object.return_identification_code() << endl;
		cout << "Subjects : " << endl;
		for (int j = 1; j <= object.number_of_subjects(); j++) {
			cout << j << ": " << object.subject_return(j) << endl;
		}
	}
	if (i == 2) {
		cout << "Enter name and last name" << endl;
		string name, last_name;
		cin >> name >> last_name;
		Teacher object = dto.find_teacher(name, last_name);
		if (object.return_identification_code() == "") {
			cout << "This teacher was not found." << endl;
			return;
		}
		cout << "Name and last name :" << object.return_name() << " " << object.return_last_name() << endl;
		cout << "Age :" << object.return_age() << endl;
		cout << "Identification Code :" << object.return_identification_code() << endl;
		cout << "Subjects : " << endl;
		for (int j = 1; j <= object.number_of_subjects(); j++) {
			cout << j << ": " << object.subject_return(j) << endl;
		}
	}
}