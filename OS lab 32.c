
#include <stdio.h>

int main() {
    int frames[10], pages[30], counter[10];
    int m, n, pageFaults = 0;
    int i, j, k, pos, min, flag;

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
        counter[i] = 0;
    }

    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++) {
        flag = 0;

        // Check if page already exists in frame
        for(j = 0; j < m; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                counter[j] = i + 1; // update usage time
                break;
            }
        }

        // If page not found, replace using LRU
        if(flag == 0) {
            pos = 0;
            min = counter[0];
            for(j = 1; j < m; j++) {
                if(counter[j] < min) {
                    min = counter[j];
                    pos = j;
                }
            }
            frames[pos] = pages[i];
            counter[pos] = i + 1;
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




