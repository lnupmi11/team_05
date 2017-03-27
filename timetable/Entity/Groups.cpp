#include "Groups.h"

Group::Group() {
	name = "";
}
Group::Group(string n) {
	name = n;
}
Group::Group(const Group& obj) {
	name = obj.name;
}
void Group::set_name(string n) {
	name = n;
}
string Group::get_name() {
	return name;
}
