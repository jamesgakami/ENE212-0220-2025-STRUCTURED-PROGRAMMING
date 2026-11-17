#include <stdio.h>
#include <stdlib.h>


/*START
  DECLARE n, i, max, min
  READ n
  DECLARE arr[n]
  FOR i = 0 TO n-1
    READ arr[i]
  END FOR
  max = arr[0]
  min = arr[0]
  FOR i = 1 TO n-1
    IF arr[i] > max THEN max = arr[i]
    IF arr[i] < min THEN min = arr[i]
  END FOR
  PRINT "Maximum = ", max
  PRINT "Minimum = ", min
END */


int main(void) {
    int n, i, max, min;

    printf("Input the number of elements to be stored in the array :");
    scanf("%d", &n);

    int arr[n];

    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with the first element
    max = arr[0];
    min = arr[0];

    // Traverse remaining elements
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];   // New maximum found
        }
        if (arr[i] < min) {
            min = arr[i];   // New minimum found
        }
    }

    printf("Maximum element is : %d\n", max);
    printf("Minimum element is : %d\n", min);

    return 0;
}
