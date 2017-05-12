#pragma once
#ifndef _Save_
#define _Save_
#include "../Entity/Subject.h"
#include <direct.h>
#include <fstream>
class DTO_Subject
{
public:
	void create_new_subject(Subject object);
	void Save_new_subject(Subject object);
	void Save_new_subjects(vector<Subject> object);
	vector<string> all_subject_date();
};
#endif
