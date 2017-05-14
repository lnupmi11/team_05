#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "..\DTO\DtoTeacher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace TeacherTests
{
	TEST_CLASS(TeacherUnitTest)
	{

	public:

		TEST_METHOD(CreateTeacher)
		{
			Teacher object("Jon","Jon2","Math",23,"321524363647547");

			DTO_Teacher save;

			bool test;

			try
			{
				save.Save_new_teacher(object);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			test = save.check_ID("321524363647547");
			Assert::AreEqual(true, test);
			save.delete_teach("321524363647547");
		}

		TEST_METHOD(FindTeacher)
		{
			Teacher object("Jon", "Jon2", "Math", 23, "321524363647547");

			DTO_Teacher save;

			try
			{
				save.Save_new_teacher(object);
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			Teacher object1;
			Teacher object2;

			object1 = save.find_teacher("321524363647547");
			object2 = save.find_teacher("Jon", "Jon2");

			int age1;
			int age2;

			age1 = object1.return_age();
			age2 = object2.return_age();

			Assert::AreEqual(age1, age2);
			save.delete_teach("321524363647547");
		}
	};
}