#include "Groups.h"

Group::Group() {
	id = "";
	name = "";
}
Group::Group(string n, string i) {
	id = i;
	name = n;
}
Group::Group(const Group& obj) {
	id = obj.id;
	name = obj.name;
}
void Group::set_name(string n) {
	name = n;
}
string Group::get_name() {
	return name;
}
void Group::set_id(string i) {
	id = i;
}
string Group::get_id() {
	return id;
}
