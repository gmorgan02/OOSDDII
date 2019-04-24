#include <iostream>
#include "DoctorLogin.h"
#include "PatientLogin.h"
#include "CreatePatient.h"

void Menu()
{
	int option;
	bool validChoice = false;
	std::cout << "Welcome to the program!\n";
	


	while (!validChoice)
	{
		std::cout << "Please Select from one of the following:\n";
		std::cout << "1. Patient Login\n2. Doctor Login\n3. Add new Patient\n4. Exit Program\n";
		std::cin >> option;
		switch (option)
		{
		case 1:
			validChoice = true;
			PatientLogin();
			break;
		case 2:
			validChoice = true;
			DoctorLogin();
			break;
		case 3:
			validChoice = true;
			CreatePatient();
			break;
		case 4:
			validChoice = true;
			break;
		default:
			std::cout << "Please select a valid option\n\n";
			break;
		}
	}	
}
