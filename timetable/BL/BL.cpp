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
		cout << "1. Teacher" << endl << "2. Groups" << endl << "3. Rooms" << endl << "4. Subject" << endl << "5. Exit" << endl;
		int i;
		cin >> i;
		switch (i)
		{
			case 1: teacher_menu(); break;
			case 3: room_menu(); break;
			case 4: subject_menu();break;
			case 5: return;
			default:
				break;
		}
	}
}

void teacher_menu() {
	while (true) {
		int i;
		cout << "1. Create" << endl << "2. Print all" << endl << "3. Information about teacher" << endl << "4. Edit" << endl << "5. Delete" << endl << "6. Exit" << "\nset option: ";
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
	cout << "How many items learned this teacher? ";
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
	cout << "2) Enter name and last name which teacher you want to edit" << endl;
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
	cout << "2) Enter name and last name which teacher you want to find" << endl;
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

void create_new_room() {
	system("cls");
	cout << "Enter room number ";
	string number;
	cin >> number;
	DTO_Room dto_room;
	while (dto_room.is_room(number)) {
		cout << "This room already created" << endl;
		cout << "To return to the previous menu enter 1 " << endl;
		cout << "To enter again 2" << endl << "Set option" << endl;
		int i;
		cin >> i;
		if (i == 1) {
			return;
		}
		else {
			cin >> number;
		}
	}
	cout << "Enter capacity this room ";
	int capacity;
	cin >> capacity;
	cout << "Enter type this room ";
	string type;
	cin >> type;
	Room room(number, type, capacity);
	dto_room.create_new_room(room);
	cout << endl << "Success" << endl << endl;
}

void delete_room() {
	system("cls");
	cout << "Enter room which you want to delete" << endl;
	string number;
	cin >> number;
	DTO_Room dto_room;
	dto_room.delete_room(number);
}

void replacemant_date_room() {
	system("cls");
	cout << "Enter room which you want to edit" << endl;
	string number;
	cin >> number;
	DTO_Room dto_room;
	while (!dto_room.is_room(number))
	{
		cout << "Enter correct number " << endl;
		cin >> number;
	}
	Room room;
	room.set_number(number);
	string line;
	cout << "You can edit: " << endl;
	cout << "1. Capacity" << endl;
	cout << "2. Type" << endl;
	int i = 0;
	cin >> i;
	switch (i)
	{
	case 1: cin >> line; room.set_capacity(stoi(line)); break;
	case 2: cin>>line; room.set_type(line); break;
	default:
		break;
	}
	dto_room.save_new_room_date(room);
}

void print_all_room_date() {
	system("cls");
	vector<Room> objects;
	DTO_Room dto_room;
	objects = dto_room.all_room_date();
	for (int i = 0; i < objects.size(); i++) {
		cout << "Number : " << objects[i].return_number() << endl;
		cout << "Capacity : " << objects[i].return_capacity() << endl;
		cout << "Type : " << objects[i].return_type() << endl;
		cout << endl;
	}
}

void find_information_about_room() {
	system("cls");
	Room object;
	string num;
	cout << "Enter room which you want find" << endl;
	cin >> num;
	DTO_Room dto_room;
	object = dto_room.find_date_room(num);
	cout << "Number : " << object.return_number() << endl;
	cout << "Capacity : " << object.return_capacity() << endl;
	cout << "Type : " << object.return_type() << endl;
}

void room_menu() {
	while (true) {
		int i;
		cout << "1. Create new room " << endl << "2. Edit date room" << endl << "3. Delete room" << endl << "4. Print all" << endl << "5. Print one room" << endl << "6. Exit" << endl;
		cout << "Set option ";
		cin >> i;
		switch (i)
		{
			case 1: create_new_room(); break;
			case 2: replacemant_date_room(); break;
			case 3: delete_room(); break;
			case 4: print_all_room_date(); break;
			case 5: find_information_about_room(); break;
			default:
				break;
		}
		if (i == 6) {
			break;
		}
	}
}
void subject_menu()
{
	while (true) 
	{
		int i;
		cout << "1. Create new subject " << endl << "2. Edit date subject" << endl << "3. Delete subject" << endl << "4. Print all subjects" << endl << "5. Print one subject" << endl << "6. Exit" << endl;
		cout << "Set option ";
		cin >> i;
		switch (i)
		{
			case 1: create_new_subject(); break;
			case 2: replacemant_date_subject(); break;
			case 3: delete_subject(); break;
			case 4: print_all_subjects_date(); break;
			case 5: find_information_about_subject(); break;
			default:
				break;
		}
		if (i == 6) {
			break;
		}
	}
}
void find_information_about_subject() 
{
	system("cls");
	Subject object;
	string id;
	cout << "Enter the ID of the subject which you want find" << endl;
	cin >> id;
	DTO_Subject dto_subject;
	while (!dto_subject.is_subject(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	object = dto_subject.find_date_subject(id);
	cout << "Name : " << object.get_course_title() << endl;
	cout << "ID : " << object.get_id() << endl;
}
void print_all_subjects_date() 
{
	system("cls");
	vector<Subject> objects;
	DTO_Subject dto_subject;
	objects = dto_subject.all_subject_date();
	for (int i = 0; i < objects.size(); i++) {
		cout << "Name : " << objects[i].get_course_title() << endl;
		cout << "ID : " << objects[i].get_id() << endl;
		cout << endl;
	}
}
void replacemant_date_subject() 
{
	system("cls");
	cout << "Enter the ID of the subject which you want to edit" << endl;
	string id;
	cin >> id;
	DTO_Subject dto_subject;
	while (!dto_subject.is_subject(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	Subject subject;
	subject.set_id(id);
	string line;
	cout<<"Please edit the name of the subject"<<endl;
	cin>>line;
	subject.set_course_title(line);
	dto_subject.save_new_subject_date(subject);
	cout << endl << "Success" << endl << endl;
}
void delete_subject() 
{
	system("cls");
	cout << "Enter the ID of the subject which you want to delete" << endl;
	string id;
	cin >> id;
	DTO_Subject dto_subject;
	while (!dto_subject.is_subject(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	dto_subject.delete_subject(id);
	cout << endl << "Success" << endl << endl;
}
void create_new_subject() 
{
	system("cls");
	cout << "Enter subject ID: ";
	string id;
	cin >> id;
	DTO_Subject dto_subject;
	while (dto_subject.is_subject(id)) {
		cout << "This subject already created" << endl;
		cout << "To return to the previous menu enter 1 " << endl;
		cout << "To enter again 2" << endl << "Set option" << endl;
		int i;
		cin >> i;
		if (i == 1) {
			return;
		}
		else {
			cin >> id;
		}
	}
	cout<<"Enter the name of subject: ";
	string name;
	cin>>name;
	Subject subject(name,id);
	dto_subject.create_new_subject(subject);
	cout << endl << "Success" << endl << endl;
}
