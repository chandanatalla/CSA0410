
#include <stdio.h>
#include <stdlib.h>

// Structure for a disk block
struct Block {
    int blockNumber;
    struct Block *next;
};

// Function to create a new block
struct Block* createBlock(int blockNumber) {
    struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->blockNumber = blockNumber;
    newBlock->next = NULL;
    return newBlock;
}

// Function to display the linked allocation of a file
void displayFile(struct Block* start) {
    struct Block* temp = start;
    printf("File blocks: ");
    while (temp != NULL) {
        printf("%d -> ", temp->blockNumber);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n, i, blockNum;
    struct Block *start = NULL, *end = NULL, *newBlock;

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &blockNum);
        newBlock = createBlock(blockNum);

        if (start == NULL) {
            start = newBlock;
            end = newBlock;
        } else {
            end->next = newBlock;
            end = newBlock;
        }
    }

    printf("\nLinked Allocation Simulation:\n");
    printf("Start block: %d\n", start->blockNumber);
    printf("End block: %d\n", end->blockNumber);

    displayFile(start);

    return 0;
}

