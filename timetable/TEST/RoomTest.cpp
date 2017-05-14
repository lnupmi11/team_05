#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "DTO\DtoRoom.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace RoomTests
{
	TEST_CLASS(RoomTest)
	{

	public:

		TEST_METHOD(CreateRoom)
		{
			Room object("213", "Historical study", 130);

			DTO_Room save;

			bool test;

			try
			{
				save.create_new_room(object);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			test = save.is_room("213");
			Assert::AreEqual(true, test);
			save.delete_room("213");
		}


		TEST_METHOD(EditDate)
		{
			Room object("459", "Historical study", 78);

			DTO_Room save;

			int test1;
			string test2;
			bool test3;

			try
			{
				save.create_new_room(object);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			object.set_type("Historical");
			object.set_capacity(5);

			save.save_new_room_date(object);

			object = save.find_date_room("459");

			test1 = object.return_capacity();
			test2 = object.return_type();

			Assert::AreEqual(5, test1);
			Assert::AreEqual("Historical", test2);

			save.delete_room("459");
		}

		TEST_METHOD(IsRoom)
		{
			
			bool test;

			DTO_Room object;

			test = object.is_room("459");

			Assert::AreEqual(false, test);
		}
	};
}