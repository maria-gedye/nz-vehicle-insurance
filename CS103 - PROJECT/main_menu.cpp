#include <iostream>
#include <string>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures

// declare variables 
int user_choice, count = 0;
std::string username, password, admin_n, admin_p;
bool flag;


int main ()
{
start:
    menu(); // calling the menu function 
    switch(user_choice) // switch case for the implementation of the appropriate menus 
    {
        case 1:
        retry:
        Customer_Login();
        flag = validation(username, password);
        if (flag) {
            std::cout << "\nLog in successful" << std::endl;
            customerScreenMenu();
        } else {
            std::cout << "\nSorry, username or password was wrong" << std::endl; 
            count++;
            if (count < 3)
            goto retry;
            else {
            std::cout << "\nSorry, there have been too many unsuccessful attempts. Please wait before trying again" << std::endl; 
            goto start;
            }
        }
        break;

        case 2:
        Admin_login();
        break;

        case 3:
        Contact();
        break;

        default:
        std::cout << "Please input a valid option ";
    }
 }

// function definitions below
 void line()
{
    std::cout << "\n\t\t~~~~~~~~~~~~~~~~~";
}

void menu() // menu for the user to choose from 
{
    std::cout << "\n\t\tEvolve Insurance";
    line();
    std::cout <<"\n\n";

    std::cout << "\nWelcome, Please Sign In \n";
    std::cout << "\n1. Customer Login/Register ";
    std::cout << "\n2. Adminstrator Login";
    std::cout << "\n3. Evolve Insurance Contact Us";

    std::cout << "\n\nPlease select an option : ";
    std::cin >> user_choice;
}

void Customer_Login() // login details 
{
std::cout << "\nLogin to MyEvolve Insurance";
std::cout << "\n\nEmail or Username : ";
std::cin >> username;
std::cout << "\nPassword : ";
std::cin >> password;

}

void Admin_login() // admin details
{
std::cout << "\nLogin to Evolve Insurance Admin";
std::cout << "\n\nEmail or Username : ";
std::cin >> admin_n;
std::cout << "\nPassword : ";
std::cin >> admin_p;

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

bool validation(std::string a, std::string b) {

}
