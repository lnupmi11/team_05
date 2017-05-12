#include "DtoSubject.h"
void DTO_Subject:: save_new_subject_date(Subject object)
{
	ofstream out;
	string way="Subjects\\"+object.get_course_title() +"date.txt";
	out.open(way, ios_base::trunc);
	out<<object.get_course_title()<<endl;
	out.close();
}
void DTO_Subject:: create_new_subject(Subject object)
{
	ofstream out;
	string folder_name = "Subjects\\" + object.get_course_title() ;
	_mkdir(folder_name.c_str());
	string way=folder_name+"\\date.txt";
	out.open(way, ios_base::app);
	out<<object.get_course_title()<<endl;
	out.close();
	out.open("Subjects\\Subjects.txt", ios_base::app);
	out<<object.get_course_title()<<endl;
	out.close();
}
bool DTO_Subject:: is_subject(string name)
{
	ifstream in("Subjects\\Subjects.txt");
	string line;
	while(!line.eof())
	{
		getline(in, line);
		if (line == name) 
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
Subject DTO_Subject:: find_date_subject(string name)
{
	ifstream in;
	string way="Subjects\\"+name+"\\date.txt";
	in.open(way);
	string line;
	Subject object;
	getline(in,line);
	object.set_course_title(name);
	in.close();
	return object;
}
vector<Subject> DTO_Subject::all_subject_date()
{
	vector<Subject> objects;
	ifstream subjects;
	ifstream in;
	string line,subject_name;
	subjects.open("Subjects\\Subjects.txt");
	while (true) 
	{
		getline(subjects, subject_name);
		if (subject_name=="") {
			break;
		}
		string way="Subjects\\"+subject_name+"\\date.txt";
		in.open(way);
		Subject object;
		getline(in,line);
		object.set_course_title(name);
		in.close();
		objects.push_back(object);
	}
	return objects;
}

