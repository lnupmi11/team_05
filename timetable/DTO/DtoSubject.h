#pragma once
#include <direct.h>
#include <string>
#include <fstream>
#include "../Entity/Subject.h"

using namespace std;

class DTO_Subject
{
public:
	void create_new_subject(Subject object);
	void Save_new_subject(Subject object);
	void Save_new_subjects(vector<Subject> object);
	vector<string> all_subject_date();
};
