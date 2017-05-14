#include "DtoSubject.h"
void DTO_Subject:: save_new_subject_date(Subject object)
{
	ofstream out;
	string way="Subjects\\"+object.get_id() +"\\date.txt";
	out.open(way, ios_base::trunc);
	out<<object.get_course_title()<<endl;
	out<<object.get_id()<<endl;
	out.close();
}
void DTO_Subject:: create_new_subject(Subject object)
{
	ofstream out;
	string folder_name = "Subjects\\" + object.get_id() ;
	_mkdir(folder_name.c_str());
	string way=folder_name+"\\date.txt";
	out.open(way, ios_base::app);
	out<<object.get_course_title()<<endl;
	out<<object.get_id()<<endl;
	out.close();
	out.open("Subjects\\Subjects.txt", ios_base::app);
	out<<object.get_id()<<endl;
	out.close();
}
bool DTO_Subject:: is_subject(string id)
{
	ifstream in("Subjects\\Subjects.txt");
	string line;
	while(!in.eof())
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
}
Subject DTO_Subject:: find_date_subject(string id)
{
	ifstream in;
	string way="Subjects\\"+id+"\\date.txt";
	in.open(way);
	string line;
	Subject object;
	getline(in,line);
	object.set_course_title(line);
	getline(in,line);
	object.set_id(line);
	in.close();
	return object;
}
vector<Subject> DTO_Subject::all_subject_date()
{
	vector<Subject> objects;
	ifstream subjects;
	ifstream in;
	string line,subject_id;
	subjects.open("Subjects\\Subjects.txt");
	while (true) 
	{
		getline(subjects, subject_id);
		if (subject_id=="") {
			break;
		}
		string way="Subjects\\"+subject_id+"\\date.txt";
		in.open(way);
		Subject object;
		getline(in,line);
		object.set_course_title(line);
		getline(in,line);
		object.set_id(line);
		in.close();
		objects.push_back(object);
	}
	return objects;
}
void DTO_Subject:: delete_subject(string id)
{
	string way = "Subjects\\" + id;
	string first = way + "\\date.txt";
	remove(first.c_str());
	_rmdir(way.c_str());
	ifstream subjects;
	vector<string>id_subjects;
	string line;
	subjects.open("Subjects\\Subjects.txt");
	while(true)
	{
		getline(subjects,line);
		if (line == "") {
			break;
		}
		if (line == id) {
			continue;
		}
		id_subjects.push_back(line);
	}
	subjects.close();
	ofstream out;
	way="Subjects\\Subjects.txt";
	out.open(way, ios_base::trunc);
	for (int i = 0; i < id_subjects.size(); i++) {
		out << id_subjects[i] << endl;
	}
	out.close();
}
