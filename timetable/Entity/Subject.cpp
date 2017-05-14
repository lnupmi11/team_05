#include "Subject.h"

	Subject::Subject()
	{
		this->course_title = "";
		this->id = "";
	}
        Subject::Subject(string course_title1,string id1) 
	{
		this->course_title = course_title1;
		this->id = id1;
	}
        Subject::Subject(const Subject &object)
	{
		this->course_title = object.course_title;
		this->id = object.id;
	}
	void Subject::set_course_title(string a)
	{
		course_title = a;
	}
	string Subject::get_course_title()
        {
		return course_title;
	}
        void Subject::set_id(string a)
	{
		id = a;
	}
	string Subject::get_id()
        {
		return id;
	}

