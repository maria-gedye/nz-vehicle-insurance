#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures


void readCustomer(struct Customer& c)  {
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
        
        std::cout << "Enter address : ";
        std::cin >> c.address;

        //storing and formatting the file
        // file << c.first_name << "\n";
        // file << c.last_name << "\n";
        // file << c.user_name << "\n";
        // file << c.password << "\n";
        // file << c.birthday << "\n";
        // file << c.email << "\n";
        // file << c.phone << "\n";
        // file << c.rego << "\n";
        // file << c.licence << "\n";
        // file << c.address << "\n";
       } 
    
// converting above info to binary in the file
    file.write(reinterpret_cast<char*>(&c), sizeof(c));

    file.close(); // closing the file 
}
