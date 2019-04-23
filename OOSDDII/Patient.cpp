#include "Patient.h"
#include <fstream>


Patient::Patient()
{
}


Patient::~Patient()
{
}

void Patient::GetPatient(std::string namePass, std::string passwordPass, int phoneNumberPass, std::string addressPass, std::string ailmentPass)
{
	std::string Name = namePass, Password = passwordPass, Address = addressPass, Ailment = ailmentPass;
	int PhoneNumber = phoneNumberPass;
}

void Patient::CreatePatient()
{
	std::ofstream patientFile("Patients.csv", std::ios::app);
	patientFile << Name << "," << Password << "," << PhoneNumber << "," << Field << "," << SurgeryName << "\n";
	patientFile.close();
}
