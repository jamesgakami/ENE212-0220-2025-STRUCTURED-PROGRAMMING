#include <stdio.h>
#include <stdlib.h>

/*START
  DECLARE n, i, value, pos
  READ n
  DECLARE arr[n+1]     // one extra slot for insertion
  FOR i = 0 TO n-1
    READ arr[i]
  END FOR
  READ value
  READ pos               // 1-based position
  // Shift elements from the end down to pos-1
  FOR i = n DOWNTO pos
    arr[i] = arr[i-1]
  END FOR
  arr[pos-1] = value
  PRINT "After Insert: "
  FOR i = 0 TO n
    PRINT arr[i]
  END FOR
END */


int main(void) {
    int n, i, value, pos;

    printf("Input the size of array : ");
    scanf("%d", &n);

    // Allocate n+1 so there is room for the new element
    int arr[n + 1];

    printf("Input %d elements in the array in ascending order:\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Input the value to be inserted : ");
    scanf("%d", &value);

    printf("Input the Position, where the value to be inserted : ");
    scanf("%d", &pos);   // 1-based position

    // Print the current array before insertion
    printf("The current list of the array : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Shift elements one position to the right, starting from the end
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new value at the requested position
    arr[pos - 1] = value;

    // Print the updated array (now has n+1 elements)
    printf("After Insert the element the new list is : ");
    for (i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
