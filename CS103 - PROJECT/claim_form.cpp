#include <iostream>
#include <string.h>
#include <fstream>
#include "functions.h"  // import function prototypes
#include "structures.h"  // import structures


void claimForm(struct Admin& a)
{
    Claims info; 
    std::fstream file; 
    file.open("claims.dat", std::ios::out | std::ios::app | std::ios::binary);
    
    std::cout << "\t\tClaims Registration Screen";
    line();

    if(file.is_open())

    {
        //write personal information inside the file 
        std::cout << "\n\nPersonal Details ";
        line();
        std::cout << "\nFull name of the insured person : ";
        std::cin >> info.name;

        std::cout << "\nPolicy number : ";
        std::cin >> info.policynum;

        std::cout << "\n\n\t\tIncident details : ";
        line();

        std::cout << "\nDate : ";
        std::cin >> info.date;

        std::cout << "\nTime : ";
        std::cin >> info.time;

        std:: cout << "\nDescription of Incident : ";
        std::cin >> info.incident;

        std::cout << "\nVehicle Damage : ";
        std::cin >> info.damage;

        std::cout << "\n\n\t\tContact details : ";
        line();

        std::cout << "\n\nEmail : ";
        std::cin >> info.email;

        std::cout << "\nPhone : ";
        std::cin >> info.ph;

    file.write(reinterpret_cast<char*>(&info), sizeof(Claims)); // test that this is writing to the file
    file.close(); 

    a.claim_counter++;  // for every claim written to file, increase by 1

    } else {
        std::cout << "\nError, claims file not found\n";
    }

}
