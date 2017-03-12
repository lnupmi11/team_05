#include "DtoTeacher.h"

void Save_new_teacher(Teacher object) {

	string folder_name = "Teachers\\" + object.return_identification_code();
	_mkdir(folder_name.c_str());
	ofstream out;
	string date = folder_name + "\\date.txt";
	out.open(date, ios_base::trunc);
	out << object.return_name() << endl << object.return_last_name() << endl;
	out << object.return_age() << endl;
	out << object.return_identification_code() << endl;
	out.close();
	ofstream out_subject;
	string subject_record = folder_name + "\\subjects.txt";
	out_subject.open(subject_record, ios_base::trunc);
	for (int i = 1; i <= object.number_of_subjects(); i++) {
		out_subject << object.subject_return(i) << endl;
	}
	out_subject.close();
	cout << "This teacher created" << endl;
	ofstream out_teacher;
	out_teacher.open("Teachers\\teachers.txt", ios_base::app);
	out_teacher << object.return_identification_code() << endl;
	out_teacher.close();
}

vector<Teacher> all_teachers_date() {
	ifstream in("Teachers\\teachers.txt");
	vector<Teacher> objects;
	string folder_name;
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, folder_name);
			if (folder_name.empty()) {
				break;
			}
			string way = "Teachers\\" + folder_name + "\\date.txt";
			ifstream input_date(way);
			string line;
			string name;
			string last_name;
			vector<string> subject;
			int age;
			string identification_code;
			if (input_date.is_open()) {
				for (int i = 1; i <= 4; i++) {
					getline(input_date, line);
					switch (i)
					{
					case 1: name = line; break;
					case 2: last_name = line; break;
					case 3: age = stoi(line); break;
					case 4: identification_code = line; break;
					default:
						break;
					}
				}
				input_date.close();
			}
			way = "Teachers\\" + folder_name + "\\subjects.txt";
			ifstream input_subject(way);
			while (!input_subject.eof()) {
				getline(input_subject, line);
				if (line.empty()) {
					break;
				}
				subject.push_back(line);
			}
			input_subject.close();
			objects.emplace_back(name, last_name, subject, age, identification_code);
		}
		in.close();
	}
	return objects;
}


Teacher find_teacher(string ID) {
	ifstream in("Teachers\\teachers.txt");
	Teacher object;
	string folder_name;
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, folder_name);
			if (folder_name == ID) {
				string way = "Teachers\\" + folder_name + "\\date.txt";
				ifstream input_date(way);
				string line;
				string name;
				string last_name;
				vector<string> subject;
				int age;
				string identification_code;
				if (input_date.is_open()) {
					for (int i = 1; i <= 4; i++) {
						getline(input_date, line);
						switch (i)
						{
						case 1: name = line; break;
						case 2: last_name = line; break;
						case 3: age = stoi(line); break;
						case 4: identification_code = line; break;
						default:
							break;
						}
					}
					input_date.close();
					way = "Teachers\\" + folder_name + "\\subjects.txt";
					ifstream input_subject(way);
					while (!input_subject.eof()) {
						getline(input_subject, line);
						if (line.empty()) {
							break;
						}
						subject.push_back(line);
					}
					input_subject.close();
				}
				object(name, last_name, subject, age, identification_code);
			}
			if (folder_name.empty()) {
				break;
			}
		}
		in.close();
	}
	return object;
}

void update_teacher_subject(Teacher object) {
	ofstream out;
	string way = "Teachers\\" + object.return_identification_code() + "\\subjects.txt";
	out.open(way, ios_base::trunc);
	for (int i = 1; i <= object.number_of_subjects(); i++) {
		out << object.subject_return(i) << endl;
	}
	out.close();
}

void update_teacher(Teacher object) {
	ofstream out;
	string way = "Teachers\\" + object.return_identification_code() + "\\date.txt";
	out.open(way, ios_base::trunc);
	out << object.return_name() << endl;
	out << object.return_last_name() << endl;
	out << object.return_age() << endl;
	out << object.return_identification_code() << endl;
	out.close();
}