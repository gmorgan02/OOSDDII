#include "Doctor.h"
#include <iostream>
#include "DoctorMenu.h"

void CreateDoctor(Doctor* objLoggedInDoctor)
{
	Doctor objDoctor;
	std::string namePass, passwordPass, fieldPass, surgeryNamePass;

	std::cout << "Please Enter the Doctors Name \n";
	std::cin.ignore();
	std::getline(std::cin, namePass);

	std::cout << "Please Enter the Doctors Password \n";
	std::cin >> passwordPass;

	std::cout << "Please Enter the Doctors Specialty \n";
	std::cin.ignore();
	std::getline(std::cin, fieldPass);

	std::cout << "Please Enter the Doctors Surgery Name \n";
	std::cin.clear();
	std::getline(std::cin, surgeryNamePass);

	objDoctor.CreateDoctor(namePass, passwordPass, fieldPass, surgeryNamePass);

	std::cout << "Doctor Created!\n";
	DoctorMenu(objLoggedInDoctor);
}
