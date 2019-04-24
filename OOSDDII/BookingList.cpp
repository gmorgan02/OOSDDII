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

	objBooking.SetBookings();
}
