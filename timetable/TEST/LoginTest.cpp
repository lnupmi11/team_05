#include "CppUnitTest.h"
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "..\DTO\DtoLogin.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

namespace LoginTests
{
	TEST_CLASS(UserUnitTest)
	{

	public:

		TEST_METHOD(CreateUser)
		{

			Login object;

			bool test;


			try
			{
				object.save_new_user("38947uf9ehg");
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}

			test = object.check_login("38947uf9ehg");

			Assert::AreEqual(true, test);


			try
			{
				object.delete_user("38947uf9ehg");
			}
			catch (exception& ex)
			{
				Assert::Fail();
			}
		}
	};
}