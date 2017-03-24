#pragma once
#ifndef _BL_
#define _BL_
#include "../DTO/DtoTeacher.h"
#include "../DTO/DtoLogin.h"
#include "../DTO/DtoRoom.h"

void teacher_menu();

void print_all_teachers_date();

void create_new_teacher();

void replacemant_date_teacher();

bool is_number(string number);

void delete_teacher();

bool start_login();

void Start();

void find_information_about_teacher();

void create_new_room();

void delete_room();

void replacemant_date_room();

#endif