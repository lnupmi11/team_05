#include "Groups.h"

Group::Group() {
	name = "";
	number = 0;
}
Group::Group(string n, int numb) {
	name = n;
	number = numb;
}
Group::Group(const Group& obj) {
	name = obj.name;
	number = obj.number;
}
void Group::set_name(string n) {
	name = n;
}
string Group::get_name() {
	return name;
}
void Group::set_number(int n) {
	number = n;
}
int Group::get_number() {
	return number;
}
