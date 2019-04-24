#include "Surgery.h"
#include <fstream>


Surgery::Surgery()
{
	Name = "";
	Location = "";
}


Surgery::~Surgery()
{
}

void Surgery::SetName(std::string namePass)
{
	Name = namePass;
}

std::string Surgery::GetName()
{
	return Name;
}

void Surgery::SetLocation(std::string locationPass)
{
	std::string Location = locationPass;
}

std::string Surgery::GetLocation()
{
	return  Location;
}

std::vector<std::string> Surgery::GetSurgeries()
{
	std::vector<std::string>surgeries;
	std::string storedSurgeries;

	std::ifstream surgeriesFile("Surgeries.csv");

	while (std::getline(surgeriesFile, storedSurgeries, ','))
	{
		surgeries.push_back(storedSurgeries);
	}

	return surgeries;
}

void Surgery::CreateSurgery(std::string namePass, std::string locationPass)
{
	std::ofstream surgeryFile("Surgeries.csv", std::ios::app);
	surgeryFile << namePass << "," << locationPass << "\n";
	surgeryFile.close();
}