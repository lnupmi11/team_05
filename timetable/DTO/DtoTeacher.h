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

#endif