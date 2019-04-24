#include "Surgery.h"
#include "Patient.h"
#include "Doctor.h"
#include "Booking.h"
#include <fstream>
#include <iostream>

void BookingList(Surgery* objSelectedSurgery, Patient* objLoggedInPatient, Doctor* objSelectedDoctor)
{	
	Booking objBooking;
	objBooking.SetSurgeryName(objSelectedSurgery->GetName());
	objBooking.SetDoctorName(objSelectedDoctor->GetName());
	objBooking.SetPatientName(objLoggedInPatient->GetName());
	int timeSelected;
	std::string stringCheck = "\n";

	std::vector<std::string> bookingInfos = objBooking.GetBookings();
	std::vector<std::string> processedBookingInfo;

	for (std::vector<std::string>::value_type bookinginfo : bookingInfos)
	{
		if (bookinginfo.find(stringCheck) != std::string::npos)
		{
			bookinginfo.erase(0, 1);
		}
		processedBookingInfo.push_back(bookinginfo);
	}









	std::string booking;
	std::vector<std::string> storedBookings;

	std::ofstream writeBookingFile(objSelectedSurgery->GetName()+"_Bookings.csv", std::ios::app);
	for (int i = 0; i < times.size(); i++)
	{
		if (times[i] == 1300)
		{
			std::cout << " Lunch - 1400";
		}

		if (times[i] == 1100)
		{
			std::cout << " Break - 1130";
		}
		writeBookingFile << times[i] << "\n";
	}
	writeBookingFile.close();

	std::cout << "Please select a time to book (enter time as shown):";
	std::ifstream readBookingFile(objSelectedSurgery->GetName() + "_Bookings.csv");

	while (std::getline(readBookingFile, booking, ','))
	{
		storedBookings.push_back(booking);
	}


	for (int i = 0; i < times.size(); i++)
	{
		std::cout << storedBookings;
	}
	std::cin >> timeSelected;

	
}
