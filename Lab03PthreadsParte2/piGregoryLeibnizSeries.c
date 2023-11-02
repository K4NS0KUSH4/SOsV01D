/* This code was developed by Pedro Henrique Araujo Farias.
 * Feel free to use. It's totally open source. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double sum = 0;
int termsPerThread;

void* gregoryLeibnizSeries(void* threadNum);

int main(int argc, char* argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Invalid arguments. Usage: <program> <number of threads> <number of terms per thread>\n");
        return 1;
    }

    int numOfThreads = strtol(argv[1], NULL, 10);
    termsPerThread = strtol(argv[2], NULL, 10);
    pthread_t* threadArray = malloc(numOfThreads * sizeof(pthread_t));

    for(int thread = 0; thread < numOfThreads; thread++) {
        pthread_create(&threadArray[thread], NULL, gregoryLeibnizSeries, (void*) thread);
    }

    for(int i = 0; i < numOfThreads; i++) { pthread_join(threadArray[i], NULL); }

    double pi = 4 * sum;

    printf("Valor: %lf\n", pi);

    return 0;
}

void* gregoryLeibnizSeries(void* threadNum) {
    long idThread = (long) threadNum;
    double factor;
    long firstTerm = idThread * termsPerThread;
    long lastTerm = firstTerm + termsPerThread;

    if(idThread % 2 == 0) { factor = 1.0; }
    else { factor = -1.0; }

    for(int i = firstTerm; i < lastTerm; i++, factor = -factor) {
        sum += factor/(2 * i + 1);
    }

    return NULL;
}