#include <iostream>
#include <fstream>
#include <string>
#include "DoctorMenu.h"
#include <vector>
#include "Doctor.h"


bool ValidateLogin(std::string enteredName, std::string enteredPassword)
{
	std::vector<std::string>doctors;
	std::string storedDoctors;
	std::string stringCheck = "\n";

	std::ifstream doctorsFile("Doctors.csv");
	
	while (std::getline(doctorsFile, storedDoctors, ','))
	{		
		if (storedDoctors.find(stringCheck) != std::string::npos)
		{
			storedDoctors.erase(0, 1);
		}		
		doctors.push_back(storedDoctors);
	}

	
	for (int i = 0; i < doctors.size(); i++)
	{
		if (doctors[i] == enteredName)
		{
			if (doctors[i + 1] == enteredPassword)
			{					
				return true;
			}
		}
	}
	return false;
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

			std::string stringCheck = "\n";
			Doctor objProcessDoctor;
			Doctor* objLoggedInDoctor = new Doctor;
			std::vector<std::string> doctorsInfo = objProcessDoctor.GetDoctors();
			std::vector<std::string> processedDoctorsInfo;

			for (std::vector<std::string>::value_type doctorinfo : doctorsInfo)
			{
				if (doctorinfo.find(stringCheck) != std::string::npos)
				{
					doctorinfo.erase(0, 1);
				}
				processedDoctorsInfo.push_back(doctorinfo);
			}

			for (int i = 0; i < processedDoctorsInfo.size(); i++)
			{
				if (processedDoctorsInfo[i] == enteredName)
				{

					std::string namePass = processedDoctorsInfo[i];
					std::string passwordPass = processedDoctorsInfo[i + 1];
					std::string fieldPass = processedDoctorsInfo[i + 2];
					//if (Doctors[i + 3].find(stringCheck))
					//{
					//	//TODO remove \n off the end of the Surgery Name
					//	processedDoctorsInfo[i + 3].erase(0, 1);
					//}	
					std::string surgeryNamePass = processedDoctorsInfo[i + 3];

					objLoggedInDoctor->SetName(namePass);
					objLoggedInDoctor->SetPassword(passwordPass);
					objLoggedInDoctor->SetField(fieldPass);
					objLoggedInDoctor->SetSurgeryName(surgeryNamePass);
				}
			}
			DoctorMenu(objLoggedInDoctor);
		}
	}
}




