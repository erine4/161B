#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//constant variables
const double planS = 35.00;
const double planM = 50.00;
const double planL = 70.00;
const double planUnlimited = 75.00;
const double overage = 15.00;
const int planSGB = 2;
const int planMGB = 4;
const int planLGB = 8;

//function declarations
double readUserInput(double);
char readUserChar(char);
double calculateOverageCharge(char, double);
void printPlanCharge(char);
void upgradeSave(double);
double totalCost(char, double);

int main()  {
    //declare variables
    char userChar;
    double userInput = 0.0;
    
    //setprecision
    cout << fixed << setprecision(2);

    //display welcome message
    cout << "***** Welcome to Mint Mobile *****" << endl << endl;

    //display header message
    cout << "Let's calculate your monthly bill!" << endl << endl;
    cout << "S: 2GB $35/mo*" << endl;
    cout << "M: 4GB $50/mo*" << endl;
    cout << "L: 8GB $70/mo*" << endl;
    cout << "U: Unlimited $75/mo*" << endl << endl;
    cout << "*Overage charges $15 per GB" << endl << endl;

    //Display input message
    cout << "Which plan are you on? (S/M/L/U) : ";
    cin >> userChar;
    userChar = readUserChar(userChar);

    cout << endl << "How many GB did you use last month? ";
    cin >> userInput;
    userInput = readUserInput(userInput);
    cout << endl;

    //display plan charges
    printPlanCharge(userChar);
    
    //overage charges
    if (calculateOverageCharge(userChar, userInput) > 0)    {
        cout << "Overage charges: $" << calculateOverageCharge(userChar,userInput) << endl;
    }

    //total cost
    cout << "Total cost: $" << totalCost(userChar, userInput) << endl;

    upgradeSave(totalCost(userChar, userInput));

    //Display end message
    cout << endl << "Thank you for choosing Mint Mobile." << endl;
    cout << "Goodbye!" << endl;

    return 0;
}

double readUserInput (double userInput) {
    userInput = ceil(userInput);

    while (userInput < 0) {
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       cout << "Bad input! Please enter an integer greater than or equal to 0: ";
       cin >> userInput;
    }

    return userInput;
}

char readUserChar (char userChar) {
    userChar = toupper(userChar);

    while ((userChar != 'S')  && (userChar != 'M')
        && (userChar != 'L') && (userChar != 'U')) {
       cin.clear();
       cin.ignore();
       cout << "Invalid option! Choose S, M, L, U: ";
       cin >> userChar;
    }

    return userChar;
}

double calculateOverageCharge (char userChar, double userInput)   {
    double overageCharge = 0.00;
    userChar = toupper(userChar);
    userInput = ceil(userInput);

    if (userChar == 'S')    {
        if (userInput > planSGB)    {
            overageCharge = overage * (userInput - planSGB);
        }
    }

    else if (userChar == 'M')    {
        if (userInput > planMGB)    {
            overageCharge = overage * (userInput - planMGB);
        }
    }

    else if (userChar == 'L')   {
        if (userInput > planLGB)    {
            overageCharge = overage * (userInput - planLGB);
        }
    }

    return overageCharge;
}

double totalCost (char userChar, double userInput)  {
    double totalCost = 0.00;
    userChar = toupper(userChar);
    userInput = ceil(userInput);

    if (userChar == 'S')    {
        totalCost = planS + calculateOverageCharge(userChar, userInput);
    }

    if (userChar == 'M')   {
        totalCost = planM + calculateOverageCharge(userChar, userInput);
    }

    if (userChar == 'L')   {
        totalCost = planL + calculateOverageCharge(userChar, userInput);
    }

    if (userChar == 'U')   {
        totalCost = planUnlimited;
    }

    return totalCost;
}

void printPlanCharge (char userChar)    {
    userChar = toupper(userChar);
    
    cout << "Plan charges: $";

    if (userChar == 'S')    {
        cout << planS << endl;
    }

    if (userChar == 'M')    {
        cout << planM << endl;
    }

    if (userChar == 'L')    {
        cout << planL << endl;
    }

    if (userChar == 'U')    {
        cout << planUnlimited << endl;
    }
}

void upgradeSave(double totalCost)   {

    if (totalCost > 75) {
        cout << endl << "Upgrade to Unlimited and save $" << (totalCost - planUnlimited) 
             << "!" << endl;
    }
}

