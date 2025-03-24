#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "myfifo"

int main() {
    char message[] = "Hello via FIFO!";
    char buffer[100];

    pid_t pid = fork();

    if (pid > 0) { // Parent Process - Writer
        int fd = open(FIFO_NAME, O_WRONLY);
        write(fd, message, strlen(message) + 1);
        close(fd);
    } else { // Child Process - Reader
        int fd = open(FIFO_NAME, O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd);
    }

    return 0;
}
