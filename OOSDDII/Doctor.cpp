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

void Doctor::GetDoctor(std::string namePass, std::string passwordPass, std::string fieldPass, std::string surgeryNamePass)
{
	std::string Name = namePass, Password = passwordPass, Field = fieldPass, SurgeryName = surgeryNamePass;
}

void Doctor::CreateDoctor(std::string namePass, std::string passwordPass, std::string fieldPass, std::string surgeryNamePass)
{	
	std::ofstream doctorFile("Doctors.csv", std::ios::app);
	doctorFile << namePass << "," << passwordPass << "," << fieldPass << "," << surgeryNamePass << "\n";
	doctorFile.close();
}

