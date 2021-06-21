// Customer_Screen_LoggedIn.cpp : 
//3.	Customer screen should include:
//•	A menu contains the following option :
//-Policy and insurance application process(see Task 4),
//-claim(See task 5),
//-renewal(See task 6),
//-benefits of NZ insurance
//•	 Benefits of NZ insurance should include :
//-New sign - up discounts
//- Multi policy discount
//- Renewal discount
//- discount for reviewing the insuranceand introducing friends or family discount.


#include <iostream>
#include <fstream>

void line();

int main()
{
	int option;

	std::cout << "\n\nWELCOME TO THE CUSTOMER SCREEN\n";
	line();
	std::cout << "\n\n";
	menu:
	std::cout << "1. Benefits of insurance\n";
	std::cout << "2. New policy application\n";
	std::cout << "3. Renew a policy\n";
	std::cout << "4. Make a claim\n";
	std::cout << "5. Log out\n";
	std::cout << "Please select an option:  \n";
	std::cin >> option;
   
	switch (option) {
	case 1:
		benefitsMenu();
		goto menu;
		break;
	case 2:
		newPolicy();
		displayPolicy();
		goto menu;
		break;
	case 3:
		renewalInfo();
		renewalForm();
		goto menu;
		beak;
	case 4:
		// link to other cpp file;
		goto menu;
		break;
	case 5:
		std::cout << "\nYou have been logged out\n";

	}

}

void line() {
	for (int i = 0; i < 40; i++) {
		std::cout << '~';
	}
}