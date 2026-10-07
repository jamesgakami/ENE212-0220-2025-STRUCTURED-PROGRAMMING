#include <stdio.h>
#include <stdlib.h>

/*PSEUDOCODE
START
    DECLARE Number, i, regNumber, marks as integer
    DECLARE name as string
    DECLARE grade as character
    DECLARE status as string
    DECLARE bucket as integer

    OUTPUT "Enter number of students: "
    INPUT N

    FOR i = 1 do
        OUTPUT "Enter Registration Number: "
        INPUT regNo
        OUTPUT "Enter Name: "
        INPUT name
        OUTPUT "Enter Marks: "
        INPUT marks

        //do grading using the switch case
        bucket = marks / 10
        SWITCH category
            CASE 10:
            CASE 9:
            CASE 8:
            CASE 7:
                grade = 'A'
                BREAK
            CASE 6:
                grade = 'B'
                BREAK
            CASE 5:
                grade = 'C'
                BREAK
            CASE 4:
                grade = 'D'
                BREAK
            DEFAULT:
                grade = 'F'
        END SWITCH

        // categorize as either pass or fail
        IF marks >= 40 then
            status = "PASS"
        ELSE
            status = "FAIL"
        END IF

        // ----- Display formatted info -----
        OUTPUT "--------------------------------"
        OUTPUT "        STUDENT INFORMATION"
        OUTPUT "--------------------------------"
        OUTPUT "Registration No: ", regNo
        OUTPUT "Name: ", name
        OUTPUT "Marks: ", marks
        OUTPUT "Grade: ", grade
        OUTPUT "Status: ", status
        OUTPUT "--------------------------------"
    END FOR
END*/


int main(void)
{
    //defining the values we will be using
    int Number;
    int i;
    int regNumber;
    int marks;
    int category;
    char name[50];
    char grade;
    const char *status;

    printf("Enter number of students: ");
    scanf("%d", &Number);

    //inputing the student information
    for (i = 1; i <= Number; i++)
    {
        printf("\n--- Student %d ---\n", i);

        printf("Enter Registration Number: ");
        scanf("%d", &regNumber);

        printf("Enter Name: ");
        scanf("%49s", name);

        printf("Enter Marks: ");
        scanf("%d", &marks);

        //grading the student marks
        category = marks / 10;

        switch (category)
        {
            case 10:
            case 9:
            case 8:
            case 7:
                grade = 'A';
                break;
            case 6:
                grade = 'B';
                break;
            case 5:
                grade = 'C';
                break;
            case 4:
                grade = 'D';
                break;
            default:
                grade = 'F';
                break;
        }

        //assigning pass or fail
        if (marks >= 40)
        {
            status = "PASS";
        }
        else
        {
            status = "FAIL";
        }

        //displaying final student information
        printf("\n--------------------------------\n");
        printf("        STUDENT INFORMATION\n");
        printf("--------------------------------\n");
        printf("Registration No: %d\n", regNumber);
        printf("Name: %s\n", name);
        printf("Marks: %d\n", marks);
        printf("Grade: %c\n", grade);
        printf("Status: %s\n", status);
        printf("--------------------------------\n");
    }

    return 0;
}
