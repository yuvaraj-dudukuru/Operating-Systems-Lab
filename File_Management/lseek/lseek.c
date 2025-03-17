#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int file;
    char buffer[20];
    ssize_t bytesRead;

    // Open "testfile.txt" in read-only mode
    file = open("testfile.txt", O_RDONLY);
    if (file < 0) {
        perror("Error opening file");
        return 1;
    }

    // Read first 19 bytes from the file into buffer
    bytesRead = read(file, buffer, 19);
    if (bytesRead < 0) {
        perror("Error reading file");
        close(file);
        return 1;
    }
    buffer[bytesRead] = '\0';  // Null-terminate the buffer
    printf("First Read: %s\n", buffer);

    // Change the file pointer position using lseek: set offset to 10 bytes from beginning
    if (lseek(file, 10, SEEK_SET) < 0) {
        perror("Error in lseek");
        close(file);
        return 1;
    }

    // Read another 19 bytes from the new position
    bytesRead = read(file, buffer, 19);
    if (bytesRead < 0) {
        perror("Error reading file after lseek");
        close(file);
        return 1;
    }
    buffer[bytesRead] = '\0';  // Null-terminate the buffer
    printf("Second Read: %s\n", buffer);

    close(file);
    return 0;
}
