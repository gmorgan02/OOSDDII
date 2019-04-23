#include <iostream>
#include <fstream>
#include <string>
#include "DoctorMenu.h"


bool ValidateLogin(std::string enteredName, std::string enteredPassword)
{
	std::string storedName;
	std::string storedPassword;

	std::ifstream doctorsFile("Doctors.csv");

	std::getline(doctorsFile, storedName, ',');
	std::getline(doctorsFile, storedPassword, ',');

	storedName.erase(0, 1);

	return storedName == enteredName && storedPassword == enteredPassword;
}

void DoctorLogin()
{
	std::string enteredName;
	std::string enteredPassword;
	bool validLogin = false;
	
	while (!validLogin)
	{
		std::cout << "Please Enter your name(First Name *Space* Last Name)\n";
		std::cin.ignore();
		std::getline(std::cin, enteredName);
		std::cout << "Please Enter your Password\n";		
		std::cin >> enteredPassword;
		
		if (!ValidateLogin(enteredName, enteredPassword))
		{
			std::cout << "Invalid name or password please try again \n";
		}
		else
		{
			validLogin = true;
			DoctorMenu();
		}
	}
}


