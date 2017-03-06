#include "Entity\Teacher.h"
#include "BL\BL.h"

int main() {
	vector<Teacher> mass;
	mass = create_new_teacher(mass);
	print_all_teachers_date();
	system("pause");
	return 0;
}