#pragma once
#include <fstream>
#include <string>
#include <direct.h>
#include "../Entity/Rooms.h"

using namespace std;

class DTO_Room {
public:
	void create_new_room(Room object);
	void save_new_room_date(Room object);
	bool is_room(string number);
	Room find_date_room(string number);
	vector<Room> all_room_date();
	void delete_room(string number);
};