#include <stdio.h>
#include <stdlib.h>


/*START
  DECLARE n, i, sum = 0
  READ n
  DECLARE arr[n]
  FOR i = 0 TO n-1
    READ arr[i]
    sum = sum + arr[i]
  END FOR
  PRINT "Sum = ", sum
END*/



int main(void) {
    int n, i, sum = 0;

    printf("Input the number of elements to be stored in the array :");
    scanf("%d", &n);

    int arr[n];

    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];   // Accumulate each element into sum
    }

    printf("Sum of all elements stored in the array is : %d\n", sum);

    return 0;
}
