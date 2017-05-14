#include "DtoGroups.h"

void DTO_Group::save_new_group_date(Group object)
{
	ofstream out;
	string way = "group\\" + object.get_id() + "\\date.txt";
	out.open(way, ios_base::trunc);
	out << object.get_name() << endl;
	out << object.get_id() << endl;
	out.close();
}
void DTO_Group::create_new_group(Group object)
{
	ofstream out;
	string folder_name = "group\\" + object.get_id();
	_mkdir(folder_name.c_str());
	string way = folder_name + "\\date.txt";
	out.open(way, ios_base::app);
	out << object.get_name() << endl;
	out << object.get_id() << endl;
	out.close();
	out.open("group\\group.txt", ios_base::app);
	out << object.get_id() << endl;
	out.close();
}
bool DTO_Group::is_group(string id)
{
	ifstream in("group\\group.txt");
	string line;
	while (!in.eof())  //
	{
		getline(in, line);
		if (line == id)
		{
			return true;
		}
		if (line == "")
		{
			return false;
		}
	}
	return false;
}
Group DTO_Group::find_date_group(string id)
{
	ifstream in;
	string way = "group\\" + id + "\\date.txt";
	in.open(way);
	string line;
	Group obj;
	getline(in, line);
	obj.name(line);
	getline(in, line);
	obj.set_id(line);
	in.close();
	return obj;
}
vector<Group> DTO_Group::all_group_date()
{
	vector<Group> objects;
	ifstream groups;
	ifstream in;
	string line, group_id;
	groups.open("group\\group.txt");
	while (true)
	{
		getline(groups, group_id);
		if (group_id == "") {
			break;
		}
		string way = "group\\" + group_id + "\\date.txt";
		in.open(way);
		Group object;
		getline(in, line);
		object.set_name(line);
		getline(in, line);
		object.set_id(line);
		in.close();
		objects.push_back(object);
	}
	return objects;
}
void DTO_Group::delete_group(string id)
{
	string way = "group\\" + id;
	string first = way + "\\date.txt";
	remove(first.c_str());
	_rmdir(way.c_str());
	ifstream groups;
	vector<string>id_groups;
	string line;
	groups.open("group\\group.txt");
	while (true)
	{
		getline(groups, line);
		if (line == "") {
			break;
		}
		if (line == id) {
			continue;
		}
		id_groups.push_back(line);
	}
	groups.close();
	ofstream out;
	way = "group\\group.txt";
	out.open(way, ios_base::trunc);
	for (int i = 0; i < id_groups.size(); i++) {
		out << id_groups[i] << endl;
	}
	out.close();
}
