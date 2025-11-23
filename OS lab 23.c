
#include <stdio.h>

int main() {
    int blockSize[20], processSize[20], blockAllocated[20];
    int m, n; // m = number of blocks, n = number of processes
    int i, j;

    // Input number of blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each block:\n");
    for(i = 0; i < m; i++) {
        printf("Block %d: ", i+1);
        scanf("%d", &blockSize[i]);
    }

    // Input number of processes
    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &processSize[i]);
        blockAllocated[i] = -1; // initially not allocated
    }

    // First Fit Allocation
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                blockAllocated[i] = j;
                blockSize[j] -= processSize[i]; // reduce block size
                break;
            }
        }
    }

    // Output allocation results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < n; i++) {
        if(blockAllocated[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i+1, processSize[i], blockAllocated[i]+1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, processSize[i]);
    }

    return 0;
}



