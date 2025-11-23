
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, choice, block;
    int indexBlock[20], fileBlocks[20];

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    // Input block numbers for the file
    printf("Enter block numbers for the file:\n");
    for(i = 0; i < n; i++) {
        printf("Block %d: ", i+1);
        scanf("%d", &fileBlocks[i]);
        indexBlock[i] = fileBlocks[i];  // store in index block
    }

    while(1) {
        printf("\n--- Indexed File Allocation Menu ---\n");
        printf("1. Display Index Block\n");
        printf("2. Access a block by index\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nIndex Block Contents:\n");
                for(i = 0; i < n; i++) {
                    printf("Index[%d] -> Block %d\n", i, indexBlock[i]);
                }
                break;

            case 2:
                printf("Enter index to access (0 to %d): ", n-1);
                scanf("%d", &block);

                if(block < 0 || block >= n) {
                    printf("Invalid index!\n");
                } else {
                    printf("Accessing block at index %d -> Block %d\n", block, indexBlock[block]);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}



