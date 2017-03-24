#include "DtoRoom.h"

void DTO_Room::save_new_room_date(Room object) {
	ofstream out;
	string way = "Rooms\\" + object.return_number() + "\\date.txt";
	out.open(way, ios_base::trunc);
	out << object.return_number() << endl;
	out << object.return_capacity() << endl;
	out << object.return_type() << endl;
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

void DTO_Room::create_new_room(Room object) {
	ofstream out;
	string way = "Rooms\\" + object.return_number();
	_mkdir(way.c_str());
	way += "\\date.txt";
	out.open(way, ios_base::app);
	out << object.return_number() << endl;
	out << object.return_capacity() << endl;
	out << object.return_type() << endl;
	out.close();
	out.open("Rooms\\Rooms.txt", ios_base::app);
	out << object.return_number() << endl;
	out.close();
}

Room DTO_Room::find_date_room(string number) {
	ifstream in;
	string way = "Rooms\\" + number + "\\date.txt";
	in.open(way);
	string line;
	Room object;
	getline(in, line);
	object.set_number(line);
	getline(in, line);
	object.set_capacity(stoi(line));
	getline(in, line);
	object.set_type(line);
	in.close();
	return object;
}

vector<Room> DTO_Room::all_room_date() {
	vector<Room> objects;
	ifstream rooms;
	ifstream in;
	string line, room_number;
	rooms.open("Rooms\\Rooms.txt");
	while (true)
	{
		getline(rooms, room_number);
		if (room_number == "") {
			break;
		}
		string way = "Rooms\\" + room_number + "\\date.txt";
		in.open(way);
		Room object;
		getline(in, line);
		object.set_number(line);
		getline(in, line);
		object.set_capacity(stoi(line));
		getline(in, line);
		object.set_type(line);
		in.close();
		objects.push_back(object);
	}
	return objects;
}

void DTO_Room::delete_room(string number) {
	string way = "Rooms\\" + number;
	string first = way + "\\date.txt";
	remove(first.c_str());
	_rmdir(way.c_str());
	ifstream rooms;
	vector<string> number_rooms;
	string line;
	rooms.open("Rooms\\Rooms.txt");
	while (true)
	{
		getline(rooms, line);
		if (line == "") {
			break;
		}
		if (line == number) {
			continue;
		}
		number_rooms.push_back(line);
	}
	rooms.close();
	ofstream out;
	way = "Rooms\\Rooms.txt";
	out.open(way, ios_base::trunc);
	for (int i = 0; i < number_rooms.size(); i++) {
		out << number_rooms[i] << endl;
	}
	out.close();
}