#include <iostream>
#include <string.h>
#include <fstream>

struct claims{ // create structure to store the information 
    
    char fname[20], lname[20], description[100], damage[100], email[30]; // insured person details 
    int policynum, ph; 
    std::string address, time, date; // incident details 

    // driver details 'd' - driver
    char dfn[30], dln[30], ddob[15], demail[30], dlicence;
    int dph;
    std::string daddress; 
 
};

// declare functions
void line();

int main ()
{
    claims info; 
    std::fstream file; 
    file.open("claimsform.dat", std::ios::out | std::ios::app | std::ios::binary);
    
    std::cout << "Claims Registration Screen";
    line();

    if(file.is_open())

    {
        //write personal information inside the file 
        std::cout << "\n\nPersonal Details ";
        line();
        std::cout << "\nFirst name of the insured person : ";
        std::cin >> info.fname;

        std::cout << "\nLast name of the insured person : ";
        std::cin >> info.lname;

        std::cout << "\nPolicy number : ";
        std::cin >> info.policynum;

        std::cout << "\n\nContact details : ";
        line();

        std::cout << "\n\nEmail : ";
        std::cin >> info.email;

        std::cout << "\nPhone : ";
        std::cin >> info.ph;

        std::cout << "\nAddress : ";
        std::cin >> info.address;

        std::cout << "\n\nDriver details : ";
        line();

        std::cout << "\nFirst name : ";
        std::cin >> info.dfn;

        std::cout << "\nLast name :";
        std::cin >> info.dln;

        std::cout << "\nDate of birth : ";
        std::cin >> info.ddob;

        std::cout << "\nPhone : ";
        std::cin >> info.dph;

        std::cout << "\nEmail : ";
        std::cin >> info.demail;

        std::cout << "\nAddress : ";
        std::cin >> info.daddress;

        std::cout << "\nLicence : eg. Learners/Restricted/Full (L/R/F)\n";
        std::cin >> info.dlicence;

        std::cout << "\n\nIncident details : ";
        line();

        std::cout << "\nDate : ";
        std::cin >> info.date;

        std::cout << "\nTime : ";
        std::cin >> info.time;

        std:: cout << "\nDescription of Incident : ";
        std::cin >> info.description;

        std::cout << "\nVehicle Damage : ";
        std::cin >> info.damage;

        // storing and formatting the data into the file 

        file << info.fname << "\n";
        file << info.lname << "\n";
        file << info.policynum << "\n";
        file << info.email << "\n"; 
        file << info.ph << "\n";
        file << info.address << "\n";
        file << info.dfn << "\n";
        file << info.dln << "\n";
        file << info.ddob << "\n";
        file << info.dph << "\n";
        file << info.demail << "\n"; 
        file << info.daddress << "\n";
        file << info.dlicence << "\n";
        file << info.date << "\n";
        file << info.time << "\n";
        file << info.description << "\n";
        file << info.damage << "\n";
            
    }
    

}


void line() {

    std::cout << "\n\n";
    for (int i = 0; i < 40; i++)
    {
        std::cout << "~";
    }
    std::cout << "\n\n";
    }