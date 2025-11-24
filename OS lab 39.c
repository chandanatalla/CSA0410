
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, i, head, disk_size;
    int requests[50];
    int seek_time = 0;
    int index;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests (space separated): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size (number of cylinders): ");
    scanf("%d", &disk_size);

    // Sort the request queue
    sort(requests, n);

    // Find the index where head is located
    for (i = 0; i < n; i++) {
        if (head < requests[i]) {
            index = i;
            break;
        }
    }

    printf("\nOrder of servicing requests (C-SCAN):\n");

    // Move towards the end of disk
    for (i = index; i < n; i++) {
        printf("%d ", requests[i]);
        seek_time += abs(head - requests[i]);
        head = requests[i];
    }

    // Jump to end of disk
    seek_time += abs(disk_size - head - 1);
    head = 0; // circular jump to beginning

    // Move from beginning to the index-1
    for (i = 0; i < index; i++) {
        printf("%d ", requests[i]);
        seek_time += abs(head - requests[i]);
        head = requests[i];
    }

    printf("\nTotal Seek Time = %d\n", seek_time);
    printf("Average Seek Time = %.2f\n", (float)seek_time/n);

    return 0;
}



