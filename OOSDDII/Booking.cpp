#include "Booking.h"
#include "Surgery.h"
#include <fstream>
#include <iostream>


Booking::Booking()
{
	Times = { 900,915,930,945,1000,1015,1030,1045,1100,1115,1130,1145,1200,1300,1315,1330,1345,1400,1415,1430,1445,1500,1530,1545,1600,1615,1630,1645 };
	PatientName = "";
	DoctorName = "";
	SurgeryName = "";
}


Booking::~Booking()
{
}

void Booking::SetTimes(std::vector<int> timesPass)
{
	Times = timesPass;
}

std::vector<int> Booking::GetTimes()
{
	return Times;
}

void Booking::SetPatientName(std::string patientNamePass)
{
	PatientName = patientNamePass;
}

std::string Booking::GetPatientName()
{
	return PatientName;
}

void Booking::SetDoctorName(std::string doctorNamePass)
{
	DoctorName = doctorNamePass;
}

std::string Booking::GetDoctorName()
{
	return DoctorName;
}

void Booking::SetSurgeryName(std::string surgeryNamePass)
{
	SurgeryName = surgeryNamePass;
}

std::string Booking::GetSurgeryName()
{
	return SurgeryName;
}

void Booking::SetBookings(std::string doctorNamePass, std::string patientNamePass)
{
	std::vector<std::string> bookings;
	std::string storedBookings;

	std::ofstream bookingFile(SurgeryName + "_Bookings.csv");

	for (int i = 0; i < Times.size(); i++)
	{		
		bookingFile << Times[i] << "," << DoctorName << "," << PatientName << "\n";
	}
	
}

std::vector<std::string> Booking::GetBookings()
{
	std::vector<std::string> bookings;
	std::string storedBookings;

	std::ifstream bookingFile(SurgeryName + "_Bookings.csv");

	while (std::getline(bookingFile, storedBookings, ','))
	{
		bookings.push_back(storedBookings);
	}

	return bookings;
}
