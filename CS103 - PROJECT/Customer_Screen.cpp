// Customer_Screen_LoggedIn.cpp : 
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures


// global variables
char cus_name[30];
int policy_num;
int position = 0;

// function definitions
void search_read() {
    std::cin.ignore();
    std::cout << "\n\nEnter the first/last name : ";
    std::cin.getline(cus_name, 40);
    std::cout << "\nEnter the policy number : ";
    std::cin >> policy_num;
}

void customerScreenMenu() {
		int option;
		struct Customer c; // to be passed through new policy process
		struct Admin a; // needs to pass thru function

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
		// newPolicy(c); // write to file
		// displayQuote(c); // read back file
		// request(c); // user chooses to apply or not
		goto menu;
		break;
	case 2:
		claimForm(a);
		goto menu;
		break;
	case 3:
		// renewalInfo(); 
		// search_read(); // find record
		// renewalForm(policy_num, cus_name); // edit record
		goto menu;
		break;
	case 4:
		benefitsMenu(); 
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

// // read from the user
// void newPolicy(struct Customer& c) {
// 	int policy, vehicle_type;
// 	Admin display; 
// 	std::fstream file;
// 	std::fstream cfile;

// 			std::cout << "\n\t\tNEW POLICY APPLICATION";
// 			line();

// // ask user to select policy category
// p_menu:
// 			std::cout << "\n\n";
// 			std::cout << "Current Policy Information & Vehicle Rates \n";
// 			line2();
// 						std::cout << "\nPlease read through info before choosing the right policy for you (recommend viewing in full-screen)\n\n";
// // READ from Admin file
// file.open("admins.dat", std::ios::in|std::ios::binary);
// 	if(file.is_open()) {
// 		file.read(reinterpret_cast<char*>(&display), sizeof(Admin));
// 		file.close();
		
// } else {
// 	std::cout << "\nOops. Policy description unavailable\n";
// }
// 	std::cout << display.policy_description << std::endl;

// 			std::cout << "\nChoose a policy category:  ";
// 			std::cin >> policy;

// cfile.open("customers.dat", std::ios::out|std::ios::app|std::ios::binary);

// // switch case to assign fixed rate for policy type
// 			switch(policy) {
// 				case 1:
// 					c.plcy->category = "Comprehensive";
// 					c.plcy->category_rate = 0.055;	
// 					break;
// 				case 2:
// 					c.plcy->category = "Third Party, Fire & Theft";
// 					c.plcy->category_rate  = 0.044;  
// 					break;
// 				case 3:
// 					c.plcy->category = "Third Party Only";
// 					c.plcy->category_rate = 0.033;  
// 					break;
// 				default:
// 					std::cout << "\nSorry, please choose from options 1-3\n";
// 					goto p_menu;
// 					break;
// 			}

// // ask user to select vehicle category
// v_menu:

// 			std::cout << "\nChoose vehicle type:  ";
// 			std::cin >> vehicle_type;

// // switch case to assign fixed rate for vehicle
// 			switch (vehicle_type) {
// 				case 1:
// 					c.plcy->vehicle = "Car";
// 					c.plcy->vehicle_rate = 500.00;  
// 					break;
// 				case 2:
// 					c.plcy->vehicle  = "Motorcycle";
// 					c.plcy->vehicle_rate = 250.00;	
// 					break;
// 				default:
// 					std::cout << "\nSorry please choose from option 1 or 2\n";
// 					goto v_menu;
// 					break;
// 			}

// 			std::cout << "\nWhen would you like the policy to start? (dd/mm/yyyy) \n";
// 			std::cin >> c.plcy->date;

// 			std::cout << "\nEnter car/motorcycle details: (Make, Model & Year) \n";
// 			std::cin.ignore();
// 			std::cin.getline(c.plcy->vehicle_details, 50);

// 			std::cout << "\nHow much is the vehicle worth? \n";
// 			std::cin >> c.plcy->sum_insured;

// cfile.write(reinterpret_cast<char*>(&c), sizeof(c)); // write new policy info
// cfile.close();
// }

// void displayQuote(struct Customer& c) {
// std::fstream cfile;
// cfile.open("customers.dat", std::ios::out|std::ios::app|std::ios::binary);

// // calculate annual, monthly and fortnightly prices
//  c.plcy->annual = (c.plcy->sum_insured * c.plcy->category_rate) + c.plcy->vehicle_rate;
//  c.plcy->monthly = c.plcy->annual / 12;
//  c.plcy->fortnightly = (c.plcy->annual / 52) * 2;

// // display the quote and above calculations
// 			std::cout << "\n\t\tYOUR INSURANCE POLICY QUOTE";
// 			line();
// 			std::cout << "\n\n";
// 			std::cout << "Your chosen policy: " << c.plcy->category << " " << c.plcy->vehicle << std::endl;
// 			std::cout << "\n$" << c.plcy->fortnightly<< " per fortnight" << std::endl;
// 			std::cout << "...or $" << c.plcy->monthly << " per month" << std::endl;
// 			std::cout << "...or $" << c.plcy->annual << " per year" << std::endl;

// cfile.write(reinterpret_cast<char*>(&c), sizeof(c)); // write new policy info
// cfile.close();
// // end of function
// }

// int request(struct Customer& c) {
// 	start:
// 		char answer;
// 		int answer2;
// 			std::cout << "\nWould you like to go ahead with this quote and register this policy? (y/n)" << std::endl;
// 			std::cin >> answer;
// 			if (answer == 'n') {
// 			menu:
// 				std::cout << "\nWould you like to: " << std::endl;
// 				std::cout << "1 = Start a new quote " << std::endl;
// 				std::cout << "2 = Go back to Customer Menu" << std::endl;
// 				std::cin >> answer2;

// 				switch(answer2) {
// 					case 1:
// 						newPolicy(c);
// 						displayQuote(c);
// 						goto start;
// 						break;
// 					case 2:
// 						customerScreenMenu();
// 						break;
// 					default:
// 						std::cout << "\nPlease choose option 1 or 2" << std::endl;
// 						std::cout << answer2 << std::endl;
// 						goto menu;
// 						break;
// 				}
// 			} else if (answer == 'y') {
// 				displayPolicy();
// 			} else {
// 				std::cout << "\nSorry please type 'y' for yes or 'n' for no " << std::endl;
// 				goto start;
// 			}

// 			return answer2;
// }

// // TEST THIS**
// // ERRORS: 
// // dob field also prints email, registration field prints twice
// // also if name check is incorrect, it doesnt recognise valid name when trying again
// void displayPolicy() {
	
// 	srand(time(NULL));
// 	std::fstream file;
// 	bool flag = false;
// 	char fname[20];
// 	char lname[20];
// 	Customer cus;

// 	std::cout << "Please confirm your first name:   ";
// 	std::cin >> fname;
// 	std::cout << "And last name:   ";
// 	std::cin >> lname;

//     file.open("customers.dat", std::ios::out|std::ios::in|std::ios::binary);

//     if (file.is_open()) {

// 					while(!file.eof()) {
// 						file.read(reinterpret_cast<char*>(&cus), sizeof(Customer));

//             	if ((strcmp(fname, cus.first_name) == 0) && (strcmp(lname, cus.last_name) == 0)) {

// 							cus.plcy->policynum = rand() % 300 + 100;		// generate random number

// 							std::cout << "\nCongratulations! Your policy has been registered\n";
// 							line2();
// 							std::cout<< "Policy Number:  " << cus.plcy->policynum << std::endl;	
// 							std::cout<< "\n~~Driver's Details~~  " << std::endl;
// 							std::cout<< "Name:  " << cus.first_name << " " << cus.last_name << std::endl;
// 							std::cout<< "Gender:  " << cus.gender << std::endl;
// 							std::cout<< "Date of birth:  " << cus.birthday << std::endl; // prints email aswell
// 							std::cout<< "Email:  " << cus.email << std::endl; 
// 							std::cout<< "Contact number:  " << cus.phone << std::endl;
// 							std::cout<< "\n~~Vehicle Details~~  " << std::endl;
// 							std::cout<< "Registration Number:  " << cus.rego << std::endl; // prints twice
// 							std::cout<< "Make, Model & Year:  " << cus.plcy->vehicle_details << std::endl;
// 							std::cout<< "Vehicle address:  " << cus.address << std::endl; 
// 							flag = true;
// 							file.close();
// 							break;
// 							} else
// 									flag = false;
// 					}

//     } else
//         std::cout << "\nFile error. Please contact admin\n";

// // end of function
// }

// void renewalInfo() {
// 	std::cout << "\n\t\tThe Renewal process:" << std::endl;
// 	line();
// 	std::cout << "Select which current policy you'd like to renew, confirm your personal details and add payment details" << std::endl;
// 	std::cout << "\nIf you choose to change policy category(go from comprehensive to third party only), this will affect how much you need to pay\n" << std::endl;

// }

// // CHECK THIS
// void renewalForm(int policy_num, char cus_name[]) {
// 	Customer cus;
// 	int policy;
// 	bool flag = false;
// 	std::fstream file;

// 	file.open("customers.dat", std::ios::in|std::ios::out|std::ios::binary);

// 	if(file.is_open()) {
// 		while(!file.eof()) {
			
// 			file.read(reinterpret_cast<char*>(&cus), sizeof(cus));
// 			position = file.tellg(); 

// 			if((strcmp(cus_name, cus.first_name) == 0) || (strcmp(cus_name, cus.last_name) == 0)) {
// 				if (policy_num == cus.plcy->policynum) {
// 							std::cout << "\n\t\t**Your current policy**" << std::endl;
// 							std::cout << "\nDriver's Name:  " << cus.first_name << " " << cus.last_name << std::endl;
// 							std::cout << "Contact Number:  " << cus.phone << std::endl;
// 							std::cout << "Policy Type:  " << cus.plcy->category << " " << cus.plcy->vehicle << std::endl;
// 							std::cout << "Vehicle Details:  " << cus.plcy->vehicle_details << std::endl;

// 							file.seekp(position-(sizeof(cus)));

// 							std::cout << "\n\t\tRenewal form\n" << std::endl;
// 							line();
// 							std::cout << "\nDriver's First Name:  ";
// 							std::cin >> cus.first_name;
// 							std::cout << "\nDriver's Last Name:  ";
// 							std::cin >> cus.last_name;
// 							std::cout << "\nContact Number:  ";
// 							std::cin >> cus.phone;
// 				p_menu:
// 							std::cout << "\nChoose a policy category (1.Comprehensive, 2.Third Party, Fire & Theft, 3.Third Party Only):  ";
// 							std::cin >> policy;

// 				// switch case to assign fixed rate for policy type
// 							switch(policy) {
// 								case 1:
// 									cus.plcy->category = "Comprehensive";
// 									cus.plcy->category_rate = 0.055;	
// 									break;
// 								case 2:
// 									cus.plcy->category = "Third Party, Fire & Theft";
// 									cus.plcy->category_rate = 0.044;  
// 									break;
// 								case 3:
// 									cus.plcy->category= "Third Party Only";
// 									cus.plcy->category_rate = 0.033;  
// 									break;
// 								default:
// 									std::cout << "\nSorry, please choose from options 1-3\n";
// 									goto p_menu;
// 									break;
// 							}
// 							std::cout << "\nAdd card number (16 digits, no spaces):  ";
// 							std::cin >> cus.visa;

// 							file.write(reinterpret_cast<char*>(&cus), sizeof(cus));
// 							flag = false;
// 							break;
// 				} // policy num check statement
// 			} else // name check statement
// 			flag = true;
// 		} // end of file
// 	} else // file is not open
// 			std::cout << "\nFile not found\n";

// 	if(flag) {
// 					std::cout << "\nCannot find Customer policy\n";
// 	}

// 	file.close();

// }
