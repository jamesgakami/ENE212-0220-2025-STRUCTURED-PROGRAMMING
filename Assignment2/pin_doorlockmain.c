#include <stdio.h>
#include <stdlib.h>

/*
 * PSEUDOCODE
 * ----------
 * START
 *   DECLARE pin, choice, attempts = 0, granted = 0 AS integer
 *   DECLARE correctpin = 1234 AS AN integer
 *
 *   WHILE attempts < 3 and granted == 0 DO
 *       OUTPUT "Enter your 4-digit PIN: "
 *       INPUT pin
 *
 *       IF pin < 1000 then
 *           OUTPUT "pin is too short (must be 4 digits)"
 *       ELSE IF pin > 9999 then
 *           OUTPUT "pin is too long (must be 4 digits)"
 *       ELSE IF pin != correctpin then
 *           attempts = attempts + 1
 *           OUTPUT "Incorrect PIN."
 *       ELSE
 *           granted = 1
 *           OUTPUT "Access Granted. Door Unlocked."
 *       END IF
 *   END WHILE
 *
 *   IF granted == 1 then
 *       WHILE choice != 4 do
 *           OUTPUT menu
 *           INPUT choice
 *           SWITCH choice ... end switch
 *       END WHILE
 *   ELSE
 *       OUTPUT "System Locked."
 *       FOR i = 5 OUTPUT "you can try again now"
 *   END IF
 * END
 */

int main(void)
{
    //defining the values we will use
    int pin;
    int choice;
    int attempts = 0;
    int granted = 0;
    int i;
    const int CORRECT_PIN = 1234;

    //limiting the attempts to three
    while (attempts < 3 && granted == 0)
    {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &pin);

        //checking the length of the input pin
        if (pin < 1000)
        {
            printf("PIN is too short (must be 4 digits)\n");
        }
        else if (pin > 9999)
        {
            printf("PIN is too long (must be 4 digits)\n");
        }
        else if (pin != CORRECT_PIN)
        {
            attempts++;
            printf("Incorrect PIN.\n");
            printf("Attempts remaining: %d\n", 3 - attempts);
        }
        else
        {
            granted = 1;
            printf("Access Granted. Door Unlocked.\n");
        }
    }

    //providing the options to select from when the user is granted access
    if (granted == 1)
    {
        choice = 0;
        while (choice != 4)
        {
            printf("\n=== Device Menu ===\n");
            printf("1. Open Door\n");
            printf("2. Change Username\n");
            printf("3. Change PIN\n");
            printf("4. Exit\n");
            printf("Choose an option: ");
            scanf("%d", &choice);

            //The various responses to the chosen option after granting th e user access
            switch (choice)
            {
                case 1:
                    printf("Door is already open.\n");
                    break;
                case 2:
                    printf("Change username feature coming soon.\n");
                    break;
                case 3:
                    printf("Change PIN feature coming soon.\n");
                    break;
                case 4:
                    printf("Exiting system.\n");
                    break;
                default:
                    printf("Invalid option! Please try again.\n");
                    break;
            }
        }
    }
    else
    {
        //locking out user if he/she has had three wrong attempts in entering the pin and providing them with a five second break
        printf("Too many attempts! System Locked.\n");
        printf("System locked! Wait for 5 seconds...\n");

        for (i = 5; i >= 1; i--)
        {
            printf("%d...", i);
        }

        printf("\nYou can try again now.\n");
    }

    return 0;
}

