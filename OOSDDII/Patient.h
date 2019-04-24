#pragma once
#include <string>
#include <vector>

class Patient
{
public:
	Patient();
	~Patient();
	void SetName(std::string);
	std::string GetName();
	void SetPassword(std::string);
	std::string GetPassword();
	void SetAddress(std::string);
	std::string GetAddress();
	void SetAilment(std::string);
	std::string GetAilment();
	void SetPhoneNumber(std::string);
	std::string GetPhoneNumber();
	std::vector<std::string> GetPatients();
	void CreatePatient(std::string, std::string, std::string, std::string, std::string);
private:
	std::string Name, Password, Address, Ailment, PhoneNumber;

};

