#include "Patient.h"
#include <iostream>
#include "Menu.h"
#include <string>

void CreatePatient()
{	
	Patient objPatient;
	std::string namePass, passwordPass, addressPass, ailmentPass, phoneNumberPass;

	std::cout << "Please Enter the Patient's Name \n";
	std::cin.ignore();
	std::getline(std::cin, namePass);

	std::cout << "Please Enter the Patient's Password \n";
	std::cin >> passwordPass;


	//declare variables for phoneNumber check
	std::string phoneNumber;
	bool isPhoneNumber = false;
	static const std::string allowedNumbers = "0123456789";
	int correctCharCount = 0;
	//while loop that will keep asking for the phone number until the checks are passed
	while (!isPhoneNumber)
	{
		std::cout << "Please Enter the Patient's Phone Number \n";
		std::cin >> phoneNumber;
		//checks the number of digits entered 
		if (phoneNumber.size() == 11)
		{
			//foreach loop checking each character entered matches one of the characters in the allowedNumbers variable 
			for (auto numberChar = phoneNumber.begin();
				numberChar != phoneNumber.end(); ++numberChar)
			{
				if (allowedNumbers.end() == std::find(
					allowedNumbers.begin(), allowedNumbers.end(), *numberChar))
				{
					//Check failed on the character in the loops on the phone number variable failed on any characters not in allowedNumbers example: letters or special characters				
				}
				else
				{
					//iterates through to the next digit
					correctCharCount++;
				}
			}
		}
		//checks that the loop has checked all digits else will restart the loop
		if (correctCharCount == 11)
		{
			//exits the while loop when entered
			isPhoneNumber = true;
			std::cout << "Phone number is in correct format\n";
		}
		else
		{
			std::cout << "Please enter the phone number in the correct format\n";
		}
	}

	phoneNumberPass = phoneNumber;

	std::cout << "Please Enter the Patient's Address \n";
	std::cin.ignore();
	std::getline(std::cin, addressPass);

	std::cout << "Please Enter the Patient's Ailment \n";
	std::cin.clear();
	std::getline(std::cin, ailmentPass);

	objPatient.CreatePatient(namePass, passwordPass, phoneNumberPass, addressPass, ailmentPass);

	std::cout << "Patient Created!\n";
	Menu();
}
