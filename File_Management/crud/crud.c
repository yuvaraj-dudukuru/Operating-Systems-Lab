#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int f1, f2, i = 0;
    char c, strin[100];

    // Open (or create) file "data" for read/write and truncate existing file
    f1 = open("data", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (f1 < 0) {
        perror("Error opening file for writing");
        return 1;
    }

    // Read characters until newline is encountered
    printf("Enter text: ");
    while ((c = getchar()) != '\n' && i < 99) {
        strin[i++] = c;
    }
    strin[i] = '\0';  // Null-terminate the string

    // Write the string to the file
    if (write(f1, strin, i) != i) {
        perror("Error writing to file");
        close(f1);
        return 1;
    }
    close(f1);  // Close the file after writing

    // Open the file for reading
    f2 = open("data", O_RDONLY);
    if (f2 < 0) {
        perror("Error opening file for reading");
        return 1;
    }

    // Clear the string buffer and read contents from file
    i = 0;
    while (read(f2, &c, 1) == 1 && i < 99) {
        strin[i++] = c;
    }
    strin[i] = '\0';  // Null-terminate the string

    // Display the file content
    printf("\nFile Contents: %s\n", strin);
    close(f2);  // Close the file

    return 0;
}
