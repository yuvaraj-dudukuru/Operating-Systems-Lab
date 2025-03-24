#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];  // File descriptors for the pipe
    char buffer[100];
    char message[] = "Hello from Parent!";

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid > 0) { // Parent Process
        close(pipefd[0]);  // Close read end
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);
    } else { // Child Process
        close(pipefd[1]);  // Close write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(pipefd[0]);
    }

    return 0;
}
