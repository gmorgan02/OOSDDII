#include "Surgery.h"
#include <fstream>


Surgery::Surgery()
{
}


Surgery::~Surgery()
{
}

void Surgery::GetSurgery(std::string namePass, std::string passwordPass, std::string fieldPass, std::string surgeryNamePass)
{
	std::string Name = namePass, Password = passwordPass, Field = fieldPass, SurgeryName = surgeryNamePass;
}

void Surgery::CreateSurgery(std::string namePass, std::string passwordPass, std::string fieldPass, std::string surgeryNamePass)
{
	std::ofstream surgeryFile("Surgeries.csv", std::ios::app);
	surgeryFile << namePass << "," << passwordPass << "," << fieldPass << "," << surgeryNamePass << "\n";
	surgeryFile.close();
}