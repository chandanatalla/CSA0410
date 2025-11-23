
#include <stdio.h>
#include <string.h>

// Function to display permissions in rwx format
void displayPermissions(int perm) {
    char str[4];
    str[0] = (perm & 4) ? 'r' : '-'; // Read
    str[1] = (perm & 2) ? 'w' : '-'; // Write
    str[2] = (perm & 1) ? 'x' : '-'; // Execute
    str[3] = '\0';
    printf("%s", str);
}

int main() {
    int owner, group, others;

    printf("Enter owner permissions (0-7): ");
    scanf("%d", &owner);
    printf("Enter group permissions (0-7): ");
    scanf("%d", &group);
    printf("Enter others permissions (0-7): ");
    scanf("%d", &others);

    printf("\nFile Permissions Simulation:\n");
    printf("Owner : ");
    displayPermissions(owner);
    printf("\nGroup : ");
    displayPermissions(group);
    printf("\nOthers: ");
    displayPermissions(others);

    printf("\n\nComplete Permission String: ");
    displayPermissions(owner);
    displayPermissions(group);
    displayPermissions(others);
    printf("\n");

    return 0;
}




