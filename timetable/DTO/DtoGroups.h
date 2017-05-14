#pragma once
#ifndef _DTOGROUPS_H_
#define _DTOGROUPS_H_
#include "../Entity/Groups.h"
#include <direct.h>
#include <fstream>
#include <string>
using namespace std;

class DTO_Group
{
public:
	void save_new_group_date(Group obj);
	void create_new_group(Group obj);
	bool is_group(string id);
	Group find_date_group(string id);
	vector<Group> all_group_date();
	void delete_group(string id);
};

#endif
