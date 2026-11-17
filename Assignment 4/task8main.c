#include <stdio.h>
#include <stdlib.h>

/*START
  DECLARE matrix[6][4] with initial values
  FOR row = 0 TO 5
    FOR col = 0 TO 3
      PRINT matrix[row][col]
    END FOR
    PRINT newline
  END FOR
END */


#define ROWS 6
#define COLS 4

int main(void) {
    int i, j;

    // Initialize a 6x4 2D array with sample values
    int matrix[ROWS][COLS] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };

    // Traverse every element using nested loops
    printf("2D Array (%d rows x %d columns):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%4d", matrix[i][j]);   // Print each element
        }
        printf("\n");   // Newline after each row
    }

    return 0;
}
