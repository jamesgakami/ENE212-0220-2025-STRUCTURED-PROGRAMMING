#include <stdio.h>
#include <stdlib.h>


/*START
  DECLARE n, i, j, temp
  READ n
  DECLARE arr[n]
  FOR i = 0 TO n-1
    READ arr[i]
  END FOR
  // Bubble sort
  FOR i = 0 TO n-2
    FOR j = 0 TO n-2-i
      IF arr[j] > arr[j+1] THEN
        SWAP arr[j], arr[j+1]
      END IF
    END FOR
  END FOR
  PRINT "Sorted: "
  FOR i = 0 TO n-1
    PRINT arr[i]
  END FOR
END*/


int main(void) {
    int n, i, j, temp;

    printf("Input the size of array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    // Bubble sort: repeatedly swap adjacent out-of-order elements
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Elements of array in sorted ascending order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
