// Customer_Screen_LoggedIn.cpp : 
//3.	Customer screen should include:
//�	A menu contains the following option :
//-Policy and insurance application process(see Task 4),
//-claim(See task 5),
//-renewal(See task 6),
//-benefits of NZ insurance

#include <iostream>
#include <fstream>
#include "functions.h"

// define structure for new policies
struct Policy {	
	char category[35],
			vehicle[11],
			date[10],
			vehicle_details[50];
	float category_rate,
			vehicle_rate;
	double sum_insured;

};

// function prototypes
void line();
void benefitsMenu();
struct Policy newPolicy(struct Policy);
void displayQuote(struct Policy); 
void displayPolicy();
void renewalInfo();
void renewalForm();

// main function below
int main()
{
	int option;
	struct Policy p;
	
	menu:
	std::cout << "\n\nWELCOME TO THE CUSTOMER SCREEN\n";
	line();
	std::cout << "\n\n";
	std::cout << "1. New policy application\n";
	std::cout << "2. Make a claim\n";
	std::cout << "3. Renew a policy\n";
	std::cout << "4. Benefits of insurance\n";
	std::cout << "5. Log out\n";
	std::cout << "Please select an option:  \n";
	std::cin >> option;
   
	switch (option) {
	case 1:
		p = newPolicy(p); // form
		displayQuote(p);
		displayPolicy(); // pass newPolicy data, ndisplay policy quote
		goto menu;
		break;
	case 2:
				// link to claim_form.cpp;
		goto menu;
		break;
	case 3:
		// renewalInfo(); // display info
		// renewalForm(); // form
		goto menu;
		break;
	case 4:
		benefitsMenu(); // this needs to pass data from a fstream file
		goto menu;
		break;
	case 5:
		std::cout << "\nYou have been logged out\n";
		// link to vehicle_insurance.cpp
		break;
	default:
		std::cout << "Sorry, please pick from options 1-5";
		goto menu;
		break;
	}

return 0;		// end of main function

}


// function definitions
void line() {
	for (int i = 0; i < 40; i++) {
		std::cout << '~';
	}
}

struct Policy newPolicy(struct Policy p) {
	int policy, vehicle_type;

			std::cout << "\nNEW POLICY APPLICATION\n";
			line();
			std::cout << "\n\n";
			std::cout << "Choose a policy: (1-3)\n";
			std::cout << "1 = Comprehensive \t2 = Third Party, Fire & Theft \t3 = Third Party Only\n\n";
			std::cin >> policy;

			std::cout << "Choose vehicle type:\n";
			std::cout << "1 = Car \t2 = Motorcycle\n\n";
			std::cin >> vehicle_type;

			std::cout << "When would you like the policy to start? \n";
			std::cin >> p.date;

			std::cout << "Enter car/motorcycle details: (Make, Model & Year) \n";
			std::cin >> p.vehicle_details;

			std::cout << "How much is the vehicle worth? \n";
			std::cin >> p.sum_insured;

			return p;
}

void displayQuote(struct Policy p) {
			std::cout << "\nYOUR INSURANCE POLICY QUOTE\n";
			line();
			std::cout << "\n\n";
			std::cout << "Choose a policy:\n";
// quote - policy + vehicle type * 52, follow example
}

void displayPolicy() {
// 	policy registration -	Policy number (should be generated automatically), first name, last name, dob, gender, 
// contact no, email, physical address, vehicle registration number, vehicle name, model.
}
// void renewalInfo();
// void renewalForm();

void benefitsMenu() {
int option;

	submenu:
	std::cout << "\n\nINSURANCE BENEFITS\n";
	line();
	std::cout << "\n\n";
	std::cout << "1. New signup discounts\n";
	std::cout << "2. Multi policy discount\n";
	std::cout << "3. Renewal discount\n";
	std::cout << "4. Discount for reviewing the insurance\n";
	std::cout << "5. Introducing friends or family discount\n";
	std::cout << "Please select an option:  \n";
	std::cin >> option;
   
	switch (option) {
	case 1:
		std::cout << "\nNEW SIGNUP DISCOUNT:\n";
		std::cout << "All customers will receive a discount off their first year’s premium for each car insurance policy bought online.\n";
		std::cout << "The amount of the Discount is $50 for Car Comprehensive, $25 for Car Third Party Fire and Theft, and $10 for Car Third Party Only.\n";
		goto submenu;
		break;
	case 2:
		std::cout << "\nMULTI POLICY DISCOUNT:\n";
		std::cout << "To qualify for our Multi-Policy Discount, you must have a Car Comprehensive policy plus one other qualifying policy. These are: \n";
		std::cout << "• Car Third Party Fire and Theft \n";
		std::cout << "• Car Third Party Only \n";
		std::cout << "• Motorcycle Comprehensive \n";
		std::cout << "• Motorcycle Third Party Only \n";
		std::cout << "\nThe amount of the Discount is 10% \n";
		goto submenu;
		break;
	case 3:
		std::cout << "\nRENEWAL DISCOUNT:\n";
		std::cout << "If you have held your insurance policy with us for more than a year you may qualify for this discount. \n";
		std::cout << "\nThe amount of the Discount is 5% \n";
		goto submenu;
		break;
	case 4:
		std::cout << "\nREVIEW DISCOUNT\n";
		std::cout << "To qualify for our Review Discount, you nust have had a Car or Motorcycle Third Party Only policy for at least one year before upgrading to another qualifying policy. These are:  \n";
		std::cout << "• Car Third Party Fire and Theft \n";
		std::cout << "• Motorcycle Comprehensive \n";
		std::cout << "\nThe amount of the Discount is 7.5% \n";
		goto submenu;
		break;
	case 5:
		std::cout << "\nINTRODUCE A FRIEND OR FAMILY:\n";
		std::cout << "All customers will receive a discount off their first year’s premium for each friend or family member that purchases an insurance policy with us.\n";
		std::cout << "The amount of the Discount per referral is $100 for Car Comprehensive, $50 for Car Third Party Fire and Theft, and $25 for Car Third Party Only.\n";
		goto submenu;
		break;
	default:
		std::cout << "Sorry, please pick from options 1-5";
		goto submenu;
		break;
	}
}

