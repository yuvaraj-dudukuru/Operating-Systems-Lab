#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // Define buffer size

int buffer[BUFFER_SIZE];  // Shared buffer
int in = 0, out = 0;  // Indexes for producer and consumer

sem_t empty, full;  // Semaphore for empty and full buffer slots
pthread_mutex_t mutex;  // Mutex for critical section

void *producer(void *arg) {
    int item;
    for (int i = 0; i < 10; i++) {  // Producing 10 items
        item = i + 1;  // Producing an item
        sem_wait(&empty);  // Wait if buffer is full
        pthread_mutex_lock(&mutex);  // Lock critical section

        buffer[in] = item;  // Add item to buffer
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;  // Circular increment

        pthread_mutex_unlock(&mutex);  // Unlock critical section
        sem_post(&full);  // Increase full count
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg) {
    int item;
    for (int i = 0; i < 10; i++) {  // Consuming 10 items
        sem_wait(&full);  // Wait if buffer is empty
        pthread_mutex_lock(&mutex);  // Lock critical section

        item = buffer[out];  // Remove item from buffer
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;  // Circular increment

        pthread_mutex_unlock(&mutex);  // Unlock critical section
        sem_post(&empty);  // Increase empty count
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);  // Empty slots = BUFFER_SIZE
    sem_init(&full, 0, 0);  // Full slots = 0
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
