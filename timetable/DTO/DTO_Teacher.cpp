#include "DtoTeacher.h"

void DTO_Teacher::Save_new_teacher(Teacher object) {

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

vector<Teacher> DTO_Teacher::all_teachers_date() {
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


Teacher DTO_Teacher::find_teacher(string ID) {
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
				string identification_code;
				if (input_date.is_open()) {
					for (int i = 1; i <= 4; i++) {
						getline(input_date, line);
						switch (i)
						{
							case 1: object.set_name(line); break;
							case 2: object.set_last_name(line); break;
							case 3: object.set_age(stoi(line)); break;
							case 4: object.set_identification_code(line); break;
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
						object.add_subject(line);
					}
					input_subject.close();
				}
			}
			if (folder_name.empty()) {
				break;
			}
		}
		in.close();
	}
	return object;
}

void DTO_Teacher::update_teacher_subject(Teacher object) {
	ofstream out;
	string way = "Teachers\\" + object.return_identification_code() + "\\subjects.txt";
	out.open(way, ios_base::trunc);
	for (int i = 1; i <= object.number_of_subjects(); i++) {
		out << object.subject_return(i) << endl;
	}
	out.close();
}

void DTO_Teacher::update_teacher(Teacher object) {
	ofstream out;
	string way = "Teachers\\" + object.return_identification_code() + "\\date.txt";
	out.open(way, ios_base::trunc);
	out << object.return_name() << endl;
	out << object.return_last_name() << endl;
	out << object.return_age() << endl;
	out << object.return_identification_code() << endl;
	out.close();
}

bool DTO_Teacher::check_ID(string ID) {
	ifstream in("Teachers\\teachers.txt");
	string id;
	while (!in.eof())
	{
		getline(in, id);
		if (id == "") {
			return false;
		}
		if (id == ID) {
			return true;
		}
	}
}

void DTO_Teacher::delete_teach(string ID) {
	ifstream in("Teachers\\teachers.txt");
	string way = "Teachers\\" + ID;
	string first = way + "\\date.txt";
	remove(first.c_str());
	first = way + "\\subjects.txt";
	remove(first.c_str());
	vector<string> id;
	_rmdir(way.c_str());
	while (!in.eof())
	{
		string line;
		getline(in, line);
		if (line == "") {
			break;
		}
		if (line == ID) {
			continue;
		}
		id.push_back(line);
	}
	in.close();
	ofstream update("Teachers\\teachers.txt", ios_base::trunc);
	for (int i = 0; i < id.size(); i++) {
		update << id[i] << endl;
	}
}

Teacher DTO_Teacher::find_teacher(string name, string last_name) {
	ifstream in("Teachers\\teachers.txt");
	Teacher object;
	string folder_name;
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, folder_name);
			if (folder_name.empty()) {
				break;
			}
			string way = "Teachers\\" + folder_name + "\\date.txt";
			string _name;
			string _last_name;
			ifstream input_date(way);
			getline(input_date, _name);
			getline(input_date, _last_name);
			string line;
			if (name == _name && last_name == _last_name) {
				object.set_name(name);
				object.set_last_name(last_name);
				getline(input_date, line);
				object.set_age(stoi(line));
				getline(input_date, line);
				object.set_identification_code(line);
				way = "Teachers\\" + folder_name + "\\subjects.txt";
				ifstream input_subject(way);
				while (!input_subject.eof()) {
					getline(input_subject, line);
					if (line.empty()) {
						break;
					}
					object.add_subject(line);
				}
				input_subject.close();
				return object;
			}
		}
	}
	return object;
}