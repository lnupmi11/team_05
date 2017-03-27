#pragma once
#ifndef _Save_
#define _Save_
#include "../Entity/Groups.h"
#include <direct.h>
#include <fstream>
class DTO_Group
{
public:
	void Save_new_group(Group object);
	void Save_new_group(vector<Group> object);
	vector<string> all_group_date();
};
#endif
