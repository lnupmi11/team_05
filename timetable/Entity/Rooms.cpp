#include "Rooms.h"

	void Room::set_number(string a)
	{
        number=a;
	}
	string Room::get_number(){
		return number;
	}
	void Room::save_room() {
		string room_number = this->number;
		ofstream out;
		string date = "Rooms\\" + room_number + ".txt";
		out.open(date, ios_base::trunc);
		out.close();
}

	Room::~Room()
	{

	}
