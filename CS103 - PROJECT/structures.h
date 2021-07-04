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
			annual, 
			monthly, 
			fortnightly;
	double sum_insured;
	int policynum; 
};

// claims structure
struct Claims { 
    char name[50], 
				date[10],
				time[7], 
				incident[100], 
				damage[100], 
				email[30],
				phone[14];
    int policynum; 

};


// structure for customer information 
struct Customer{
    char first_name[20], 
				last_name[20], 
				user_name[30],	// needs to be char [] for comparison
				password[30],	// needs to be char [] for comparison
				gender[6], 
				birthday[10], 
				email[30], 
  		  phone[14],
				rego[6],
				licence[8],
				address[45];
		// struct Policy pol;		// cause malloc error
		// struct Claims cla;
};

// structure for admin capabilities
struct Admin {
	char user_name[20],
			password[20],
			discount_signup[220],
			discount_multi[292],
			discount_renewal[145],
			discount_review[286],
			discount_friend[295],
			policy_description[355];
	int customer_counter,
			claim_counter,
			renewal_counter,
			new_reg_counter;
};

