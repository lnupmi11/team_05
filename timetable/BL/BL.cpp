#include "BL.h"

bool makeChanges;

bool start_login() {
	Login object;
	string login, password;
	cin >> login;
	HANDLE hSTDin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hSTDin, &mode);
	SetConsoleMode(hSTDin, mode & (~ENABLE_ECHO_INPUT));
	cin >> password;
	if (object.check_login(login, password)) {
		if (login != "admin") {
			makeChanges = false;
		}
		else
		{
			makeChanges = true;
		}
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
		cout << "Error. Please try again. Click the button to continue" << endl;
		count_try++;
		_getch();
		system("cls");
		if (count_try == 5) {
			cout << "Limit attempts exhausted. Please try again later";
			return;
		}
	}
	while (true)
	{
		system("cls");
		cout << "Available menu items :" << endl;
		cout << "1. Teacher" << endl << "2. Groups" << endl << "3. Rooms" << endl << "4. Subject" << endl <<"5. Student"<<endl << "6. Timetable" << endl << "7. Exit" << endl;
		string i;
		cin >> i;
		if (is_number(i))
		{
			switch (stoi(i))
			{
			case 1: teacher_menu(); break;
			case 2: group_menu(); break;
			case 3: room_menu(); break;
			case 4: subject_menu(); break;
			case 5: student_menu(); break;
			case 6: timetable_menu(); break;
			case 7: return;
			default:
				break;
			}
		}
		else
		{
			cout << "Input date is incorrect. Try again" << endl;
		}
	}
}

void teacher_menu() {
	system("cls");
	if (makeChanges == true) {
		while (true) {
			string i;
			cout << "1. Create" << endl << "2. Print all" << endl << "3. Information about teacher" << endl << "4. Edit" << endl << "5. Delete" << endl << "6. Exit" << "\nset option: ";
			cin >> i;
			if (!is_number(i))
			{
				cout << "Enter correct input date" << endl;
			}
			else
			{
				switch (stoi(i))
				{
				case 1: create_new_teacher(); break;
				case 2: print_all_teachers_date(); break;
				case 3: find_information_about_teacher(); break;
				case 4: replacemant_date_teacher(); break;
				case 5: delete_teacher(); break;
				default:
					break;
				}
				if (stoi(i) == 6) {
					break;
				}
			}
		}
	}
	else {
		while (true) {
			string i;
			cout << "1. Print all" << endl << "2. Information about teacher" << endl << "3. Exit" << "\nset option: ";
			cin >> i;
			if (!is_number(i))
			{
				cout << "Enter correct input date" << endl;
			}
			else
			{
				switch (stoi(i))
				{
				case 1: print_all_teachers_date(); break;
				case 2: find_information_about_teacher(); break;
				default:
					break;
				}
				if (stoi(i) == 3) {
					break;
				}
			}
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
	cin.ignore();
	for (int i = 0; i < coll; i++) {
		cout << "Enter subject " << i + 1 << "  ";
		string subj;
		getline(cin, subj);
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
					cin.ignore();
					getline(cin, new_subject);
					object.add_subject(new_subject);
				}
				if (choice == 2) {
					string delete_subject;
					cout << "Enter the subject you want to delete ";
					cin.ignore();
					getline(cin, delete_subject);
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
					cin.ignore();
					getline(cin, new_subject);
					object.add_subject(new_subject);
				}
				if (choice == 2) {
					string delete_subject;
					cout << "Enter the subject you want to delete ";
					cin.ignore();
					getline(cin, delete_subject);
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
	Login log;
	log.delete_user(Id);
}

void find_information_about_teacher() {
	system("cls");
	DTO_Teacher dto;
	cout << "1) Enter ID which teacher you want to find" << endl;
	cout << "2) Enter name and last name which teacher you want to find" << endl;
	cout << "set option: ";
	string i;
	cin >> i;
	if (is_number(i))
	{
		if (stoi(i) == 1) {
			cout << "Enter ID" << endl;
			string ID;
			cin >> ID;
			Teacher object;
			object = dto.find_teacher(ID);
			if (object.return_identification_code() == "") {
				cout << "This teacher was not found." << endl;
				return;
			}
			cout << endl;
			cout << "Name and last name :" << object.return_name() << " " << object.return_last_name() << endl;
			cout << "Age :" << object.return_age() << endl;
			cout << "Identification Code :" << object.return_identification_code() << endl;
			cout << "Subjects : " << endl;
			for (int j = 1; j <= object.number_of_subjects(); j++) {
				cout << j << ": " << object.subject_return(j) << endl;
			}
			cout << endl;
		}
		if (stoi(i) == 2) {
			cout << "Enter name and last name" << endl;
			string name, last_name;
			cin >> name >> last_name;
			Teacher object = dto.find_teacher(name, last_name);
			if (object.return_identification_code() == "") {
				cout << "This teacher was not found." << endl;
				return;
			}
			cout << endl;
			cout << "Name and last name :" << object.return_name() << " " << object.return_last_name() << endl;
			cout << "Age :" << object.return_age() << endl;
			cout << "Identification Code :" << object.return_identification_code() << endl;
			cout << "Subjects : " << endl;
			for (int j = 1; j <= object.number_of_subjects(); j++) {
				cout << j << ": " << object.subject_return(j) << endl;
			}
			cout << endl;
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
	cout << "Enter type this room " << endl;
	string type;
	cin.ignore();
	getline(cin, type);
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
	case 2: cin.ignore(); getline(cin, line); room.set_type(line); break;
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
	cout << endl;
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
	cout << endl;
	cout << "Number : " << object.return_number() << endl;
	cout << "Capacity : " << object.return_capacity() << endl;
	cout << "Type : " << object.return_type() << endl;
	cout << endl;
}

void room_menu() {
	system("cls");
	if (makeChanges == true) {
		while (true) {
			string i;
			cout << "1. Create new room " << endl << "2. Edit date room" << endl << "3. Delete room" << endl << "4. Print all" << endl << "5. Print one room" << endl << "6. Exit" << endl;
			cout << "Set option ";
			cin >> i;
			if (!is_number(i))
			{
				cout << "Enter correct input date" << endl;
			}
			else
			{
				switch (stoi(i))
				{
				case 1: create_new_room(); break;
				case 2: replacemant_date_room(); break;
				case 3: delete_room(); break;
				case 4: print_all_room_date(); break;
				case 5: find_information_about_room(); break;
				default:
					break;
				}
				if (stoi(i) == 6) {
					break;
				}
			}
		}
	}
	else {
		while (true) {
			string i;
			cout << "1. Print all" << endl << "2. Print one room" << endl << "3. Exit" << endl;
			cout << "Set option ";
			cin >> i;
			if (!is_number(i))
			{
				cout << "Enter correct input date" << endl;
			}
			else
			{
				switch (stoi(i))
				{
				case 1: print_all_room_date(); break;
				case 2: find_information_about_room(); break;
				default:
					break;
				}
				if (stoi(i) == 3) {
					break;
				}
			}
		}
	}
}
void subject_menu()
{
	system("cls");
	if (makeChanges == true) {
		while (true) {
			int i;
			cout << "1. Create subject" << endl << "2. Edit subject" << endl << "3. Delete subject" << endl << "4. Print all subjects" << endl << "5. Information about subject" << endl << "6. Exit" << "\nset option: ";
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
	else {
		while (true) {
			int i;
			cout << "1. Print all subjects" << endl << "2. Information about subject" << endl << "3. Exit" << "\nset option: ";
			cin >> i;
			switch (i)
			{
			case 1: print_all_subjects_date(); break;
			case 2: find_information_about_subject(); break;
			default:
				break;
			}
			if (i == 3) {
				break;
			}
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
void group_menu()
{
	if (makeChanges == true) {
		while (true)
		{
			int i;
			cout << "1. Create new group " << endl << "2. Edit date group" << endl << "3. Delete group" << endl << "4. Print all groups" << endl << "5. Print one group" << endl << "6. See timetable group" << endl << "7. Exit" << endl;
			cout << "Set option ";
			cin >> i;
			switch (i)
			{
			case 1: create_new_group(); break;
			case 2: replacemant_date_group(); break;
			case 3: delete_group(); break;
			case 4: print_all_groups_date(); break;
			case 5: find_information_about_group(); break;
			case 6: timetable_group(); break;
			default:
				break;
			}
			if (i == 7) {
				break;
			}

		}
	}
	else {
		while (true) {
			int i;
			cout << "1. Print all groups" << endl << "2. Print one group" << endl << "3. See timetable group" << endl << "4. Exit" << "\nset option: ";
			cin >> i;
			switch (i)
			{
			case 1: print_all_groups_date(); break;
			case 2: find_information_about_group(); break;
			case 3: timetable_group(); break;
			default:
				break;
			}
			if (i == 4) {
				break;
			}
		}
	}
}
void create_new_group() 
{
	system("cls");
	cout << "Enter GroupID: ";
	string id;
	cin >> id;
	DTO_Group dto_group;
	while (dto_group.is_group(id)) {
		cout << "This group is already created" << endl;
		cout << "To return to the previous menu enter 1 " << endl;
		cout << "To try to create again enter 2" << endl << "Set option" << endl;
		int i;
		cin >> i;
		if (i == 1) {
			return;
		}
		else {
			cin >> id;
		}
	}
	cout<<"Enter the name of group: ";
	string name;
	cin>>name;
	Group group(name,id);
	dto_group.create_new_group(group);
	cout << endl << "Successfully created" << endl << endl;
}
void print_all_groups_date() 
{
	system("cls");
	vector<Group> objects;
	DTO_Group dto_group;
	objects = dto_group.all_group_date();
	for (int i = 0; i < objects.size(); i++) {
		cout << "Name of group: " << objects[i].get_name() << endl;
		cout << "GroupID : " << objects[i].get_id() << endl;
		cout << endl;
	}
}
void replacemant_date_group() 
{
	system("cls");
	cout << "Enter the ID of the group which you want to edit" << endl;
	string id;
	cin >> id;
	DTO_Group dto_group;
	while (!dto_group.is_group(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	Group group;
	group.set_id(id);
	string line;
	cout<<"Edit the name of the group"<<endl;
	cin>>line;
	group.set_name(line);
	dto_group.save_new_group_date(group);
	cout << endl << "Successfully replaced" << endl << endl;
}
void find_information_about_group() 
{
	system("cls");
	Group object;
	string id;
	cout << "Enter the ID of the group which you want find" << endl;
	cin >> id;
	DTO_Group dto_group;
	while (!dto_group.is_group(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	object = dto_group.find_date_group(id);
	cout << "Name of group: " << object.get_name() << endl;
	cout << "GroupID : " << object.get_id() << endl;
}
void delete_group() 
{
	system("cls");
	cout << "Enter the ID of the group which you want to delete" << endl;
	string id;
	cin >> id;
	DTO_Group dto_group;
	while (!dto_group.is_group(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	dto_group.delete_group(id);
	cout << endl << "Successfully deleted" << endl << endl;
}


void timetable_menu()
{
	system("cls");
	if (makeChanges)
	{
		while (true)
		{
			cout << "1. Create a timetable for the group" << endl << "2. Edit a timetable for the group" << endl << "3. Exit" << endl;
			cout << "Set option ";
			string i;
			cin >> i;
			if (is_number(i))
			{
				switch (stoi(i))
				{
				case 1: create_timetable(); break;
				case 2: edit_timetable(); break;
				default:
					break;
				}
				if (stoi(i) == 3)
				{
					break;
				}
			}
			else
			{
				cout << "Enter correct input data" << endl << endl;
			}
		}
	}
	else
	{
		cout << "You do not have access" << endl;
		_getch();
	}
}

void create_timetable()
{
	cout << "Sorry this function does not work" << endl << endl;
}

void edit_timetable()
{
	cout << "Sorry this function does not work" << endl << endl;
}

void timetable_group()
{
	cout << "Enter id group" << endl;
	string id;
	cin >> id;
	DTO_Group object;
	if (object.is_group(id))
	{
		group_timetable();
	}
	else
	{
		cout << "This group not found" << endl << endl;
	}
}


void group_timetable()
{
	cout << "Timetable was not created" << endl << endl;
}


void student_menu()
{
	system("cls");
	if (makeChanges == true) {
		while (true)
		{
			int i;
			cout << "1. Create new student " << endl << "2. Edit date student" << endl << "3. Delete student" << endl << "4. Print all students" << endl << "5. Print one student" << endl << "6. Exit" << endl;
			cout << "Set option ";
			cin >> i;
			switch (i)
			{
			case 1: create_new_student(); break;
			case 2: replacemant_date_student(); break;
			case 3: delete_student(); break;
			case 4: print_all_students_date(); break;
			case 5: find_information_about_student(); break;
			default:
				break;
			}
			if (i == 6) {
				break;
			}

		}
	}
	else {
		while (true) {
			int i;
			cout << "1. Print all students" << endl << "2. Print one student" << endl << "3. Exit" << "\nset option: ";
			cin >> i;
			switch (i)
			{
			case 1: print_all_students_date(); break;
			case 2: find_information_about_student(); break;
			default:
				break;
			}
			if (i == 3) {
				break;
			}
		}
	}
}
void create_new_student() 
{
	system("cls");
	cout << "Enter StudentID: ";
	string id;
	cin >> id;
	DTO_Student dto_student;
	while (dto_student.is_student(id)) {
		cout << "This student is already created" << endl;
		cout << "To return to the previous menu enter 1 " << endl;
		cout << "To try to create again enter 2" << endl << "Set option" << endl;
		int i;
		cin >> i;
		if (i == 1) {
			return;
		}
		else {
			cin >> id;
		}
	}
	cout<<"Enter the full name (name and surname) of student: ";
	string full_name;
	cin>>full_name;
	Student student(full_name,id);
	dto_student.create_new_student(student);
	cout << endl << "Successfully created" << endl << endl;
}
void print_all_students_date() 
{
	system("cls");
	vector<Student> objects;
	DTO_Student dto_student;
	objects = dto_student.all_student_date();
	for (int i = 0; i < objects.size(); i++) {
		cout << "Surname and Name " << objects[i].get_full_name() << endl;
		cout << "Student's ID : " << objects[i].get_id() << endl;
		cout << endl;
	}
}
void replacemant_date_student() 
{
	system("cls");
	cout << "Enter the ID of the student which you want to edit" << endl;
	string id;
	cin >> id;
	DTO_Student dto_student;
	while (!dto_student.is_student(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	Student student;
	student.set_id(id);
	string line;
	cout<<"Edit the full name of the student"<<endl;
	cin>>line;
	student.set_full_name(line);
	dto_student.save_new_student_date(student);
	cout << endl << "Successfully replaced" << endl << endl;
}
void find_information_about_student() 
{
	system("cls");
	Student object;
	string id;
	cout << "Enter the ID of the Student which you want to find" << endl;
	cin >> id;
	DTO_Student dto_student;
	while (!dto_student.is_student(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	object = dto_student.find_date_student(id);
	cout << "Name and Surname of Student: " << object.get_full_name() << endl;
	cout << "Student's ID : " << object.get_id() << endl;
}
void delete_student() 
{
	system("cls");
	cout << "Enter the ID of the Student which you want to delete" << endl;
	string id;
	cin >> id;
	DTO_Student dto_student;
	while (!dto_student.is_student(id))
	{
		cout << "Enter correct id" << endl;
		cin >> id;
	}
	dto_student.delete_student(id);
	cout << endl << "Successfully deleted" << endl << endl;
}
