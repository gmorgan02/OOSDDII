#include <iostream>
#include "sqlite3.h"

bool ValidateLogin(std::string, std::string)
{
	sqlite3 *db;
	sqlite3_open("OOSDDII.db", &db);
	
	
}

void DoctorLogin()
{
	std::string enteredName;
	std::string enteredPassword;
	bool validLogin = false;
	



	while (!validLogin)
	{
		std::cout << "Please Enter your name(First Name *Space* Last Name)\n";
		std::cin >> enteredName;
		std::cout << "Please Enter your Password\n";
		std::cin >> enteredPassword;
		ValidateLogin(enteredName, enteredPassword);
	}
}


