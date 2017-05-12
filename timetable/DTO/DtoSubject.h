#pragma once
#include <direct.h>
#include <string>
#include <fstream>
#include "../Entity/Subject.h"

using namespace std;

class DTO_Subject
{
public:
	void save_new_subject_date(Subject object);
	void create_new_subject(Subject object);
	bool is_subject(string name);
	Subject find_date_subject(string name);
	vector<Subject> all_subject_date();
	void delete_subject(string name);
};
