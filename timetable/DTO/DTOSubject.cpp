#include "DtoSubject.h"
void DTO_Subject:: save_new_subject_date(Subject object)
{
	ofstream out;
	string way="Subjects\\"+object.get_course_title() +"date.txt";
	out.open(way, ios_base::trunc);
	out<<object.get_course_title()<<endl;
	out.close();
}
void DTO_Subject:: create_new_subject(Subject object);
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
vector<string> DTO_Subject::all_subject_date()
{
	vector<string> subject;
	string way = "Subject\\subjects.txt";
	string line;
	ifstream input_subject(way);
	while (!input_subject.eof()) {
		getline(input_subject, line);
		if (line.empty()) {
			break;
		}
		subject.push_back(line);
	}
	input_subject.close();
	return subject;
}

