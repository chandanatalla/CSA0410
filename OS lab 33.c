
#include <stdio.h>

int main() {
    int frames[10], pages[30];
    int m, n, pageFaults = 0;
    int i, j, k, pos, flag, max, future[10];

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
        flag = 0;

        // Check if page already exists in frame
        for(j = 0; j < m; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // If page not found, replace using Optimal
        if(flag == 0) {
            // If empty frame available
            for(j = 0; j < m; j++) {
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    pageFaults++;
                    flag = 1;
                    break;
                }
            }

            // If no empty frame, find optimal replacement
            if(flag == 0) {
                for(j = 0; j < m; j++) {
                    future[j] = -1;
                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            future[j] = k;
                            break;
                        }
                    }
                }

                pos = -1;
                max = -1;
                for(j = 0; j < m; j++) {
                    if(future[j] == -1) {
                        pos = j;
                        break;
                    }
                    if(future[j] > max) {
                        max = future[j];
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
                pageFaults++;
            }
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






