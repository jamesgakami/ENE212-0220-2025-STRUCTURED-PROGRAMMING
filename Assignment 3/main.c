#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
PSEUDOCODE

ACCOUNT VARIABLES:
    balance = 1000.00 (Initial balance)
    correct_pin = "1234" (Stored PIN)

FUNCTION login():
    attempts = 0
    WHILE attempts < 3:
        PRINT "Enter PIN: "
        READ entered_pin
        IF entered_pin == correct_pin:
            RETURN True
        ELSE:
            attempts = attempts + 1
            PRINT "Incorrect PIN. Attempts remaining: ", (3 - attempts)
    END WHILE
    PRINT "Maximum attempts exceeded. Access Denied."
    RETURN False

FUNCTION checkBalance():
    PRINT "Your current balance is: ksh", balance

FUNCTION deposit(amount):
    IF amount > 0:
        balance = balance + amount
        PRINT "Deposit successful. New balance: ksh", balance
    ELSE:
        PRINT "Invalid amount. Deposit must be a positive number."

FUNCTION withdraw(amount):
    IF amount > 0:
        IF amount <= balance:
            balance = balance - amount
            PRINT "Withdrawal successful. New balance: ksh", balance
        ELSE:
            PRINT "Insufficient funds."
    ELSE:
        PRINT "Invalid amount. Withdrawal must be a positive number."

MAIN FUNCTION:
    IF login() == True:
        choice = 0
        WHILE choice != 4:
            PRINT "1. Balance Inquiry"
            PRINT "2. Deposit"
            PRINT "3. Withdraw"
            PRINT "4. Exit"
            PRINT "Enter choice: "
            READ choice

            SWITCH choice:
                CASE 1:
                    CALL checkBalance()
                CASE 2:
                    PRINT "Enter deposit amount: "
                    READ amount
                    CALL deposit(amount)
                CASE 3:
                    PRINT "Enter withdrawal amount: "
                    READ amount
                    CALL withdraw(amount)
                CASE 4:
                    PRINT "Exiting. Thank you!"
                DEFAULT:
                    PRINT "Invalid choice. Try again."
    ELSE:
*/

// Account variables to maintain state across functions
double balance = 1000.00; // Starting with a default balance
const char* CORRECT_PIN = "1234"; // Correct ATM PIN

// Functions
bool login();
void checkBalance();
void deposit(double amount);
void withdraw(double amount);
void displayMenu();

// Login / PIN Verification Function
bool login() {
    char entered_pin[10]; //[10] used to make the program flexible for 9 digits ,without crashing
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    while (attempts < MAX_ATTEMPTS) {
        printf("Please enter your 4-digit PIN: ");
        scanf("%9s", entered_pin); // the 9 tells the program to read only nine digits snce 0 is a null digit

        // Check if entered PIN matches
        int match = 1;
        for (int i = 0; i < 4; i++) {
            if (entered_pin[i] != CORRECT_PIN[i]) {
                match = 0;
                break;
            }
        }
        // Check for null terminator to ensure exactly 4 digits (optional but good practice)
        if (entered_pin[4] != '\0') {
            match = 0;
        }

        if (match) {
            printf("Login successful!\n\n");
            return true;
        } else {
            attempts++;
            printf("Incorrect PIN. You have %d attempt(s) left.\n", MAX_ATTEMPTS - attempts);
        }
    }
    return false;
}

// Show ATM Menu
void displayMenu() {
    printf("===================================\n");
    printf("              ATM MENU             \n");
    printf("===================================\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("===================================\n");
}

// Handle User Choice - Balance
void checkBalance() {
    printf("Your current balance is: ksh%.2f\n", balance);
}

// Handle User Choice - Deposit & Validation
void deposit(double amount) {
    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }
    balance += amount;
    printf("Deposit successful. Your new balance is: ksh%.2f\n", balance);
}

// Handle User Choice - Withdraw & Validation
void withdraw(double amount) {
    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    }
    if (amount > balance) {
        printf("Error: Insufficient funds. Your current balance is ksh%.2f\n", balance);
        return;
    }
    balance -= amount;
    printf("Withdrawal successful. Your new balance is: ksh%.2f\n", balance);
}


int main() {
    int choice;
    double amount;

    printf("Welcome to the Simulated ATM System\n");
    printf("-----------------------------------\n");

    // Login
    if (login()) {
        // Repeat Until Exit
        do {
            displayMenu(); // Requirement 2
            printf("Enter your choice (1-4): ");
            scanf("%d", &choice);

            // Handling User Choice
            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    printf("Enter amount to deposit: $");
                    scanf("%lf", &amount);
                    deposit(amount);
                    break;
                case 3:
                    printf("Enter amount to withdraw: $");
                    scanf("%lf", &amount);
                    withdraw(amount);
                    break;
                case 4:
                    printf("Exiting the system. Thank you for using our ATM!\n");
                    break;
                default:
                    printf("Invalid choice. Please select a number between 1 and 4.\n");
            }
            printf("\n"); // blank line for readability before looping again
        } while (choice != 4);
    } else {
        printf("Access Denied. Exiting program.\n");
    }

    return 0;
}



