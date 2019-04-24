#include <iostream>
#include <fstream>
#include <string>
#include "PatientMenu.h"
#include <vector>
#include "Patient.h"
#include "PatientMenu.h"


bool ValidatePatientLogin(std::string enteredName, std::string enteredPassword)
{
	std::vector<std::string>patients;
	std::string storedPatients;
	std::string stringCheck = "\n";

	std::ifstream patientsFile("Patients.csv");

	while (std::getline(patientsFile, storedPatients, ','))
	{
		if (storedPatients.find(stringCheck) != std::string::npos)
		{
			//TODO remove end of ailment instead of beginning
			storedPatients.erase(0, 1);
		}
		patients.push_back(storedPatients);
	}


	for (int i = 0; i < patients.size(); i++)
	{
		if (patients[i] == enteredName)
		{
			if (patients[i + 1] == enteredPassword)
			{
				return true;
			}
		}
	}
	return false;
}

void PatientLogin()
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

		if (!ValidatePatientLogin(enteredName, enteredPassword))
		{
			std::cout << "Invalid name or password please try again \n";
		}
		else
		{
			validLogin = true;

			std::string stringCheck = "\n";
			Patient objProcessPatient;
			Patient* objLoggedInPatient = new Patient;
			std::vector<std::string> patientsInfo = objProcessPatient.GetPatients();
			std::vector<std::string> processedPatientInfo;

			for (std::vector<std::string>::value_type patientInfo : patientsInfo)
			{
				if (patientInfo.find(stringCheck) != std::string::npos)
				{
					patientInfo.erase(0, 1);
				}
				processedPatientInfo.push_back(patientInfo);
			}

			for (int i = 0; i < processedPatientInfo.size(); i++)
			{
				if (processedPatientInfo[i] == enteredName)
				{

					std::string namePass = processedPatientInfo[i];
					std::string passwordPass = processedPatientInfo[i + 1];
					std::string phoneNumberPass = processedPatientInfo[i + 2];					
					//if (Patients[i + 3].find(stringCheck))
					//{
					//	//TODO remove \n off the end of the Address
					//	processedPatientsInfo[i + 3].erase(0, 1);
					//}	
					std::string ailmentPass = processedPatientInfo[i + 3];
					std::string addressPass = processedPatientInfo[i + 4];

					objLoggedInPatient->SetName(namePass);
					objLoggedInPatient->SetPassword(passwordPass);
					objLoggedInPatient->SetAddress(addressPass);
					objLoggedInPatient->SetAilment(ailmentPass);
					objLoggedInPatient->SetPhoneNumber(phoneNumberPass);
				}
			}
			PatientMenu(objLoggedInPatient);
		}
	}
}