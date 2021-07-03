#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures

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
    claimsReport(); 
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

void claimsReport() {
  Admin a;
  std::cout << "\n\t\tCLAIMS REPORT";
  line();
  std::cout << "\nTotal claims made:  " << a.claim_counter << std::endl;
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
// Debug: When new info is published the other default fields are empty
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