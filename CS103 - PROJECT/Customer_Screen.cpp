// Customer_Screen_LoggedIn.cpp : 
#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures


// main function below....
int main()
{	
	customerScreenMenu();		// displays menu - delete this when integrating with main menu
	
return 0;		// end of main function
}



// function definitions
void line() {
	for (int i = 0; i < 40; i++) {
		std::cout << '~';
	}
}

void customerScreenMenu() {
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
	std::cout << "Please select an option:  ";
	std::cin >> option;
   
	switch (option) {
	case 1:
		p = newPolicy(p); // form
		displayQuote(p);
		request(p);
		displayPolicy(p); // pass newPolicy data, ndisplay policy quote
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
}

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
	std::cout << "6. Go back to Main Menu\n";
	std::cout << "Please select an option:  ";
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
	case 6:
		break;
	default:
		std::cout << "Sorry, please pick from options 1-5";
		goto submenu;
		break;
	}
}

struct Policy newPolicy(struct Policy p) {
	int policy, vehicle_type;

			std::cout << "\nNEW POLICY APPLICATION\n";
			line();

// ask user to select policy category
p_menu:
			std::cout << "\n\n";
			std::cout << "1. Policy Category: (1-3)\n";
			std::cout << "1 = Comprehensive \t2 = Third Party, Fire & Theft \t3 = Third Party Only\n";
			std::cout << "\nChoose a policy category:  ";
			std::cin >> policy;

// switch case to assign fixed rate for policy type
			switch(policy) {
				case 1:
					p.category = "Comprehensive";
					p.category_rate = 0.055;	 // placeholder
					break;
				case 2:
					p.category = "Third Party, Fire & Theft";
					p.category_rate = 0.044;  // placeholder
					break;
				case 3:
					p.category = "Third Party Only";
					p.category_rate = 0.033;  // placeholder
					break;
				default:
					std::cout << "\nSorry, please choose from options 1-3\n";
					goto p_menu;
					break;
			}

// ask user to select vehicle category
v_menu:
			std::cout << "\n2. Vehicle type:\n";
			std::cout << "1 = Car \t2 = Motorcycle\n";
			std::cout << "\nChoose vehicle type:  ";
			std::cin >> vehicle_type;

// switch case to assign fixed rate for vehicle
			switch (vehicle_type) {
				case 1:
					p.vehicle = "Car";
					p.vehicle_rate = 0.025;  // placeholder;
					break;
				case 2:
					p.vehicle = "Motorcycle";
					p.vehicle_rate = 0.010;	// placeholder
					break;
				default:
					std::cout << "\nSorry please choose from option 1 or 2\n";
					goto v_menu;
					break;
			}

			std::cout << "\nWhen would you like the policy to start? (dd/mm/yyyy) \n";
			std::cin >> p.date;

			std::cout << "\nEnter car/motorcycle details: (Make, Model & Year) \n";
			std::cin.ignore();
			std::cin.getline(p.vehicle_details, 50);

			std::cout << "\nHow much is the vehicle worth? \n";
			std::cin >> p.sum_insured;


			return p;	
}

void displayQuote(struct Policy p) {

// calculate annual, monthly and fortnightly prices
 p.annual = (p.category_rate + p.vehicle_rate) * p.sum_insured;
 p.monthly = p.annual / 12;
 p.fortnightly = (p.annual / 52) * 2;

// display the quote and above calculations
			std::cout << "\nYOUR INSURANCE POLICY QUOTE\n";
			line();
			std::cout << "\n\n";
			std::cout << "Your chosen policy: " << p.category << " " << p.vehicle << std::endl;
			std::cout << "\n$" << p.fortnightly << " per fortnight" << std::endl;
			std::cout << "...or $" << p.monthly << " per month" << std::endl;
			std::cout << "...or $" << p.annual << " per year" << std::endl;

// end of function
}

int request(struct Policy p) {
	start:
		char answer;
		int answer2;
			std::cout << "\nWould you like to go ahead with this quote and register this policy? (y/n)" << std::endl;
			std::cin >> answer;
			if (answer == 'n') {
			menu:
				std::cout << "\nWould you like to: " << std::endl;
				std::cout << "1 = Start a new quote " << std::endl;
				std::cout << "2 = Go back to Customer Menu" << std::endl;
				std::cin >> answer2;

				switch(answer2) {
					case 1:
						newPolicy(p);
						displayQuote(p);
						goto start;
						break;
					case 2:
						customerScreenMenu();
						break;
					default:
						std::cout << "\nPlease choose option 1 or 2" << std::endl;
						std::cout << answer2 << std::endl;
						goto menu;
						break;
				}
			} else if (answer == 'y') {
				displayPolicy(p);
			} else {
				std::cout << "\nSorry please type 'y' for yes or 'n' for no " << std::endl;
				goto start;
			}

			return answer2;
}

// -	Policy number (should be generated automatically), first name, last name, 
// dob, gender, contact no, email, physical address, vehicle registration number, 
// vehicle name, model.
void displayPolicy(struct Policy p) {
	// when user says yes to register quote this is the next function that is called
}

// still need to define:
// void renewalInfo();
// void renewalForm();
