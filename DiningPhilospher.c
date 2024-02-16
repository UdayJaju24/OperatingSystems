#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_PHILOSOPHERS 100

sem_t forks[MAX_PHILOSOPHERS];
pthread_t philosophers[MAX_PHILOSOPHERS];
int num_philosophers;
int num_eats;

void* philosopher(void* arg) {
    int id = *(int*) arg;
    int left_fork = id;
    int right_fork = (id + 1) % num_philosophers;

    for (int i = 0; i < num_eats; i++) {
        sem_wait(&forks[left_fork]);
        sem_wait(&forks[right_fork]);

        printf("Philosopher %d is eating.\n", id);
        sleep(1);

        sem_post(&forks[right_fork]);
        sem_post(&forks[left_fork]);

        printf("Philosopher %d is thinking.\n", id);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main() {
    printf("Enter the number of philosophers (maximum %d): ", MAX_PHILOSOPHERS);
    scanf("%d", &num_philosophers);
    if (num_philosophers <= 0 || num_philosophers > MAX_PHILOSOPHERS) {
        printf("Error: Invalid number of philosophers.\n");
        return 1;
    }

    printf("Enter the number of times each philosopher will eat: ");
    scanf("%d", &num_eats);
    if (num_eats <= 0) {
        printf("Error: Invalid number of eats.\n");
        return 1;
    }

    for (int i = 0; i < num_philosophers; i++) {
        sem_init(&forks[i], 0, 1);
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, philosopher, id);
    }

    for (int i = 0; i < num_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
        sem_destroy(&forks[i]);
    }

    return 0;
}
