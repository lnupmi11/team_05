#include "Entity\Teacher.h"
#include "BL\BL.h"

int main() {
	while (true) {
		int i;
		cout << "1-create; 2-print_all; 3-edit; 4-delete; 5-exit" << "\nset option: ";
		cin >> i;
		switch (i)
		{
			case 1: create_new_teacher(); break;
			case 2: print_all_teachers_date(); break;
			case 3: replacemant_date_teacher(); break;
			case 4: delete_teacher(); break;
			default:
				break;
		}
		if (i == 5) {
			break;
		}
	}
	system("pause");
	return 0;
}