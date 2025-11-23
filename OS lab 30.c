
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void* threadFunction(void* arg) {
    int *val = (int*) arg;
    printf("Thread created with value: %d\n", *val);

    // Demonstrate pthread_exit
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int val1 = 1, val2 = 2;

    // (i) Create threads
    if (pthread_create(&t1, NULL, threadFunction, &val1) != 0) {
        printf("Error creating thread 1\n");
        return 1;
    }
    if (pthread_create(&t2, NULL, threadFunction, &val2) != 0) {
        printf("Error creating thread 2\n");
        return 1;
    }

    // (ii) Join threads (wait for them to finish)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Both threads joined successfully.\n");

    // (iii) Equal – check if two thread IDs are equal
    if (pthread_equal(t1, t2))
        printf("Thread 1 and Thread 2 are equal.\n");
    else
        printf("Thread 1 and Thread 2 are NOT equal.\n");

    // (iv) Exit – exit the main thread
    printf("Main thread exiting now.\n");
    pthread_exit(NULL);

    return 0; // This line will not be reached due to pthread_exit
}




