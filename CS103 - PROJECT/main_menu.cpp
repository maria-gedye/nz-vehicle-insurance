#include <iostream>
#include <string>

// declare variables 
int user_choice;
std::string username, password, admin_n, admin_p;

//define functions 
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

int main ()
{
    for(int i = 0; i < 3; i++) // for loop to continue displaying the menu once the option has been executed 
    {

    menu(); // calling the menu function 

    switch(user_choice) // switch case for the implementation of the appropriate menus 
    {
        case 1:
        Customer_Login();
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
}