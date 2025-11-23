
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, direction;
    int total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk requests sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    // Sort requests
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (request[i] > request[j]) {
                int temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nSequence of head movement:\n");

    if (direction == 1) { // moving right
        // First service requests greater than head
        for (i = 0; i < n; i++) {
            if (request[i] >= head) {
                printf("Head moves from %d to %d\n", head, request[i]);
                total += abs(request[i] - head);
                head = request[i];
            }
        }
        // Go to end of disk (assuming 199 as max cylinder)
        printf("Head moves from %d to 199\n", head);
        total += abs(199 - head);
        head = 199;

        // Then service requests on the left side
        for (i = n - 1; i >= 0; i--) {
            if (request[i] < head) {
                printf("Head moves from %d to %d\n", head, request[i]);
                total += abs(request[i] - head);
                head = request[i];
            }
        }
    } else { // moving left
        // First service requests smaller than head
        for (i = n - 1; i >= 0; i--) {
            if (request[i] <= head) {
                printf("Head moves from %d to %d\n", head, request[i]);
                total += abs(request[i] - head);
                head = request[i];
            }
        }
        // Go to start of disk (0)
        printf("Head moves from %d to 0\n", head);
        total += abs(head - 0);
        head = 0;

        // Then service requests on the right side
        for (i = 0; i < n; i++) {
            if (request[i] > head) {
                printf("Head moves from %d to %d\n", head, request[i]);
                total += abs(request[i] - head);
                head = request[i];
            }
        }
    }

    printf("\nTotal head movement = %d\n", total);
    printf("Average head movement = %.2f\n", (float)total / n);

    return 0;
}

