#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures

int main()
{
    Customer c;
    std::fstream file;
        // Open the file 
    file.open("customer_registration.dat", std::ios::out | std::ios::app | std::ios::binary);

    if(file.is_open())
    {
        for(int i = 0; i < 1; i++)
        {
            // write the personal information inside 
        std::cout << "\nEnter your personal details below : ";
        line(); 

        std::cout << "Enter first name : ";
        std::cin >> c.first_name;

        std::cout << "Enter last name : ";
        std::cin >> c.last_name;

        std::cout << "Enter username : ";
        std::cin >> c.user_name;

        std::cout << "Enter password : ";
        std::cin >> c.password;

        std::cout << "Enter gender : ";
        std::cin >> c.gender;
        
        std::cout << "Enter date of birth : (dd/mm/yyyy) ";
        std::cin >> c.birthday;

        std::cout << "Enter email address : ";
        std::cin >> c.email;

        std::cout << "\nEnter contact number : ";
        std::cin >> c.phone;

        std::cout << "Enter registration number : ";
        std::cin >> c.rego;

        std::cout << "Enter licence number : ";
        std::cin >> c.licence;
        
        std::cout << "Enter address : ";
        std::cin >> c.address;

        //storing and formatting the file
        file << c.first_name << "\n";
        file << c.last_name << "\n";
        file << c.user_name << "\n";
        file << c.password << "\n";
        file << c.birthday << "\n";
        file << c.email << "\n";
        file << c.phone << "\n";
        file << c.rego << "\n";
        file << c.licence << "\n";
        file << c.address << "\n";
       } 
    }
    file.close(); // closing the file 
}

void line() {

    std::cout << "\n\n";
    for (int i = 0; i < 40; i++)
    {
        std::cout << "~";
    }
    std::cout << "\n\n";
}