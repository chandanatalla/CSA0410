
#include <stdio.h>

int main() {
    int frames[10], pages[30], temp[10];
    int m, n, pageFaults = 0, count = 0;
    int i, j, k;

    printf("Enter number of frames: ");
    scanf("%d", &m);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the reference string (space separated):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames
    for(i = 0; i < m; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++) {
        int flag = 0;

        // Check if page already exists in frame
        for(j = 0; j < m; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found, replace using FIFO
        if(flag == 0) {
            frames[count] = pages[i];
            count = (count + 1) % m;
            pageFaults++;
        }

        // Print current frame status
        printf("%d\t", pages[i]);
        for(k = 0; k < m; k++) {
            if(frames[k] != -1)
                printf("%d ", frames[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}




