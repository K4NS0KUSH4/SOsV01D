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
account from, to;
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

void* transaction(void* threadNum) {
    long thrNum = (long) threadNum;
    int direction = rand() % 2; // If 0, FROM >>> TO. Otherwise, TO >>> FROM.

    pthread_mutex_lock(&mutex); // Since a thread has reached this area, it'll be locked to other threads.

    if( (*(&from)).balance != 0 && (*(&to)).balance != 0) { // If accounts have no balance, no transaction will be executed
        numOfTransactions++; // Incremeting number of transactions for posterior feedback

        printf("TRANSACTION NUMBER %d\n", numOfTransactions);
        printf("Executed by thread (%ld) ID: %ld\n", thrNum, pthread_self());

        if(direction == 0) { // FROM >>> TO transaction
            printf("FROM >>> TO\n");
            updateBalance(&from, &to);
        }

        else { // TO >>> FROM transaction
            printf("TO >>> FROM\n");
            updateBalance(&to, &from);
        }
    }

    pthread_mutex_unlock(&mutex); // Since a thread has reached this area, others will have access to the critical section.

    return NULL;
}

int main(int argc, char* argv[]) {
    if(argc != 5) { // If user doesn't give proper arguments in command line.
        fprintf(stderr, "Invalid arguments. Usage: <program> <number of threads> <transactions value> <FROM balance> <TO balance>\n\n");
        return 1;
    }

    numOfTransactions = 0; // Stores number of executed transactions.
    successfulTransactions = 0; // Stores number of transactions executed successfully.
    long thread; // A regular iterator. We use long for 64-bit systems.
    
    account** argAccounts = malloc(2 * sizeof(account*));
    argAccounts[0] = &from;
    argAccounts[1] = &to;
    
    srand(time(NULL)); // Setting up random application.

    // Note: char* argv[] is an array of strings that stores command line arguments. 
    // argv[0] stores the name of the program executed.
    int numOfThreads = strtol(argv[1], NULL, 10); // Casts first argument in command line to long integer.
    transactionAmount = strtol(argv[2], NULL, 10); // Casts second argument in command line to long integer.
    from.balance = strtol(argv[3], NULL, 10); // Casts third argument in command line to long integer.
    to.balance = strtol(argv[4], NULL, 10); // Casts fourth argument in command line to long integer.

    // Allocating memory for an array of threds.
    pthread_t* threads = malloc(numOfThreads * sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL); // Mutex for availing race conditions.

    for(thread = 0; thread < numOfThreads; thread++) { // Creating threads which will run transaction function.
        pthread_create(&threads[thread], NULL, transaction, (void*) thread);
    }

    for(thread = 0; thread < numOfThreads; thread++) { // By the time a thread has completed its work, others may not.
        pthread_join(threads[thread], NULL); // So they'll wait for every single thread to complete its job.
    }

    pthread_mutex_destroy(&mutex); // Destroying mutex used for race condition solving.
    free(threads); // Frees allocated memory for threads.

    // End of transactions feedback.
    printf("\nEND OF TRANSACTIONS\n");
    printf("FROM Final Balance: %d\n", from.balance);
    printf("TO Final Balance: %d\n\n", to.balance);

    printf("%d transactions were executed.\n", numOfTransactions);
    printf("%d succesfully. %d failed.\n\n", successfulTransactions, numOfTransactions - successfulTransactions);

    if((*(&from)).balance != 0 && (*(&to)).balance != 0) {
        printf("%d transactions weren't enough to reduce balances to zero.\n\n", numOfTransactions);
    }

    return 0;
}  

