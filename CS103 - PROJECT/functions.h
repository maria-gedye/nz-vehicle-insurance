// generic functions
void line();

// 1. Introduction Screen
void menu();
void Customer_Login();
void Admin_login();
void Contact();
bool validation(std::string, std::string);

// 2. Customer Registration Screen

// 3. Customer Screen
void customerScreenMenu();
void benefitsMenu();

// 4. Insurance Policy Screen
struct Policy newPolicy(struct Policy);
void displayQuote(struct Policy); 
int request(struct Policy);

// 5. Claim Registration Screen
// 6. Renewal Screen
// 7. Admin Screen
// 8. Policy Registation Screen

// to be defined
void displayPolicy(struct Policy);
void renewalInfo();
void renewalForm();