#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures


// declare global variables 
int user_choice, choice2;
char email[30], username[30], password[30], admin_n[30], admin_p[30];
bool cflag, aflag;
const int SIZE = 20;
char cus_name[30];
int policy_num;
int position = 0;
int count;


void test()
{
    Customer cus;
    std::fstream file;

    file.open("customers.dat", std::ios::in | std::ios::binary); // opening in a read mode

    std::cout << "\n\n All Records.....\n";

    if (file.is_open())
    {
        while (file.read(reinterpret_cast<char*>(&cus), sizeof(cus)))
        {
           std::cout << "\n\n " << cus.policynum;
           std::cout << "\t  " << cus.rego;
           std::cout << "\t\t   " << cus.birthday;
           std::cout << "\t\t\t " << cus.first_name;
           std::cout << "\t\t\t " << cus.last_name;
           std::cout << "\t\t\t " << cus.sum_insured;
           std::cout << "\t\t\t " << cus.vehicle_details;
        }
    }
    else
    {
        std::cout << "\nFile unable to access ....";
    }

    file.close();

}

// main function below...
int main ()
{
    // test();  // displays all records
    adminSetup(); // write default insurance info & admin login
    menu(); // calling the menu function 

// end of main function
    return 0;
 }


// function definitions below
void line()
{
    std::cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~";
}

void line2()
{
    for(int i = 0; i < 60; i++) {
        std::cout << "~";
    };
    std::cout << "\n";
}

// MAIN MENU SCREEN FUNCTIONS ***
void adminSetup() {
    std::fstream file;

    struct Admin a = { "admin", "hi123",   // default login access
// default discount 1:
                 "Receive discount off your first year’s premium for each car insurance policy bought.\nDiscount is $50 for Car Comprehensive, $25 for Car Third Party Fire and Theft, and $10 for Car Third Party Only.\n",
// default discount 2:                 
                "To qualify for our Multi-Policy Discount, you must have a Car Comprehensive policy plus one other qualifying policy. These are: \n- Car Third Party Fire and Theft \n- Car Third Party Only \n- Motorcycle Comprehensive \n- Motorcycle Third Party Only \n\nThe amount of the Discount is 10% \n",
// default discount 3:
                "If you have held your insurance policy with us for more than a year you may qualify for this discount. \n\nThe amount of the Discount is 5% \n",
// default discount 4:
                "To qualify for our Review Discount, you nust have had a Car or Motorcycle Third Party Only policy for at least one year before upgrading to another qualifying policy. These are:  \n- Car Third Party Fire and Theft \n- Motorcycle Comprehensive \n\nThe amount of the Discount is 7.5% \n",
// default discount 5:
                "All customers will receive a discount off their first year’s premium for each friend or family member that purchases an insurance policy with us.\nThe amount of the Discount per referral is $100 for Car Comprehensive, $50 for Car Third Party Fire and Theft, and $25 for Car Third Party Only.\n",
// default policy info:
                "Policy Category:\t\t\t\t1. Comprehensive \t2. Third Party, Fire & Theft \t3. Third Party Only\nAccidental loss or damage to your car\t\tYes \t\t\tYes \t\t\t\tNo\nDamage to someone else's vehicle or property\tYes\t\t\tYes \t\t\t\tYes\nTransport expenses\t\t\t\tYes\t\t\tNo \t\t\t\tNo\n\nVehicle fixed rates:\n1. Car $500 pa\n2. Motorcycle $250 pa\n"
// default counters
                // 0,0,0,0    
                };

file.open("admins.dat", std::ios::out |std::ios::binary);
   if(file.is_open()) {
       std::cout << "\nLoading App...\n";

    file.write(reinterpret_cast<char*>(&a), sizeof(Admin));
    file.close();
    } else {
        std::cout << "\nError: Admin file not found\n";
    }
}

void menu() // menu for the user to choose from 
{

start:
    std::cout << "\n\t\tEvolve Insurance";
    line();
    std::cout <<"\n\n";

    std::cout << "\nWelcome, Please Sign In \n";
    std::cout << "\n1. Customer Login/Register ";
    std::cout << "\n2. Adminstrator Login";
    std::cout << "\n3. Evolve Insurance Contact Us";

    std::cout << "\n\nPlease select an option : ";
    std::cin >> user_choice;

        switch(user_choice) // switch case for the implementation of the appropriate menus 
    {
        case 1:
        loginMenu();
        break;

        case 2: 
        adminLogin();
        aflag = adminValidation(admin_n, admin_p);
        aLoginOutcome(aflag);
        adminScreenMenu();
        goto start;
        break;

        case 3:
        contact();
        goto start;
        break;

        default:
        std::cout << "Please input a valid option \n\n";
        goto start;
    }
}

void loginMenu() {
    int choice;

start:
        std::cout << "\nRegister as new customer / Customer login" << std::endl;
        line2();
        std::cout << "\nPress 1 to REGISTER or 2 to LOG IN:   ";
        std::cin >> choice;

            switch(choice) {
                case 1:
                    readCustomer();
                    // std::cin.clear(); login first attempt error
                    customerLogin();
                    cflag = customerValidation(username, password);
                    cLoginOutcome(cflag);
                    goto start;
                    break;
                case 2:
                    std::cin.ignore();
                    customerLogin();
                    cflag = customerValidation(username, password);
                    cLoginOutcome(cflag);
                    break;
                default:
                    std::cout << "\nPlease choose option 1 or 2\n" << std::endl;
                    std::cin.clear();
                    std::cin.ignore();
                    goto start;
                    break;
            }
}

void customerLogin() // login details 
{
std::cout << "\nLogin to MyEvolve Insurance";
std::cout << "\n\nEmail or Username : ";
std::cin.getline(username, 30);
std::cout << "\nPassword : ";
std::cin.getline(password, 30);

}

void adminLogin() // admin details
{
std::cin.ignore();
std::cout << "\nLogin to Evolve Insurance Admin";
std::cout << "\n\nEmail or Username : ";
std::cin.getline(admin_n, 30);
std::cout << "\nPassword : ";
std::cin.getline(admin_p, 30);

}

void contact() // contact details 
{
std::cout << "\nCall Centre Hours";
std::cout << "\n8am - 8pm Monday to Friday";
std::cout << "\n8am - 6pm on weekends and public holidays";

std::cout << "\n\nQuotes and general enquiries : ";
std::cout << "\nCall 0800 500 231";

std::cout << "\n\nClaims";
std::cout <<"\nCall 0800 500 216";

std::cout <<"\n\nEmail Us";
std::cout <<"\ncustomerhelp@evolveinsurance.co.nz\n";


}

bool customerValidation(char field1[30], char field2[30]) {
    Customer all_customers[SIZE];
    std::fstream file;
    bool flag;

    file.open("customers.dat", std::ios::in|std::ios::binary);

    if (file.is_open()) {

        while (!file.eof()) {

            file.read(reinterpret_cast<char*>(all_customers), SIZE * sizeof(Customer));

            // compare user input with whats stored in the customers file
        for(int i = 0; i < SIZE; i++) {
            if ((strcmp(field1, all_customers[i].email) == 0) || (strcmp(field1, all_customers[i].user_name) == 0)) {
                if (strcmp(field2, all_customers[i].password) == 0) {
                flag = true;
                break;
                } else
                    flag = false;
            }
        } // end of loop
        } // end of file
    } else
        std::cout << "\nFile error. Please contact admin\n";

    return flag;
}

void cLoginOutcome(bool f) {
    int count = 0;

start:
    if (f) {
        std::cout << "\n** Log in successful **" << std::endl;
        customerScreenMenu();
    } else {
        std::cout << "\nSorry, username or password was wrong. Press enter to try again" << std::endl; 
        count++;
        if (count < 3) {
        customerLogin();
        f = customerValidation(username, password);
        goto start;
        }
        else 
        std::cout << "\nSorry, there have been too many unsuccessful attempts. Please wait before trying again" << std::endl; 

    }
// end of function
}

bool adminValidation(char field1[30], char field2[30]) {
    Admin a; // needed to access admin usernames and passwords
    std::fstream file;
    bool flag;

    file.open("admins.dat", std::ios::in|std::ios::binary); // need to create this
    if (file.is_open()) {
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(&a), sizeof(a));
            // compare user input with whats stored in the customers file
            if ((strcmp(field1, a.user_name) == 0) && (strcmp(field2, a.password) == 0)) {
                flag = true;
                break;
            } else
            flag = false;
        }
    } else
    std::cout << "\nCannot find file\n";
    return flag;
}

void aLoginOutcome(bool f){
    int count = 0;

start:
    if (f) {
        std::cout << "\n** Log in successful **" << std::endl;
        // adminScreenMenu(); // need to define
    } else {
        std::cout << "\nSorry, username or password was wrong. Press enter to try again" << std::endl; 
        std::cout << "HINT username: admin \t password: hi123" << std::endl; 
        count++;
        if (count < 3) {
        adminLogin();  
        f = adminValidation(username, password);
        goto start;
        }
        else 
        std::cout << "\nSorry, there have been too many unsuccessful attempts. Please wait before trying again" << std::endl; 

    }
// end of function
}


// CUSTOMER SCREEN FUNCTIONS ***
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
		Customer c; // assign to newPolicy() and pass to displayQuote()
        Admin a; // pass through claimForm()

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
		c = newPolicy(); // write to file
		displayQuote(c); // read back file
		registerPolicy(); // user chooses to apply or not
		goto menu;
		break;
	case 2:
		count = claimForm(a);
		goto menu;
		break;
	case 3:
		renewalInfo(); 
		renewalForm(username, password); // edit record
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

// read from the user
struct Customer newPolicy() {
	int policy, vehicle_type;
	Admin display; // reading from admins.dat
	Customer c; 	// writing this struct to customers.dat

	std::fstream file;
	std::fstream cfile;

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

cfile.open("customers.dat", std::ios::out|std::ios::app|std::ios::binary);

// switch case to assign fixed rate for policy type
			switch(policy) {
				case 1:
					c.category = "Comprehensive";
					c.category_rate = 0.055;	
					break;
				case 2:
					c.category = "Third Party, Fire & Theft";
					c.category_rate  = 0.044;  
					break;
				case 3:
					c.category = "Third Party Only";
					c.category_rate = 0.033;  
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
					c.vehicle = "Car";
					c.vehicle_rate = 500.00;  
					break;
				case 2:
					c.vehicle  = "Motorcycle";
					c.vehicle_rate = 250.00;	
					break;
				default:
					std::cout << "\nSorry please choose from option 1 or 2\n";
					goto v_menu;
					break;
			}

			std::cout << "\nWhen would you like the policy to start? (dd/mm/yyyy) \n";
			std::cin >> c.policy_date;

			std::cout << "\nEnter car/motorcycle details: (Make, Model & Year) \n";
			std::cin.ignore();
			std::cin.getline(c.vehicle_details, 50);

			std::cout << "\nHow much is the vehicle worth? \n";
			std::cin >> c.sum_insured;

// calculate annual, monthly and fortnightly prices
 c.annual = (c.sum_insured * c.category_rate) + c.vehicle_rate;
 c.monthly = c.annual / 12;
 c.fortnightly = (c.annual / 52) * 2;

cfile.write(reinterpret_cast<char*>(&c), sizeof(c)); // write new policy info
cfile.close();

return c;
}

// pass through p from new policy to here
void displayQuote(struct Customer c) {
	
// read back info from customers file
			std::cout << "\n\t\tYOUR INSURANCE POLICY QUOTE";
			line();
			std::cout << "\n\n";
			std::cout << "Your chosen policy: " << c.category << " " << c.vehicle << std::endl;
			std::cout << "\n$" << c.fortnightly<< " per fortnight" << std::endl;
			std::cout << "...or $" << c.monthly << " per month" << std::endl;
			std::cout << "...or $" << c.annual << " per year" << std::endl;

// end of function
}

int registerPolicy() {
Customer c; // new struct to be passed from newPolicy to displayQuote

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
						c = newPolicy();
						displayQuote(c);
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
				displayPolicy(username, password);
			} else {
				std::cout << "\nSorry please type 'y' for yes or 'n' for no " << std::endl;
				goto start;
			}

			return answer2;
}

// DISPLAY ERRORS: dob, policy number, make model and year, registration number
void displayPolicy(char username[], char password[]) {
	srand(time(NULL));
	std::fstream file;
	bool flag = false;
	Customer cus;

    file.open("customers.dat", std::ios::in|std::ios::binary|std::ios::beg);

    if (file.is_open()) {

					while(!file.eof()) {	
                        file.read(reinterpret_cast<char*>(&cus), sizeof(cus));

          if ((strcmp(username, cus.user_name) == 0) && (strcmp(password, cus.password) == 0)) {
								
                    std::cout << "\n** Congratulations! This Policy has been registered **\n";
                    line2();

 // generate policy number for reference
                    cus.policynum = rand() % 300 + 100;		// generate random number
                    std::cout<< "Policy Number:  " << cus.policynum << std::endl;
                    std::cout<< "\n~~ Driver's Details ~~  " << std::endl;
                    std::cout<< "Name:  " << cus.first_name << " " << cus.last_name << std::endl;
                    std::cout<< "Gender:  " << cus.gender << std::endl;
                    std::cout<< "Date of birth:  " << cus.birthday << std::endl; // prints email aswell
                    std::cout<< "Email:  " << cus.email << std::endl; 
                    std::cout<< "Contact number:  " << cus.phone << std::endl;

                    std::cout<< "\n~~ Vehicle Details ~~  " << std::endl;	
                    std::cout<< "Make, Model & Year:  " << cus.vehicle_details << std::endl;
                    std::cout<< "Registration Number:  " << cus.rego << std::endl; // prints twice
                    std::cout<< "Vehicle address:  " << cus.address << std::endl; 
                    flag = true;
                    file.close();
                    break;
                    } 
                    else
                            flag = false;
            }

    } else
        std::cout << "\nFile error. Please contact admin\n";

// end of function
}

void renewalInfo() {
	std::cout << "\n\t\tThe Renewal process:";
	line();
	std::cout << "\nSelect which current policy you'd like to renew, confirm your personal details and add payment details." << std::endl;
	std::cout << "\nIf you choose to change policy category(go from comprehensive to third party only), this will affect how much you need to pay\n" << std::endl;

}

// // CHECK THIS
void renewalForm(char username[], char password[]) {
	Customer cus;
	int policy;
	bool flag = false;
	std::fstream file;

	file.open("customers.dat", std::ios::in|std::ios::out|std::ios::binary);

	if(file.is_open()) {
		while(!file.eof()) {
			
			file.read(reinterpret_cast<char*>(&cus), sizeof(Customer));
			position = file.tellg(); 

			if((strcmp(username, cus.user_name) == 0) && (strcmp(password, cus.password) == 0)) {
							std::cout << "\n\t\t**Your current policy**" << std::endl;
							std::cout << "\nDriver's Name:  " << cus.first_name << " " << cus.last_name << std::endl;
							std::cout << "Contact Number:  " << cus.phone << std::endl;
							std::cout << "Policy Type:  " << cus.category << " " << cus.vehicle << std::endl;
							std::cout << "Vehicle Details:  " << cus.vehicle_details << std::endl;

							file.seekp(position-(sizeof(cus)));

							std::cout << "\n\t\tRenewal form\n" << std::endl;
							line();
							std::cout << "\nDriver's First Name:  ";
							std::cin >> cus.first_name;
							std::cout << "\nDriver's Last Name:  ";
							std::cin >> cus.last_name;
							std::cout << "\nContact Number:  ";
							std::cin >> cus.phone;
				p_menu:
							std::cout << "\nChoose a policy category (1.Comprehensive, 2.Third Party, Fire & Theft, 3.Third Party Only):  ";
							std::cin >> policy;

				// switch case to assign fixed rate for policy type
							switch(policy) {
								case 1:
									cus.category = "Comprehensive";
									cus.category_rate = 0.055;	
									break;
								case 2:
									cus.category = "Third Party, Fire & Theft";
									cus.category_rate = 0.044;  
									break;
								case 3:
									cus.category= "Third Party Only";
									cus.category_rate = 0.033;  
									break;
								default:
									std::cout << "\nSorry, please choose from options 1-3\n";
									goto p_menu;
									break;
							}
							std::cout << "\nAdd card number (16 digits, no spaces):  ";
							std::cin >> cus.visa;

							file.write(reinterpret_cast<char*>(&cus), sizeof(Customer));
							flag = false;
                            std::cout << "\nPolicy has been successfully renewed!\n";
							break;
			} else // username check statement
			flag = true;
		} // end of file
	} else // file is not open
			std::cout << "\nFile not found\n";

	if(flag) {
					std::cout << "\nCannot find Customer policy\n";
	}

	file.close();

}


// CLAIMS SCREEN FUNCTION **
int claimForm(struct Admin& a)
{
    Claims info; 
    int c;
    std::fstream file; 

    file.open("claims.dat", std::ios::out | std::ios::app | std::ios::binary);
    
    std::cout << "\n\n\t\tClaims Registration Screen";
    line();

    if(file.is_open())

    {
        //write personal information inside the file 
        std::cout << "\n\n\t\tPersonal Details ";
        line();
        std::cout << "\nFull name of the insured person : ";
        std::cin.ignore();
        std::cin.getline(info.name, 50);

        std::cout << "\nPolicy number : ";
        std::cin >> info.policynum;

        std::cout << "\n\n\t\tIncident details : ";
        line();

        std::cout << "\nDate : ";
        std::cin >> info.date;

        std::cout << "\nTime : ";
        std::cin >> info.time;

        std::cin.ignore();
        std:: cout << "\nDescription of Incident : ";
        std::cin.getline(info.incident, 100);

        std::cout << "\nVehicle Damage : ";
        std::cin.getline(info.damage, 100);

        std::cout << "\n\n\t\tContact details : ";
        line();

        std::cout << "\n\nEmail : ";
        std::cin.getline(info.email, 30);

        std::cout << "\nPhone : ";
        std::cin.getline(info.phone, 14);

    file.write(reinterpret_cast<char*>(&info), sizeof(Claims)); // test that this is writing to the file
    file.close(); 
        std::cout << "\nThank you, your claim is now being processed. We will contact you in 48hrs.\n";
    c = a.claim_counter++;  // for every claim written to file, increase by 1

    } else {
        std::cout << "\nError, claims file not found\n";
    }

return c;

}

// NEW REGISTRATION SCREEN FUNCTION **
void readCustomer()  {
    Customer c;
    std::fstream file;

        // Open the file 
    file.open("customers.dat", std::ios::out | std::ios::app | std::ios::binary);

    if(file.is_open())
    {
  
            // write the personal information inside 
        std::cout << "\n\t\tEnter your personal details below : ";
        line(); 

        std::cout << "\nEnter first name : ";
        std::cin >> c.first_name;

        std::cout << "Enter last name : ";
        std::cin >> c.last_name;

        std::cin.ignore(); // switching to different getline input

        std::cout << "Enter username : ";
        std::cin.getline(c.user_name, 30);  // changed to char [] for comparison

        std::cout << "Enter password : ";
        std::cin.getline(c.password, 30); // changed to char [] for comparison

        std::cout << "Enter gender : ";
        std::cin >> c.gender;

        std::cout << "Enter date of birth : (dd/mm/yyyy) ";
       std::cin >> c.birthday;

        std::cout << "Enter email address : ";
       std::cin >> c.email;

        std::cout << "Enter contact number : ";
       std::cin >> c.phone;

        std::cout << "Enter vehicle registration number : ";
       std::cin >> c.rego;

        std::cout << "Enter licence number : ";
       std::cin >> c.licence;
       
        std::cin.ignore(); // switching to different getline input
        std::cout << "Enter address : ";
        std::cin.getline(c.address, 45);

       } 
    
// converting above info to binary in the file
    file.write(reinterpret_cast<char*>(&c), sizeof(c));

    file.close(); // closing the file 
}


// ADMIN SCREEN **
// function definitions below...
void adminScreenMenu() {
	int option;

menu:
	std::cout << "\n\n\t\tWELCOME TO THE ADMIN SCREEN";
	line();
	std::cout << "\n\n";
	std::cout << "1. Customer Report\n";
	std::cout << "2. Weekly Claims Report\n";
	std::cout << "3. Weekly Renewals Report\n";
	std::cout << "4. Weekly New Registrations Report\n";
	std::cout << "5. Update policy/discount information\n";
	std::cout << "6. Log out\n";
	std::cout << "Please select an option:  ";
	std::cin >> option;
   
	switch (option) {
	case 1:
    customerReport();
		goto menu;
		break;
	case 2:
    claimsReport(count); 
		goto menu;
		break;
	case 3:
    renewalsReport(); 
		goto menu;
		break;
	case 4:
    newRegReport();
		goto menu;
		break;
	case 5:
    updateMenu();  // pick an option for which section admin would like to update
    goto menu;
		break;
	case 6:
		std::cout << "\nYou have been logged out\n";
		menu();
		break;
	default:
		std::cout << "Sorry, please pick from options 1-6";
		goto menu;
		break;
	}

}

void customerReport() {
const int SIZE = 20;
char search_name[20];
Customer all_customers[SIZE];
std::fstream file;
bool flag = false;

  std::cout << "\n\t\tCUSTOMER REPORT";
  line();
  std::cout << "\nEnter Customer first name or last name:  " << std::endl;
  std::cin.ignore();
  std::cin.getline(search_name, 20);

 
  file.open("customers.dat", std::ios::in|std::ios::binary);

  if (file.is_open()) {

    while (!file.eof()) {

      file.read(reinterpret_cast<char*>(all_customers), SIZE * sizeof(Customer));

    for(int i = 0; i < SIZE; i++) {
        if((strcmp(search_name, all_customers[i].first_name) == 0) || (strcmp(search_name, all_customers[i].last_name) == 0)) 
    {
        std::cout << "\n1 Customer found" << std::endl;
        std::cout << "\nFirst name: " << all_customers[i].first_name << std::endl;
        std::cout << "Last name: " << all_customers[i].last_name << std::endl;
        std::cout << "Username: " << all_customers[i].user_name<< std::endl;
        std::cout << "Password: " << all_customers[i].password << std::endl;
        std::cout << "Gender: " << all_customers[i].last_name << std::endl;
        std::cout << "Date of birth: " << all_customers[i].birthday << std::endl;
        std::cout << "Email: " << all_customers[i].email << std::endl;
        std::cout << "Phone number: " << all_customers[i].phone << std::endl;   // fix error displaying
        std::cout << "Vehicle Registration: " << all_customers[i].rego << std::endl;  // fix error displaying
        std::cout << "Drivers licence number: " << all_customers[i].licence << std::endl;
        std::cout << "Home Address: " << all_customers[i].address << std::endl;  // fix error displaying

        flag = true;
        break;
      } else {
          flag = false;
      }
    } // end of loop
    }  // end of file
    file.close();
    } else {
          std::cout << "Error! No file found\n";
    }

if(!flag) {
        std::cout << "\nNo customer found";
}

}

// Error: Does not count the claims at all
void claimsReport(int count) {

  std::cout << "\n\t\tCLAIMS REPORT";
  line();
  std::cout << "\nTotal claims made:  " << count << std::endl;
}

void renewalsReport() {
    Admin a;
  std::cout << "\n\t\tRENEWALS REPORT\n";
  line();
  std::cout << "\nTotal policies renewed:  " << a.renewal_counter<< std::endl;
}

void newRegReport() {
    Admin a;
    std::cout << "\n\t\tNEW REGISTRATIONS REPORT\n";
  line();
  std::cout << "\nTotal new customers registered:  " << a.new_reg_counter << std::endl;
}

// Debug: When new info is published, it overrides all the other default fields to be empty
void updateMenu() {
  std::fstream file;
  Admin a;
  int option;
  char answer;

retry:
  std::cout << "\nWhich section would you like to update?\n";
  line2();
  std::cout << "\n1. New signup discount\n";
	std::cout << "2. Multi-policy discount\n";
	std::cout << "3. Renewal Discount\n";
	std::cout << "4. Review Discount\n";
	std::cout << "5. Introduce friend/family discount\n";
	std::cout << "6. Policy Descriptions\n";
	std::cout << "7. Go back to Admin Screen\n";
	std::cout << "Please select an option:  ";
	std::cin >> option;

file.open("admins.dat", std::ios::out|std::ios::binary);
  if(file.is_open()) {

    switch(option) {
      case 1:
        std::cout << "\nPlease type new description here...press enter when finished\n";
        std::cin.ignore();
        std::cin.getline(a.discount_signup, 220);
        break;
      case 2:
        std::cout << "\nPlease type new description here...press enter when finished\n";
        std::cin.ignore();
        std::cin.getline(a.discount_multi, 292);
        break;
      case 3:
        std::cout << "\nPlease type new description here...press enter when finished\n";
        std::cin.ignore();
        std::cin.getline(a.discount_renewal, 145);
        break;
      case 4:
        std::cout << "\nPlease type new description here...press enter when finished\n";
        std::cin.ignore();
        std::cin.getline(a.discount_review, 286);
        break;
      case 5:
        std::cout << "\nPlease type new description here...press enter when finished\n";
        std::cin.ignore();
        std::cin.getline(a.discount_friend, 295);
        break;
      case 6:
        std::cout << "\nPlease type new description here...press enter when finished\n";
        std::cin.ignore();
        std::cin.getline(a.policy_description, 355);
        break;
      case 7:
        adminScreenMenu();
        break;
      default:
        std::cout << "\nSorry, please pick from options 1-7\n";
        goto retry;
        break;
    }
// Debug: When new info is published, it overrides all the other default fields to be empty
publish:
    std::cout << "Would you like to publish these changes? (y/n)  ";
    std::cin >> answer;

    if (answer == 'y') {
      file.write(reinterpret_cast<char*>(&a), sizeof(Admin));   
      file.close();
    } else if (answer == 'n') {
      file.close();
      std::cout << "\nChanges discarded\n";
      goto retry;
    } else {
      std::cout << "\nSorry please type y for yes or n for no\n";
      goto publish;
    }
  }

}