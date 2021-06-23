#include <iostream>

/* Claim registration screen 

Policy number
Full name
Date 
Time of incident 
Description 
Complaint details 
Contact details 
Claim data needs to be managed by corresponding files
*/
void line() {

    std::cout << "\n\n";
    for (int i = 0; i < 40; i++)
    {
        std::cout << "~";
    }
    std::cout << "\n\n";
}

int main ()
{
    std::cout << "Claims Registration Screen";
    line();

    std::cout << "Insured Name ";
}
