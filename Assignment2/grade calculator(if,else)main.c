#include <stdio.h>
#include <stdlib.h>

/*PSEUDOCODE
START
    DECLARE Number, i, regNumber, marks as integer
    DECLARE name as string
    DECLARE grade as character
    DECLARE status as string

    OUTPUT "Enter number of students: "
    INPUT N

    FOR i = 1 TO N DO
        OUTPUT "Enter Registration Number: "
        INPUT regNumber
        OUTPUT "Enter Name: "
        INPUT name
        OUTPUT "Enter Marks: "
        INPUT marks

        //grade the student
        IF marks >= 70 AND marks <= 100 THEN
            grade = 'A'
        ELSE IF marks >= 60 THEN
            grade = 'B'
        ELSE IF marks >= 50 THEN
            grade = 'C'
        ELSE IF marks >= 40 THEN
            grade = 'D'
        ELSE
            grade = 'F'
        END IF

        IF marks >= 40 THEN
            status = "PASS"
        ELSE
            status = "FAIL"
        END IF

        //display student information
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
END
*/

int main(void)
{
    //defining the values we will use
    int Number;
    int i;
    int regNumber;
    int marks;
    char name[50];
    char grade;
    const char *status;

//inputing the number of students in the class
    printf("Enter number of students: ");
    scanf("%d", &Number);

//inputing the students' registration number,name and mark
    for (i = 1; i <= Number; i++)
    {
        printf("\n--- Student %d ---\n", i);

        printf("Enter Registration Number: ");
        scanf("%d", &regNumber);

        printf("Enter Name: ");
        scanf("%49s", name);

        printf("Enter Marks: ");
        scanf("%d", &marks);

        //grading using if and else
        if (marks >= 70 && marks <= 100)
        {
            grade = 'A';
        }
        else if (marks >= 60)
        {
            grade = 'B';
        }
        else if (marks >= 50)
        {
            grade = 'C';
        }
        else if (marks >= 40)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }

        //assigning pass or fail depending on the marks of the students
        if (marks >= 40)
        {
            status = "PASS";
        }
        else
        {
            status = "FAIL";
        }

        //displaying the student information in the final form of output
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

