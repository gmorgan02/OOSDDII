#pragma once
#include <string>

class Doctor
{
public:
	Doctor();
	~Doctor();
	void GetDoctor(std::string, std::string, std::string, std::string);
	void CreateDoctor();
private:
	std::string Name, Password, Field, SurgeryName;
};

