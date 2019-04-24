
#include <iostream>
#include <string>
#include "Surgery.h"
#include "DoctorMenu.h"

void CreateSurgery(Doctor* objLoggedInDoctor)
{
	Surgery objSurgery;
	std::string namePass, locationPass;

	std::cout << "Please Enter the Surgery Name \n";
	std::cin.ignore();
	std::getline(std::cin, namePass);

	std::cout << "Please Enter the Surgery Location (1st Line of Address) \n";
	std::cin.clear();
	std::getline(std::cin, locationPass);

	objSurgery.CreateSurgery(namePass, locationPass);

	std::cout << "Surgery Created!\n";
	DoctorMenu(objLoggedInDoctor);
}
