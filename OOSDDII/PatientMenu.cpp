#include <iostream>
#include "Patient.h"
#include "SelectSurgery.h"

void PatientMenu(Patient* objLoggedInPatient)
{
	int option;
	bool validChoice = false;
	std::cout << "Welcome to the Patient Menu " << objLoggedInPatient->GetName() << "!\n";



	while (!validChoice)
	{
		std::cout << "Please Select from one of the following:\n";
		std::cout << "1. View/Create Bookings\n2. Exit Program\n";
		std::cin >> option;
		switch (option)
		{
		case 1:
			validChoice = true;
			//TODO add bookings
			SelectSurgery(objLoggedInPatient);
			break;
		case 2:
		//	validChoice = true;
			//GetCreatePatient(objLoggedInPatient);
			break;
		default:
			std::cout << "Please select a valid option\n\n";
			break;
		}
	}
}
