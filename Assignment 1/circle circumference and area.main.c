#include <stdio.h>
#include <stdlib.h>

int main()
{
    //classification of the various words that will be used
    float radius, result;
    char choice;

    const float PI = 3.14159;

    //inputing the radius and the desired calculation whether area or circumference
    printf("Enter the radius of the circle:");
    scanf("%f", &radius);
    printf("Do you want to calculate area (a)or the circumference(c)?");
    scanf(" %c", &choice);

    //Calculating the area or circumference depending on the choice used

    if (choice== 'a'){
        result=PI*radius*radius ;
        printf("The area = %.2f\n", result);}

    else if (choice== 'c'){
        result=PI*2*radius ;
        printf("The circumference = %.2f\n", result);}

    else {
        printf("\n Invalid choice!Please choose area or circumference");
    }




    return 0;
}
