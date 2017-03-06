#include "SaveDate.h"

void Save_new_teacher(string name, string last_name, vector<string> subject, int age, string identification_code) {
	string folder_name = "Teachers\\" + identification_code;
	_mkdir(folder_name.c_str());
	ofstream out;
	string date = folder_name + "\\date.txt";
	out.open(date, ios_base::trunc);
	out << name << endl << last_name << endl;
	out << age << endl;
	out << identification_code << endl;
	out.close();
	ofstream out_subject;
	string subject_record = folder_name + "\\subjects.txt";
	out_subject.open(subject_record, ios_base::trunc);
	for (int i = 1; i <= subject.size(); i++) {
		out_subject << subject[i-1] << endl;
	}
	out_subject.close();
	cout << "This teacher created" << endl;
	ofstream out_teacher;
	out_teacher.open("Teachers\\teachers.txt", ios_base::app);
	out_teacher << identification_code << endl;
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
