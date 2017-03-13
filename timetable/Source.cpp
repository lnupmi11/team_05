#include "Entity\Teacher.h"
#include "BL\BL.h"

int main() {
	while (true) {
		int i;
		cout << "1-create; 2-print_all; 3-edit;" << "\nset option: ";
		cin >> i;
		if (i == 1) {
			create_new_teacher(); 
		}
		else if (i == 2) {
			print_all_teachers_date();
		}
		else if (i == 3) {
			replacemant_date_teacher();
		}
		else {
			break;
		}
	}
	system("pause");
	return 0;
}