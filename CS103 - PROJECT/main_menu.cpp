#include <iostream>
#include <string>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures

// declare global variables 
int user_choice, choice2;
char email[30], username[30], password[30], admin_n[30], admin_p[30];
bool cflag, aflag;

// main function below...
int main ()
{
    menu(); // calling the menu function 

// end of main function
    return 0;
 }

// function definitions below
 void line()
{
    std::cout << "\n\t\t~~~~~~~~~~~~~~~~~";
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
        std::cout << "\nPress 1 to REGISTER or 2 to LOG IN:   ";
        std::cin >> choice2;

        if (choice2 == 1) {

            readCustomer(c);
            std::cin.ignore();
            Customer_Login();
            cflag = customer_validation(username, password);
            loginStatus(cflag);
            goto start;

        } else if (choice2 == 2) {

        Customer_Login();
        cflag = customer_validation(username, password);
        loginStatus(cflag);
        goto start;

        } else {
            std::cout << "\nWhat was that? Please choose option 1 or 2\n" << std::endl;
            goto retry;
        }
        break;

        case 2:
        Admin_login();
        // aflag = admin_validation(admin_n, admin_p);
        // go to admin screen
        break;

        case 3:
        Contact();
        goto start;
        break;

        default:
        std::cout << "Please input a valid option \n\n";
        goto start;
    }
}

void Customer_Login() // login details 
{
std::cin.ignore();
std::cout << "\nLogin to MyEvolve Insurance";
std::cout << "\n\nEmail or Username : ";
std::cin.getline(username, 30);
std::cout << "\nPassword : ";
std::cin.getline(password, 30);

}

void Admin_login() // admin details
{
std::cin.ignore();
std::cout << "\nLogin to Evolve Insurance Admin";
std::cout << "\n\nEmail or Username : ";
std::cin.getline(admin_n, 30);
std::cout << "\nPassword : ";
std::cin.getline(admin_p, 30);

}

void Contact() // contact details 
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

bool customer_validation(char field1[30], char field2[30]) {
    Customer c;
    std::fstream file;
    bool flag;

    file.open("customers.dat", std::ios::in|std::ios::binary);

    if (file.is_open()) {
        while (!file.eof()) {
            file.read(reinterpret_cast<char*>(&c), sizeof(c));

            // compare user input with whats stored in the customers file
            if ((strcmp(field1, c.email) == 0) || (strcmp(field1, c.user_name) == 0)) {
                if (strcmp(field2, c.password) == 0)
                flag = true;
                break;
            } else
            flag = false;
        }
    } else
    std::cout << "\nFile error. Please contact admin\n";

    return flag;
}

// bool admin_validation(char field1[30], char field2[30]) {
//     Admin a; // need to create this
//     std::fstream file;
//     bool flag;

//     file.open("admins.dat", std::ios::in|std::ios::binary); // need to create this

//     if (file.is_open()) {
//         while (!file.eof()) {
//             file.read(reinterpret_cast<char*>(&a), sizeof(a));

//             // compare user input with whats stored in the customers file
//             if ((strcmp(field1, a.username) == 0) && (strcmp(field2, a.password) == 0)) {
//                 flag = true;
//                 break;
//             } else
//             flag = false;
//         }
//     } else
//     std::cout << "\nCannot find file\n";

//     return flag;
// }

void loginStatus(bool f) {
    int count = 0;

start:
    if (f) {
        std::cout << "\n** Log in successful **" << std::endl;
        customerScreenMenu();
    } else {
        std::cout << "\nSorry, username or password was wrong. Press enter to try again" << std::endl; 
        count++;
        if (count < 3) {
        Customer_Login();
        f = customer_validation(username, password);
        goto start;
        }
        else 
        std::cout << "\nSorry, there have been too many unsuccessful attempts. Please wait before trying again" << std::endl; 

    }
// end of function
}