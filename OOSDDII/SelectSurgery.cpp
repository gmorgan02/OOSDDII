
#include <string>
#include <iostream>
#include "Surgery.h"
#include "SelectSurgery.h"
#include "Patient.h"
#include "SelectDoctor.h"

void SelectSurgery(Patient* objLoggedInPatient)
{
	std::string enteredName;
	std::string enteredPassword;
	bool validchoice = false;

	std::string stringCheck = "\n";
	Surgery objProcessSurgery;
	Surgery* objSelectedSurgery = new Surgery;
	std::vector<std::string> surgeriesInfo = objProcessSurgery.GetSurgeries();
	std::vector<std::string> processedSurgeryInfo;

	for (std::vector<std::string>::value_type surgeryInfo : surgeriesInfo)
	{
		if (surgeryInfo.find(stringCheck) != std::string::npos)
		{
			surgeryInfo.erase(0, 1);
		}
		processedSurgeryInfo.push_back(surgeryInfo);
	}

	while (!validchoice)
	{				
		std::cout << objLoggedInPatient->GetName() << ", Please Select your Surgery (Enter Name)\n";
		for (int i = 0; i < processedSurgeryInfo.size(); i++)
		{
			//TODO only output names from list 
			std::cout << processedSurgeryInfo[i];
		}		
		std::cin.ignore();
		std::getline(std::cin, enteredName);

		for (int i = 0; i < processedSurgeryInfo.size(); i++)
		{
			if (processedSurgeryInfo[i] == enteredName)
			{

				std::string namePass = processedSurgeryInfo[i];
				//TODO remove \n off the end of the Location Not the beginning
				std::string locationPass = processedSurgeryInfo[i + 1];	

				objSelectedSurgery->SetName(namePass);
				objSelectedSurgery->SetLocation(locationPass);
				validchoice = true;
			}
		}
		
		if (!validchoice)
		{
			std::cout << "Incorrect Surgery Name entered please try again\n";
		}
		else
		{
			SelectDoctor(objLoggedInPatient, objSelectedSurgery);
		}
	}
}

