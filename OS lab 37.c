
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, total = 0;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk requests sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSequence of head movement:\n");
    for (i = 0; i < n; i++) {
        printf("Head moves from %d to %d\n", head, request[i]);
        total += abs(request[i] - head);
        head = request[i];
    }

    printf("\nTotal head movement = %d\n", total);
    printf("Average head movement = %.2f\n", (float)total / n);

    return 0;
}




