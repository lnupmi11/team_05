#include "DtoGroups.h"

void DTO_Group::Save_new_group(Group object)
{
	string folder_name = "Group";
	_mkdir(folder_name.c_str());
	ofstream out_group;
	string grouprec = folder_name + "\\groups.txt";
	out_group.open(grouprec, ios_base::trunc);
	out_group << object.get_name() << endl;
	out_group.close();
	cout << "This group created" << endl;
}
void DTO_Group::Save_new_group(vector<Group> object)
{
	string folder_name = "Group";
	_mkdir(folder_name.c_str());
	ofstream out_group;
	string grouprec = folder_name + "\\groups.txt";
	out_group.open(grouprec, ios_base::trunc);
	for (int i = 1; i <= object.size(); i++)
	{
		out_group << object[i - 1].get_name() << endl;
	}
	out_group.close();
	cout << "This groups created" << endl;
}
vector<string> DTO_Group::all_group_date()
{
	vector<string> group;
	string way = "Group\\groups.txt";
	string line;
	ifstream input_group(way);
	while (!input_group.eof()) {
		getline(input_group, line);
		if (line.empty()) {
			break;
		}
		group.push_back(line);
	}
	input_group.close();
	return group;
}
