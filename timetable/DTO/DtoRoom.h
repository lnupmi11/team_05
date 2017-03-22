#pragma once
#include <fstream>
#include <string>
#include <direct.h>
#include "../Entity/Rooms.h"

using namespace std;

class DTO_Room {
public:
	void save_new_room_date(Room object,string day);
	bool is_room(string number);
	bool is_room_free(int number,string day,string room);
	bool is_room_free(string day,string room);
};