#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures


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
