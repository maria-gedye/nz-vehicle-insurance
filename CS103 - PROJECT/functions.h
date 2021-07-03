// generic functions
void line(); // add 10 more symbols
void line2(); // x3 line()

// 1. Introduction Screen
void menu();
void customerLogin();
void adminLogin();
void contact();
bool customerValidation(char[], char[]);
bool adminValidation(char[], char[]);
void cLoginOutcome(bool);
void aLoginOutcome(bool);

// 2. Customer Registration Screen
void readCustomer(struct Customer&);

// 3. Customer Screen
void customerScreenMenu();
void benefitsMenu();

// 4. Insurance Policy Screen
struct Policy newPolicy(struct Policy);
void displayQuote(struct Policy); 
int request(struct Policy&, struct Customer&);

// 5. Claim Registration Screen
void claimForm(struct Admin&);

// 6. Renewal Screen
// to be defined
void renewalInfo();
void renewalForm();

// 7. Admin Screen
void adminSetup();
void adminScreenMenu();
void customerReport(struct Admin&);
void claimsReport(struct Admin&);
void renewalsReport(struct Admin&); 
void newRegReport(struct Admin&);
void updateMenu(struct Admin&); 

// 8. Policy Registation Screen
void displayPolicy(struct Policy&, struct Customer&);