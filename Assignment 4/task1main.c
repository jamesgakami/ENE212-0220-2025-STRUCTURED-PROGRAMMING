#include <stdio.h>
#include <stdlib.h>


/*START
  DECLARE n, i
  READ n
  DECLARE arr[n]
  FOR i = 0 TO n-1
    READ arr[i]
  END FOR
  PRINT "Original: "
  FOR i = 0 TO n-1
    PRINT arr[i]
  END FOR
  PRINT "Reversed: "
  FOR i = n-1 DOWNTO 0
    PRINT arr[i]
  END FOR
END*/

int main(void) {
    int n, i;

    // Ask user for the number of elements
    printf("Input the number of elements to store in the array :");
    scanf("%d", &n);

    int arr[n];  // Variable-length array (C99)

    // Read n elements from the user
    printf("Input %d number of elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Display the array in reverse order
    printf("The values store into the array in reverse are : ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
