#include "DtoLogin.h"

bool Login::check_login(string login,string password) {
	ifstream in("Users.txt");
	string cheker;
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, cheker);
			if (cheker == login && cheker == password) {
				in.close();
				return true;
			}
			if (cheker == "") {
				in.close();
				return false;
			}
		}
	}
	in.close();
	return false;
}

void Login::save_new_user(string login) {
	ofstream out;
	out.open("Users.txt", ios_base::app);
	out << login << endl;
	out.close();
}