#pragma once
#ifndef _Save_
#define _Save_
#include "../Entity/Teacher.h"
#include <direct.h>
#include <fstream>

void Save_new_teacher(Teacher object);

vector<Teacher> all_teachers_date();

void update_teacher(Teacher object);

Teacher find_teacher(string ID);

void update_teacher_subject(Teacher object);

bool check_ID(string ID);

void delete_teach(string ID);

Teacher find_teacher(string name, string last_name);

#endif