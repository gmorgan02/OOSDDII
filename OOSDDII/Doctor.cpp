#include "Doctor.h"
#include <fstream>
#include <vector>

Doctor::Doctor()
{
	Name = "";
	Password = "";
	Field = "";
	SurgeryName = "";
}


Doctor::~Doctor()
{
}

void Doctor::SetName(std::string namePass)
{
	Name = namePass;
}

std::string Doctor::GetName()
{
	return Name;
}

void Doctor::SetPassword(std::string passwordPass)
{
	Password = passwordPass;
}

std::string Doctor::GetPassword()
{
	return Password;
}

void Doctor::SetField(std::string fieldPass)
{
	Field = fieldPass;
}

std::string Doctor::GetField()
{
	return Field;
}

void Doctor::SetSurgeryName(std::string surgeryNamePass)
{
	SurgeryName = surgeryNamePass;
}

std::string Doctor::GetSurgeryName()
{
	return SurgeryName;
}

std::vector<std::string> Doctor::GetDoctors()
{
	std::vector<std::string>Doctors;
	std::string storedDoctors;

	std::ifstream doctorsFile("Doctors.csv");

	while (std::getline(doctorsFile, storedDoctors, ','))
	{
		Doctors.push_back(storedDoctors);
	}

	return Doctors;
}

void Doctor::CreateDoctor(std::string namePass, std::string passwordPass, std::string fieldPass, std::string surgeryNamePass)
{	
	std::ofstream doctorFile("Doctors.csv", std::ios::app);
	doctorFile << namePass << "," << passwordPass << "," << fieldPass << "," << surgeryNamePass << "\n";
	doctorFile.close();
}

