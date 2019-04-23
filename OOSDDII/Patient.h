#pragma once
#include <string>

class Patient
{
public:
	Patient();
	~Patient();
	void GetPatient(std::string, std::string, int, std::string, std::string);
	void CreatePatient();
private:
	std::string Name, Password, Address, Ailment;
	int PhoneNumber;

};

