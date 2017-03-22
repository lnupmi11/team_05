#pragma once
#include <fstream>
#include <string>

using namespace std;

class Login {
public:
	bool check_login(string login,string password);
	void save_new_user(string login);
};