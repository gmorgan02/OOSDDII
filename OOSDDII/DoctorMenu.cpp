
#include <iostream>
#include "CreateDoctor.h"

void DoctorMenu()
{
	int option;
	bool validChoice = false;
	std::cout << "Welcome to the program!\n";



	while (!validChoice)
	{
		std::cout << "Please Select from one of the following:\n";
		std::cout << "1. View Bookings\n2. Add new Doctor\n3. Add new Surgery\n4. Exit Program\n";
		std::cin >> option;
		switch (option)
		{
		case 1:
			validChoice = true;
			std::cout << "Option 1\n";
			break;
		case 2:
			validChoice = true;
			GetCreateDoctor();
			break;
		case 3:
			validChoice = true;
			GetCreateSurgery();
			break;
		default:
			std::cout << "Please select a valid option\n\n";
			break;
		}
	}
}
