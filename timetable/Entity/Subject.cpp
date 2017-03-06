#include "Subject.h"

	Subject::Subject()
	{
		this->course_title = "";
	}
        Subject::Subject(string course_title1) 
	{
		this->course_title = course_title1;
	}
        Subject::Subject(const Subject &object)
	{
		this->course_title = object.course_title;
	}
	void Subject::set_course_title(string a)
	{
		course_title = a;
	}
	string Subject::get_course_title()
        {
		return course_title;
	}

