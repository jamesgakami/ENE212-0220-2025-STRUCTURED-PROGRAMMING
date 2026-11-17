#include <stdio.h>
#include <stdlib.h>


/*START
  DECLARE n, i, j, count
  READ n
  DECLARE arr[n]
  FOR i = 0 TO n-1
    READ arr[i]
  END FOR
  PRINT "Unique elements: "
  FOR i = 0 TO n-1
    count = 0
    FOR j = 0 TO n-1
      IF arr[i] == arr[j] THEN
        count = count + 1
      END IF
    END FOR
    IF count == 1 THEN
      PRINT arr[i]
    END IF
  END FOR
END */


#include <stdio.h>

int main(void) {
    int n, i, j, count;

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("The unique elements found in the array are: ");

    // For each element, count how many times it appears
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;   // Count occurrences
            }
        }
        // If it appears exactly once, it's unique
        if (count == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
