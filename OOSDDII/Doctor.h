#pragma once
#include <string>
#include <vector>

class Doctor
{
public:
	Doctor();
	~Doctor();
	void SetName(std::string);
	std::string GetName();
	void SetPassword(std::string);
	std::string GetPassword();
	void SetField(std::string);
	std::string GetField();
	void SetSurgeryName(std::string);
	std::string GetSurgeryName();
	std::vector<std::string> GetDoctors();
	void CreateDoctor(std::string, std::string, std::string, std::string);
private:
	std::string Name, Password, Field, SurgeryName;
};

