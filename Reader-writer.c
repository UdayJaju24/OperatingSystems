#include <pthread.h>
#include <stdio.h>

pthread_mutex_t read_mutex;   // Mutex for controlling read access
pthread_mutex_t write_mutex;  // Mutex for controlling write access
int read_count = 0;           // Number of readers accessing the resource 

void* reader(void* arg) {
    pthread_mutex_lock(&read_mutex);
    read_count++;
    if (read_count == 1) {
        pthread_mutex_lock(&write_mutex);  // Lock the write_mutex when first reader arrives
    }
    pthread_mutex_unlock(&read_mutex);

    // Reading the resource
    printf("Reader %d is reading the resource\n", *(int*)arg);

    pthread_mutex_lock(&read_mutex);
    read_count--;
    if (read_count == 0) {
        pthread_mutex_unlock(&write_mutex);  // Release the write_mutex when last reader leaves
    }
    pthread_mutex_unlock(&read_mutex);

    pthread_exit(NULL);
}

void* writer(void* arg) {
    pthread_mutex_lock(&write_mutex);

    // Writing to the resource
    printf("Writer %d is writing to the resource\n", *(int*)arg);

    pthread_mutex_unlock(&write_mutex);

    pthread_exit(NULL);
}

int main() {
    // Initialize the mutexes
    pthread_mutex_init(&read_mutex, NULL);
    pthread_mutex_init(&write_mutex, NULL);

    int num_readers, num_writers;
    printf("Enter the number of readers: ");
    scanf("%d", &num_readers);
    printf("Enter the number of writers: ");
    scanf("%d", &num_writers);

    // Create a list of threads, with num_readers reader threads and num_writers writer threads
    pthread_t threads[num_readers + num_writers];
    for (int i = 0; i < num_readers; i++) {
        int* reader_id = malloc(sizeof(int));  // Allocate memory for the reader ID
        *reader_id = i + 1;
        pthread_create(&threads[i], NULL, reader, reader_id);
    }
    for (int i = 0; i < num_writers; i++) {
        int* writer_id = malloc(sizeof(int));  // Allocate memory for the writer ID
        *writer_id = i + 1;
        pthread_create(&threads[num_readers + i], NULL, writer, writer_id);
    }

    // Wait for the threads to finish
    for (int i = 0; i < num_readers + num_writers; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutexes
    pthread_mutex_destroy(&read_mutex);
    pthread_mutex_destroy(&write_mutex);

    return 0;
}
