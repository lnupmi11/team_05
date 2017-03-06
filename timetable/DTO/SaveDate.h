#pragma once
#ifndef _Save_
#define _Save_
#include "../Entity/Teacher.h"
#include <direct.h>
#include <fstream>

void Save_new_teacher(string name, string last_name, vector<string> subject, int age, string identification_code);

vector<Teacher> all_teachers_date();

void update_teacher();

#endif