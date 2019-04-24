
#include <iostream>
#include "Patient.h"
#include "Surgery.h"
#include "Doctor.h"
#include "BookingList.h"

void SelectDoctor(Patient* objLoggedInPatient, Surgery* objSelectedSurgery)
{
	std::string enteredName;
	bool validChoice = false;

	std::string stringCheck = "\n";
	Doctor objProcessDoctor;
	Doctor* objSelectedDoctor = new Doctor;
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

	while (!validChoice)
	{
		std::cout << "Please enter the name of the Doctor you wish to book an appointment with\n";
		for (int i = 0; i < processedDoctorsInfo.size(); i++)
		{
				//TODO only output names from the list
				std::cout << processedDoctorsInfo[i];		
		}
		std::cin.clear();	
		std::getline(std::cin, enteredName);					

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

				objSelectedDoctor->SetName(namePass);
				objSelectedDoctor->SetPassword(passwordPass);
				objSelectedDoctor->SetField(fieldPass);
				objSelectedDoctor->SetSurgeryName(surgeryNamePass);
				validChoice = true;
			}
		}

		if (!validChoice)
		{
			std::cout << "Incorrect Doctor Name entered please try again\n";
		}
		else
		{
			BookingList(objSelectedSurgery, objLoggedInPatient, objSelectedDoctor);
		}			
	}
}

