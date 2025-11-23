
#include <stdio.h>
#include <stdlib.h>

int mutex = 1;       // mutual exclusion semaphore
int full = 0;        // count of full slots
int empty;           // count of empty slots
int x = 0;           // item counter

// Wait operation
int wait(int s) {
    return (--s);
}

// Signal operation
int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces item %d", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d", x);
    x--;
    mutex = signal(mutex);
}

int main() {
    int n, choice;
    printf("Enter the buffer size: ");
    scanf("%d", &n);
    empty = n;

    while (1) {
        printf("\n\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("\nBuffer is full!");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("\nBuffer is empty!");
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}




