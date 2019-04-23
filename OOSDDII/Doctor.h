#pragma once
#include <string>

class Doctor
{
public:
	Doctor();
	~Doctor();
	void GetDoctor(std::string, std::string, std::string, std::string);
	void CreateDoctor(std::string, std::string, std::string, std::string);
private:
	std::string Name, Password, Field, SurgeryName;
};

