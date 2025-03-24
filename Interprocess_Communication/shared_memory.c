// Writer Program (shm_writer.c)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, NULL, 0);

    strcpy(str, "Hello from Shared Memory!");
    printf("Data written to shared memory: %s\n", str);

    shmdt(str); // Detach shared memory
    return 0;
}



// Reader Program (shm_reader.c)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, NULL, 0);

    printf("Data read from shared memory: %s\n", str);

    shmdt(str); // Detach shared memory
    shmctl(shmid, IPC_RMID, NULL); // Destroy shared memory
    return 0;
}
