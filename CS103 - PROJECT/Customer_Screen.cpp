// Customer_Screen_LoggedIn.cpp : 
#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures


// function definitions
void customerScreenMenu() {
		int option;
		struct Policy p;
		struct Customer c; // needs to pass thru function

menu:
	std::cout << "\n\n\t\tWELCOME TO THE CUSTOMER SCREEN";
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
		request(p, c); // user chooses to apply or not
		displayPolicy(p, c); 
		goto menu;
		break;
	case 2:
		claimForm();
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
		menu();
		break;
	default:
		std::cout << "Sorry, please pick from options 1-5";
		goto menu;
		break;
	}
}

void benefitsMenu() {
int option;
Admin display;
std::fstream file;

	submenu:
	std::cout << "\n\n\t\tINSURANCE BENEFITS";
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

file.open("admins.dat", std::ios::in|std::ios::binary);
if(file.is_open()) {
	file.read(reinterpret_cast<char*>(&display), sizeof(Admin));
	file.close();
} else {
	std::cout << "\nUh oh. Discount information unavailable\n";
}
   
	switch (option) {
	case 1:
		std::cout << "\nNEW SIGNUP DISCOUNT:\n";
		std::cout << display.discount_signup << std::endl;
		goto submenu;
		break;
	case 2:
		std::cout << "\nMULTI POLICY DISCOUNT:\n";
		std::cout << display.discount_multi << std::endl;
		goto submenu;
		break;
	case 3:
		std::cout << "\nRENEWAL DISCOUNT:\n";
		std::cout << display.discount_renewal<< std::endl;
		goto submenu;
		break;
	case 4:
		std::cout << "\nREVIEW DISCOUNT\n";
		std::cout << display.discount_review<< std::endl;
		goto submenu;
		break;
	case 5:
		std::cout << "\nINTRODUCE A FRIEND OR FAMILY:\n";
		std::cout << display.discount_friend << std::endl;
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
	Admin display; 
	std::fstream file;

			std::cout << "\n\t\tNEW POLICY APPLICATION";
			line();

// ask user to select policy category
p_menu:
			std::cout << "\n\n";
			std::cout << "Current Policy Information & Vehicle Rates \n";
			line2();
						std::cout << "\nPlease read through info before choosing the right policy for you (recommend viewing in full-screen)\n\n";
// READ from Admin file
file.open("admins.dat", std::ios::in|std::ios::binary);
if(file.is_open()) {
	file.read(reinterpret_cast<char*>(&display), sizeof(Admin));
	file.close();
} else {
	std::cout << "\nOops. Policy description unavailable\n";
}
	std::cout << display.policy_description << std::endl;

			std::cout << "\nChoose a policy category:  ";
			std::cin >> policy;

// switch case to assign fixed rate for policy type
			switch(policy) {
				case 1:
					p.category = "Comprehensive";
					p.category_rate = 0.055;	
					break;
				case 2:
					p.category = "Third Party, Fire & Theft";
					p.category_rate = 0.044;  
					break;
				case 3:
					p.category = "Third Party Only";
					p.category_rate = 0.033;  
					break;
				default:
					std::cout << "\nSorry, please choose from options 1-3\n";
					goto p_menu;
					break;
			}

// ask user to select vehicle category
v_menu:

			std::cout << "\nChoose vehicle type:  ";
			std::cin >> vehicle_type;

// switch case to assign fixed rate for vehicle
			switch (vehicle_type) {
				case 1:
					p.vehicle = "Car";
					p.vehicle_rate = 500.00;  
					break;
				case 2:
					p.vehicle = "Motorcycle";
					p.vehicle_rate = 250.00;	
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
 p.annual = (p.sum_insured * p.category_rate) + p.vehicle_rate;
 p.monthly = p.annual / 12;
 p.fortnightly = (p.annual / 52) * 2;

// display the quote and above calculations
			std::cout << "\n\t\tYOUR INSURANCE POLICY QUOTE";
			line();
			std::cout << "\n\n";
			std::cout << "Your chosen policy: " << p.category << " " << p.vehicle << std::endl;
			std::cout << "\n$" << p.fortnightly << " per fortnight" << std::endl;
			std::cout << "...or $" << p.monthly << " per month" << std::endl;
			std::cout << "...or $" << p.annual << " per year" << std::endl;

// end of function
}

int request(struct Policy& p, struct Customer& c) {
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
				displayPolicy(p, c);
			} else {
				std::cout << "\nSorry please type 'y' for yes or 'n' for no " << std::endl;
				goto start;
			}

			return answer2;
}

void displayPolicy(struct Policy& p, struct Customer& c) {
	std::fstream file;

	std::cout << "\nCongratulations! Your insurance policy has been registered\n";
	line2();
	std::cout<< "Policy Number:  " << std::endl;	// need to generate random number

file.open("customers.dat", std::ios::in|std::ios::binary);
if(file.is_open()) {
	file.read(reinterpret_cast<char*>(&c), sizeof(Customer));
	file.close();
} else {
	std::cout << "\nUh oh. Data unavailable\n";
}

	std::cout<< "\n~~Driver's Details~~  " << std::endl;
	std::cout<< "Name:  " << c.first_name << " " << c.last_name << std::endl;
	std::cout<< "Date of birth:  " << c.birthday << std::endl; // fix this line
	std::cout<< "Gender:  " << c.gender << std::endl;
	std::cout<< "Contact number:  " << c.phone << std::endl;
	std::cout<< "Email:  " << c.email << std::endl;
	std::cout<< "Home address:  " << c.address << std::endl; // needs getline
	std::cout<< "~~Vehicle Details~~  " << std::endl;
	std::cout<< "Registration Number:  " << c.rego << std::endl;
	std::cout<< "Make, Model & Year:  " << p.vehicle_details << std::endl;
}

// still need to define:
// void renewalInfo();
// void renewalForm();
