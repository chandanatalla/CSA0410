#include <stdio.h>

int main() {

    FILE *file;

    file = fopen("example.txt", "w");   // creates file in the folder where .exe runs

    if (file == NULL) {
        printf("Error creating file\n");
        return 1;
    }

    fprintf(file, "Sample content");
    fclose(file);

    printf("File created successfully\n");

    return 0;
}



