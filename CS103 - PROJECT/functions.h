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
int request(struct Policy);
void displayPolicy(struct Policy);

// 5. Claim Registration Screen
// 6. Renewal Screen

// 7. Admin Screen
void adminSetup();
void adminScreenMenu();

// 8. Policy Registation Screen

// to be defined
void renewalInfo();
void renewalForm();