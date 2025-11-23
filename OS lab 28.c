
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], pattern[50], line[200];
    int lineNumber = 0, found = 0;

    // Input filename
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Input search pattern
    printf("Enter the search pattern: ");
    scanf("%s", pattern);

    // Open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read file line by line and search
    while (fgets(line, sizeof(line), fp) != NULL) {
        lineNumber++;
        if (strstr(line, pattern) != NULL) {
            printf("Match found at line %d: %s", lineNumber, line);
            found = 1;
        }
    }

    if (!found) {
        printf("No matches found for '%s'\n", pattern);
    }

    fclose(fp);
    return 0;
}

