
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int id;
    char data[50];
};

int main() {
    struct Record file[20];
    int n, i, choice, rec_id;

    printf("Enter number of records to store: ");
    scanf("%d", &n);

    // Input records sequentially
    for(i = 0; i < n; i++) {
        file[i].id = i + 1;
        printf("Enter data for record %d: ", file[i].id);
        scanf("%s", file[i].data);
    }

    while(1) {
        printf("\n--- Sequential File Access Menu ---\n");
        printf("1. Display all records\n");
        printf("2. Access a record by ID\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nRecords stored sequentially:\n");
                for(i = 0; i < n; i++) {
                    printf("Record %d -> %s\n", file[i].id, file[i].data);
                }
                break;

            case 2:
                printf("Enter record ID to access: ");
                scanf("%d", &rec_id);

                if(rec_id > n || rec_id < 1) {
                    printf("Invalid record ID!\n");
                } else {
                    printf("Accessing record %d sequentially...\n", rec_id);
                   for(i = 0; i < rec_id; i++) {
                        printf("Record %d -> %s\n", file[i].id, file[i].data);
                    }
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



