#include <stdio.h>
#include <stdlib.h>

/*DEFINE BUFFER_SIZE = 5
DECLARE buffer[BUFFER_SIZE]
DECLARE head = 0        // next write position
DECLARE count = 0       // number of valid samples

FUNCTION insert_sample(value):
  buffer[head] = value
  head = (head + 1) % BUFFER_SIZE
  IF count < BUFFER_SIZE THEN
    count = count + 1
  END IF
END FUNCTION

FUNCTION print_samples():
  // Compute index of oldest sample
  IF count < BUFFER_SIZE THEN
    start = 0
  ELSE
    start = head           // head points to oldest when full
  END IF
  FOR i = 0 TO count-1
    idx = (start + i) % BUFFER_SIZE
    PRINT buffer[idx]
  END FOR
END FUNCTION

MAIN:
  LOOP:
    READ value
    IF value == -1 THEN BREAK
    insert_sample(value)
    print_samples()
  END LOOP
END MAIN */



#define BUFFER_SIZE 5   // Fixed buffer size

// Circular buffer state
int buffer[BUFFER_SIZE];
int head = 0;    // Points to the next slot to write
int count = 0;   // Number of valid samples currently stored

/* Insert a new sample into the circular buffer.
   If the buffer is full, the oldest value is overwritten. */
void insert_sample(int value) {
    buffer[head] = value;                // Write new sample
    head = (head + 1) % BUFFER_SIZE;     // Advance head circularly

    if (count < BUFFER_SIZE) {
        count++;                         // Buffer not yet full
    }
}

/* Print stored samples from oldest to newest. */
void print_samples(void) {
    int start, i, idx;

    if (count == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    // When the buffer is full, head points to the oldest element.
    // Otherwise, the oldest element is at index 0.
    start = (count < BUFFER_SIZE) ? 0 : head;

    printf("Buffer (oldest -> newest): ");
    for (i = 0; i < count; i++) {
        idx = (start + i) % BUFFER_SIZE; // Wrap around
        printf("%d ", buffer[idx]);
    }
    printf("\n");
}

int main(void) {
    int value;

    printf("Circular Data Logger (BUFFER_SIZE = %d)\n", BUFFER_SIZE);
    printf("Enter sensor values (-1 to quit):\n");

    while (1) {
        printf("Enter value: ");
        if (scanf("%d", &value) != 1) {
            break;   // Handle invalid input
        }
        if (value == -1) {
            break;   // Sentinel to stop
        }

        insert_sample(value);
        print_samples();   // Show chronological order after each insert
    }

    printf("Final buffer contents:\n");
    print_samples();

    return 0;
}
