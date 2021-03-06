#pragma once
#ifndef _BL_
#define _BL_
#include "../DTO/DtoTeacher.h"
#include "../DTO/DtoLogin.h"
#include "../DTO/DtoRoom.h"
#include "../DTO/DtoSubject.h"
#include "../DTO/DtoGroups.h"
#include "../DTO/DtoStudent.h"
#include <Windows.h>
#include <conio.h>

extern bool makeChanges;

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

void print_all_room_date();

void find_information_about_room();

void room_menu();

void subject_menu();

void print_all_subjects_date();

void create_new_subject();

void replacemant_date_subject();

void delete_subject();

void find_information_about_subject();

void group_menu();

void create_new_group();

void print_all_groups_date();

void replacemant_date_group();

void find_information_about_group();

void delete_group();

void group_timetable();

void edit_timetable();

void create_timetable();

void timetable_menu();

void timetable_group();

void student_menu();

void create_new_student();

void print_all_students_date();

void replacemant_date_student();

void find_information_about_student();

void delete_student();

#endif
