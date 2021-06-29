#include <iostream>
#include <fstream>
#include <string>

// structure for customer information 
struct Customer{
    char first_name[20], 
				last_name[20], 
				gender[6], 
				birthday[10], 
				email[30], 
				rego[6],
				licence[8],
				user_name[30],	// needs to be char [] for comparison
				password[30];	// needs to be char [] for comparison
    int phone;
    std::string address;
};

// structure for new policies
struct Policy {	
	std::string category;
	std::string vehicle;
	char date[10],
			vehicle_details[50];
	float category_rate,
			vehicle_rate,
			annual, 
			monthly, 
			fortnightly;
	double sum_insured;
};

// add in claims structure