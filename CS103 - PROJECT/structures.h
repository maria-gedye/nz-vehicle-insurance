#include <iostream>
#include <fstream>
#include <string>

// structure for new policies
struct Policy {	
	std::string category;
	std::string vehicle;
	char date[10],
			vehicle_details[50];
	float category_rate,
			vehicle_rate,
			annual, monthly, fortnightly;
	double sum_insured;
};