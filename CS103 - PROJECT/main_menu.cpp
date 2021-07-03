#include <iostream>
#include <string>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures

// declare global variables 
int user_choice, choice2;
char email[30], username[30], password[30], admin_n[30], admin_p[30];
bool cflag, aflag;
const int SIZE = 20;

// main function below...
int main ()
{
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
    Customer c;

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
retry:
        std::cout << "\nRegister as new customer / Customer login" << std::endl;
        line2();
        std::cout << "\nPress 1 to REGISTER or 2 to LOG IN:   ";
        std::cin >> choice2;

        if (choice2 == 1) {

            readCustomer(c);
            customerLogin();
            cflag = customerValidation(username, password);
            cLoginOutcome(cflag);
            goto start;

        } else if (choice2 == 2) {

        customerLogin();
        cflag = customerValidation(username, password);
        cLoginOutcome(cflag);
        goto start;

        } else {
            std::cout << "\nWhat was that? Please choose option 1 or 2\n" << std::endl;
            goto retry;
        }
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