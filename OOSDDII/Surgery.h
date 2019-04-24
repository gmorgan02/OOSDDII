#pragma once
#include <string>
#include <vector>


class Surgery
{
public:
	Surgery();
	~Surgery();
	void SetName(std::string);
	std::string GetName();
	void SetLocation(std::string);
	std::string GetLocation();
	std::vector<std::string> GetSurgeries();
	void CreateSurgery(std::string, std::string);
private:
	std::string Name, Location;
	
};

