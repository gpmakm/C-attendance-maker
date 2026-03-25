#include<stdio.h>
#include<string.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f;
    char c[100];

    // Open file for reading
    f = fopen("attendance.txt", "r");
    if (f == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    // Read and print file content
    while (fgets(c, sizeof(c), f) != NULL) {
        printf("%s", c);
    }

    fclose(f);

    // Open file for appending
    f = fopen("attendance.txt", "a");
    if (f == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }

    // Write to file
    fprintf(f, "Present\n");

    fclose(f);

    printf("\nData written successfully.\n");

    return 0;
}