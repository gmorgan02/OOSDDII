#include "Doctor.h"
#include <fstream>

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

void Doctor::AddDoctor(std::string namePass, std::string passwordPass, std::string fieldPass, std::string surgeryName)
{
	std::string Name = namePass, Password = passwordPass, Field = fieldPass, SurgeryName = surgeryName;
}

void Doctor::CreateDoctor()
{
	std::ofstream doctorFile("Doctors.csv", std::ios::app);
	doctorFile << Name << "," << Password << "," << Field << "," << SurgeryName << "\n";
	doctorFile.close();
}

