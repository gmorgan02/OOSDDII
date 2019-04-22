#include <iostream>
#include "sqlite3.h"

bool ValidateLogin(std::string, std::string)
{
	sqlite3 * connection = nullptr;
	int result = sqlite3_open("OOSDDII.db", &connection);

	if (SQLITE_OK != result)
	{
		std::cout << "\n" << sqlite3_errmsg(connection);
		sqlite3_close(connection);
		return result;
	}

	sqlite3_stmt* query = nullptr;
	result = sqlite3_prepare_v2(connection, "SELECT Name, Password FROM Doctors", -1, &query, nullptr);

	if (SQLITE_OK != result)
	{
		std::cout << "\n" << sqlite3_errmsg(connection);
		sqlite3_close(connection);
		return result;
	}

	while (SQLITE_ROW == sqlite3_step(query))
	{
		std::cout << "\n" << sqlite3_column_text(query, 0);
	}

	sqlite3_finalize(query);
	sqlite3_close(connection);

	return false;
}

void DoctorLogin()
{
	std::string enteredName;
	std::string enteredPassword;
	bool validLogin = false;
	



	while (!validLogin)
	{
		std::cout << "Please Enter your name(First Name *Space* Last Name)\n";
		std::cin >> enteredName;
		std::cout << "Please Enter your Password\n";
		std::cin >> enteredPassword;
		ValidateLogin(enteredName, enteredPassword);
	}
}


