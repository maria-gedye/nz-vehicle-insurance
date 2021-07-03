#include <iostream>
#include <string>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures

// function definitions below...
void adminScreenMenu() {
	int option;
  struct Admin a;

menu:
	std::cout << "\n\n\t\tWELCOME TO THE ADMIN SCREEN";
	line();
	std::cout << "\n\n";
	std::cout << "1. Generate Customer Report\n";
	std::cout << "2. Weekly Claims Report\n";
	std::cout << "3. Weekly Renewals Report\n";
	std::cout << "4. Weekly New Registrations Report\n";
	std::cout << "5. Update policy/discount information\n";
	std::cout << "6. Log out\n";
	std::cout << "Please select an option:  ";
	std::cin >> option;
   
	switch (option) {
	case 1:
    customerReport(a);
		goto menu;
		break;
	case 2:
    claimsReport(a); 
		goto menu;
		break;
	case 3:
    renewalsReport(a); 
		goto menu;
		break;
	case 4:
    newRegReport(a);
		goto menu;
		break;
	case 5:
    updateMenu(a);  // pick an option for which section admin would like to update
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

void customerReport(struct Admin& a) {
  std::cout << "/n/t/tCUSTOMER REPORT\n";
  line();
  std::cout << "Total customers registered:  " << a.customer_counter << std::endl;

}

void claimsReport(struct Admin& a) {
  std::cout << "/n/t/tCLAIMS REPORT\n";
  line();
  std::cout << "Total claims made:  " << a.claim_counter << std::endl;
}

void renewalsReport(struct Admin& a) {
  std::cout << "/n/t/tRENEWALS REPORT\n";
  line();
  std::cout << "Total policies renewed:  " << a.renewal_counter<< std::endl;
}

void newRegReport(struct Admin& a) {
    std::cout << "/n/t/tNEW REGISTRATIONS REPORT\n";
  line();
  std::cout << "Total new customers registered:  " << a.new_reg_counter << std::endl;
}

void updateMenu(struct Admin& a) {
  std::fstream file;
  

}