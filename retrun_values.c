/* 
Mohammad Al-Lozy, 100829387
Faisal Akbar, 100846786
Alexy Pichette, 100822470
CRN: 74025
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The function that will be executed by the thread
void* print_message(void* arg) {
    char* message = (char*)arg;
    printf("Thread: %s\n", message);
    // Return something if needed
    return (void*)1;
}

int main() {
    pthread_t thread_id;
    const char* msg = "Hello from the new thread!";

    // Create the new thread
    // Arguments:
    // &thread_id   -> where to store the thread ID
    // NULL         -> use default thread attributes
    // print_message-> the function to run in the new thread
    // (void*)msg   -> argument to pass to print_message
    if (pthread_create(&thread_id, NULL, print_message, (void*)msg) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    // Wait for the thread to complete
    void* retval;
    if (pthread_join(thread_id, &retval) != 0) {
        perror("Failed to join thread");
        printf("Thread returned: %ld\n", (long)retval);
        return EXIT_FAILURE;
    }
    printf("Thread returned: %ld\n", (long)retval);
    printf("Main: Thread has finished execution.\n");
    return EXIT_SUCCESS;
}
