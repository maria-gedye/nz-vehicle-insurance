// generic functions
void line(); // add 10 more symbols
void line2(); // x3 line()

// 1. Introduction Screen
void adminSetup();
void menu();
void customerLogin();
void adminLogin();
void contact();
bool customerValidation(char[], char[]);
bool adminValidation(char[], char[]);
void cLoginOutcome(bool);
void aLoginOutcome(bool);

// 2. Customer Registration Screen
void readCustomer();

// 3. Customer Screen
void customerScreenMenu();
void benefitsMenu();
void search_read();

// 4. Insurance Policy Screen
// void newPolicy(struct Customer&);
// void displayQuote(struct Customer&); 
// int request(struct Customer&);

// 5. Claim Registration Screen
int claimForm(struct Admin&);

// 6. Renewal Screen
// void renewalInfo();
// void renewalForm(int, char[]); // 

// 7. Admin Screen
void adminScreenMenu();
void customerReport();
void claimsReport(); // needs debugging  
void renewalsReport(); // setup counters to work for these 3 reports
void newRegReport();
void updateMenu(); // needs debugging

// 8. Policy Registation Screen
// void displayPolicy();  // needs debugging