#include <stdio.h>
#include <stdlib.h>

int main()
{
    //inputing the numbers and operator
    double num1, num2, result;
    char operator;
    printf("Enter first number:");
    scanf("%lf", &num1);

    printf("Enter an operator(+,-,*,/):\n" );
    scanf(" %C",&operator);

    printf("Enter second number:");
    scanf("%lf", &num2);

    //how the operators will operate
    switch(operator){
      //addition
        case '+':
            result=num1+num2;
            printf("Result=%.2lf\n", result);
            break;
      //subtraction
        case '-':
            result=num1-num2;
            printf("Result= %.2lf\n", result);
            break;
     //multiplication
        case '*':
            result=num1*num2;
            printf("Result= &.2lf\n", result);
            break;
     //division
        case '/':
            if(num2!= 0){result= num1/num2;
                printf("Result = %.2lf\n", result);}
            else{printf("Can not be divided by zero.\n");}
            break;}
return 0;

}
