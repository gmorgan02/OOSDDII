#include "Patient.h"
#include <fstream>


Patient::Patient()
{
	Name = "";
	Password = "";
	Address = "";
	Ailment = "";
	PhoneNumber = "0";
}


Patient::~Patient()
{
}

void Patient::SetName(std::string namePass)
{
	Name = namePass;
}

std::string Patient::GetName()
{
	return  Name;
}

void Patient::SetPassword(std::string passwordPass)
{
	Password = passwordPass;
}

std::string Patient::GetPassword()
{
	return  Password;
}

void Patient::SetAddress(std::string addressPass)
{
	Address = addressPass;
}

std::string Patient::GetAddress()
{
	return Address;
}

void Patient::SetAilment(std::string ailmentPass)
{
	Ailment = ailmentPass;
}

std::string Patient::GetAilment()
{
	return Ailment;
}

void Patient::SetPhoneNumber(std::string phoneNumberPass)
{
	PhoneNumber = phoneNumberPass;
}

std::string Patient::GetPhoneNumber()
{
	return PhoneNumber;
}

std::vector<std::string> Patient::GetPatients()
{
	std::vector<std::string>Patients;
	std::string storedPatients;

	std::ifstream patientsFile("Patients.csv");

	while (std::getline(patientsFile, storedPatients, ','))
	{
		Patients.push_back(storedPatients);
	}

	return Patients;
}

void Patient::CreatePatient(std::string namePass, std::string passwordPass, std::string phoneNumberPass, std::string addressPass, std::string ailmentPass)
{
	std::ofstream patientFile("Patients.csv", std::ios::app);
	patientFile << namePass << "," << passwordPass << "," << phoneNumberPass << "," << addressPass << "," << ailmentPass << "\n";
	patientFile.close();
}
