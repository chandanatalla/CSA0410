/* mem_alloc.c  -- C89-compatible implementation
   First Fit, Best Fit, Worst Fit memory allocation simulations.
   Works in Dev-C++ (MinGW) with default settings.
*/

#include <stdio.h>
#include <stdlib.h>

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int *allocation;
    int i, j;

    allocation = (int *)malloc(processes * sizeof(int));
    if (allocation == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (i = 0; i < processes; i++)
        allocation[i] = -1;

    for (i = 0; i < processes; i++) {
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT ALLOCATION:\n");
    for (i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i, allocation[i]);
        else
            printf("Process %d -> Not Allocated\n", i);
    }

    free(allocation);
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int *allocation;
    int i, j, best;

    allocation = (int *)malloc(processes * sizeof(int));
    if (allocation == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (i = 0; i < processes; i++)
        allocation[i] = -1;

    for (i = 0; i < processes; i++) {
        best = -1;
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (best == -1 || blockSize[j] < blockSize[best])
                    best = j;
            }
        }
        if (best != -1) {
            allocation[i] = best;
            blockSize[best] -= processSize[i];
        }
    }

    printf("\nBEST FIT ALLOCATION:\n");
    for (i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i, allocation[i]);
        else
            printf("Process %d -> Not Allocated\n", i);
    }

    free(allocation);
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int *allocation;
    int i, j, worst;

    allocation = (int *)malloc(processes * sizeof(int));
    if (allocation == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (i = 0; i < processes; i++)
        allocation[i] = -1;

    for (i = 0; i < processes; i++) {
        worst = -1;
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worst == -1 || blockSize[j] > blockSize[worst])
                    worst = j;
            }
        }
        if (worst != -1) {
            allocation[i] = worst;
            blockSize[worst] -= processSize[i];
        }
    }

    printf("\nWORST FIT ALLOCATION:\n");
    for (i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i, allocation[i]);
        else
            printf("Process %d -> Not Allocated\n", i);
    }

    free(allocation);
}

int main(void) {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int blocks, processes;
    int *b1, *b2, *b3;
    int i;

    blocks = sizeof(blockSize) / sizeof(blockSize[0]);
    processes = sizeof(processSize) / sizeof(processSize[0]);

    /* make copies because each algorithm mutates the block sizes */
    b1 = (int *)malloc(blocks * sizeof(int));
    b2 = (int *)malloc(blocks * sizeof(int));
    b3 = (int *)malloc(blocks * sizeof(int));
    if (b1 == NULL || b2 == NULL || b3 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < blocks; i++) {
        b1[i] = blockSize[i];
        b2[i] = blockSize[i];
        b3[i] = blockSize[i];
    }

    firstFit(b1, blocks, processSize, processes);
    bestFit(b2, blocks, processSize, processes);
    worstFit(b3, blocks, processSize, processes);

    free(b1);
    free(b2);
    free(b3);

    return 0;
}

