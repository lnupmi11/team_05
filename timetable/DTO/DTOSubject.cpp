#include "DtoSubject.h"
void DTO_Subject:: save_new_subject_date(Subject object)
{
	ofstream out;
	string way="Subjects\\date.txt";
	out.open(way, ios_base::trunc);
	out<<object.get_course_title()<<endl;
	out.close();
}
void DTO_Subject:: Save_new_subject(Subject object) 
{
	string folder_name = "Subject" ;
	_mkdir(folder_name.c_str());
	ofstream out_subject;
	string subjectrecord = folder_name +"\\subjects.txt";
	out_subject.open(subjectrecord, ios_base::trunc);
	out_subject << object.get_course_title() << endl;
	out_subject.close();
	cout << "This subject created" << endl;
}
void DTO_Subject:: Save_new_subjects(vector <Subject> object) 
{
	string folder_name = "Subject" ;
	_mkdir(folder_name.c_str());
	ofstream out_subject;
	string subjectrecord = folder_name +"\\subjects.txt";
	out_subject.open(subjectrecord, ios_base::trunc);
	for (int i = 1; i <= object.size(); i++) 
	{
		out_subject << object[i-1].get_course_title() << endl;
	}
	out_subject.close();
	cout << "This subjects created" << endl;
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

