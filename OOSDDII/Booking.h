#pragma once
#include <string>
#include <vector>

class Surgery;

class Booking
{
public:
	Booking();
	~Booking();
	void SetTimes(std::vector<int>);
	std::vector<int> GetTimes();
	void SetPatientName(std::string);
	std::string GetPatientName();
	void SetDoctorName(std::string);
	std::string GetDoctorName();
	void SetSurgeryName(std::string);
	std::string GetSurgeryName();
	void SetBookings(std::string, std::string);
	std::vector<std::string> GetBookings();
private:
	std::vector<int> Times;
	std::string PatientName, DoctorName, SurgeryName;
};

