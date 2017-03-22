#include "DtoRoom.h"

void DTO_Room::save_new_room_date(Room object,string day) {
	ofstream out;
	string folder_name = "Rooms\\" + object.return_number();
	DTO_Room check;
	if (!check.is_room(object.return_number())) {
		_mkdir(folder_name.c_str());
	}
	out.open("Rooms\\Rooms.txt", ios_base::app);
	out << object.return_number();
	out.close();
	out.open(folder_name + "\\" + day + ".txt", ios_base::app);
	out << object.return_number_subject() << endl;
	out << object.return_groups() << endl;
	out.close();
}

bool DTO_Room::is_room(string number) {
	ifstream in("Rooms\\Rooms.txt");
	string line;
	while (!in.eof())
	{
		getline(in, line);
		if (line == number) {
			return true;
		}
		if (line == "") {
			return false;
		}
	}
	return false;
}

bool DTO_Room::is_room_free(int number,string day,string room) {
	string way;
	way = "Rooms\\" + room + "\\" + day + ".txt";
	ifstream in(way);
	string line;
	while (!in.eof())
	{
		getline(in, line);
		if (line == "") {
			return true;
		}
		if (line == to_string(number)) {
			return false;
		}
	}
	return false;
}

bool DTO_Room::is_room_free(string day, string room) {
	string way;
	way = "Rooms\\" + room + "\\" + day + ".txt";
	ifstream in(way);
	string line;
	int count = 0;
	while (!in.eof())
	{
		getline(in, line);
		if (line == "") {
			return true;
		}
		if (line == "1" || line == "2" || line == "3" || line == "4" || line == "5") {
			count++;
		}
		if (count == 5) {
			return false;
		}
	}
	return false;
}