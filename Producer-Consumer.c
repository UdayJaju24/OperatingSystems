#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    int item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        item = rand() % 100;  // produce an item
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            pthread_mutex_unlock(&mutex);
            sched_yield();
            pthread_mutex_lock(&mutex);
        }
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        pthread_mutex_unlock(&mutex);
        printf("Produced item %d\n", item);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            pthread_mutex_unlock(&mutex);
            sched_yield();
            pthread_mutex_lock(&mutex);
        }
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        pthread_mutex_unlock(&mutex);
        printf("Consumed item %d\n", item);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;
    srand(time(NULL));
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}
