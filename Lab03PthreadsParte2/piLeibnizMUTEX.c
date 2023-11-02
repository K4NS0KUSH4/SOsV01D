/* This code was developed by Pedro Henrique Araujo Farias.
 * Feel free to use. It's totally open source. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double sum = 0.0;
pthread_mutex_t mutex;
int termsPerThread = 30000;

void *leibnizSeries(void *threadNum);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Invalid arguments. Usage: <program> <number of threads>\n");
        return 1;
    }

    int numOfThreads = strtol(argv[1], NULL, 10);
    pthread_t *threadArray = malloc(numOfThreads * sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);

    for (long thread = 0; thread < numOfThreads; thread++) {
        pthread_create(&threadArray[thread], NULL, leibnizSeries, (void*) thread);
    }

    for (int i = 0; i < numOfThreads; i++) { pthread_join(threadArray[i], NULL); }

    double pi = 4 * sum;
    pthread_mutex_destroy(&mutex);
    free(threadArray);

    printf("Número de threads: %d\nValor de PI calculado: %.10lf\n", numOfThreads, pi);

    return 0;
}

void *leibnizSeries(void *threadNum) {
    long idThread = (long) threadNum;
    double factor;
    long firstTerm = idThread * termsPerThread;
    long lastTerm = firstTerm + termsPerThread;

    if (idThread % 2 == 0) { factor = 1.0; }
    else { factor = -1.0; }

    pthread_mutex_lock(&mutex);
    for (int i = firstTerm; i < lastTerm; i++, factor = -factor) {
        sum += factor / (2 * i + 1);
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}
