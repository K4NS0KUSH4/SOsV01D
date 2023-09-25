/* This code was developed by Pedro Henrique Araujo Farias.
 * Feel free to use. It's totally open source. */

#include <stdio.h> // For output purposes.
#include <stdlib.h> // Dinamic memory allocation.
#include <pthread.h> // POSIX threads library.
#include <time.h> // For random applications.

typedef struct { // Defining struct for an account.
    int balance;
} account;

// Global variables to be acessed by threads.
int numOfThreads;
int transactionAmount;
int numOfTransactions;
int successfulTransactions;
pthread_mutex_t mutex;

void updateBalance(account* origin, account* destiny) { // Auxiliar function.
    printf("ORIGIN BALANCE: %d\n", origin->balance);
    printf("DESTINY BALANCE: %d\n", destiny->balance);

    if(origin->balance < transactionAmount) { // If account has insufficient balance.
        printf("ERROR: Origin account has insufficient balance. Unable to do transaction.\n\n");
        return;
    }

    // Transferring amount from origin to destiny accounts.
    origin->balance -= transactionAmount; 
    destiny->balance += transactionAmount;
    successfulTransactions++; // Incrementing number of successful transactions.

    // Updated balances feedback.
    printf("Transaction completed successfully!\n");
    printf("ORIGIN BALANCE: %d\n", origin->balance);
    printf("DESTINY BALANCE: %d\n\n", destiny->balance);
}

void* transaction(void* accounts) {
    account** accountArray = (account**) accounts;
    int direction = rand() % 2; // If 0, FROM >>> TO. Otherwise, TO >>> FROM.

    pthread_mutex_lock(&mutex); // Since a thread has reached this area, it'll be locked to other threads.

    numOfTransactions++;

    printf("TRANSACTION NUMBER %d\n", numOfTransactions);
    printf("Executed by thread %ld\n", pthread_self());

    if(direction == 0) {
        printf("FROM >>> TO\n");
        updateBalance(accountArray[0], accountArray[1]);
    }

    else {
        printf("TO >>> FROM\n");
        updateBalance(accountArray[1], accountArray[0]);
    }

    pthread_mutex_unlock(&mutex); // Since a thread has reached this area, others will have access to the critical section.

    return NULL;
}

int main(int argc, char* argv[]) {
    if(argc != 3) { // If user doesn't give proper arguments in command line.
        fprintf(stderr, "Invalid arguments. Usage: main <number of processes> <transactions value>");
        return 1;
    }

    account from, to;
    from.balance = 100; // Starting values for FROM and TO balances.
    to.balance = 100;
    numOfTransactions = 0; // Stores number of executed transactions.
    successfulTransactions = 0; // Stores number of transactions executed successfully.
    long thread; // A regular iterator. We use long for 64-bit systems.
    
    account** argAccounts = malloc(2 * sizeof(account*));
    argAccounts[0] = &from;
    argAccounts[1] = &to;
    
    srand(time(NULL)); // Setting up random application.

    // Note: char* argv[] is an array of strings that stores command line arguments. 
    // argv[0] stores the name of the program executed.
    numOfThreads = strtol(argv[1], NULL, 10); // Casts first argument in command line to long.
    transactionAmount = strtof(argv[2], NULL); // Casts second argument in command line to float. 

    // Allocating memory for an array of threads.
    pthread_t* threads = malloc(numOfThreads * sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL); // Initing mutex for availing race conditions.

    for(thread = 0; thread < numOfThreads; thread++) { // Creating threads which will run transaction function.
        pthread_create(&threads[thread], NULL, transaction, (void*) argAccounts);
    }

    for(thread = 0; thread < numOfThreads; thread++) { // By the time a thread has completed its work, others may not.
        pthread_join(threads[thread], NULL); // So they'll wait for every single thread to complete its job.
    }

    pthread_mutex_destroy(&mutex);
    free(threads); // Frees allocated memory for threads.

    // End of transactions feedback.
    printf("\nEND OF TRANSACTIONS\n");
    printf("FROM Final Balance: %d\n", from.balance);
    printf("TO Final Balance: %d\n\n", to.balance);

    printf("%d transactions were executed.\n", numOfTransactions);
    printf("%d succesfully. %d failed.\n\n", successfulTransactions, numOfTransactions - successfulTransactions);

    return 0;
}

