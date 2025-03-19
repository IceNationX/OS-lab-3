/*      Rida Siddiqi -100825212
	Ishmeet kaur -100809450
 	Muhammad Mujtaba Madad -100790195
 	-
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_message(void* arg) {
    char* message = (char*)arg;
    printf("Thread: %s\n", message);
    return (void*)1;
}

int main() {
    pthread_t thread;
    const char* msg = "Hello from the new thread!";
    pthread_create(&thread, NULL, print_message, (void*)msg);
    void* retval;
    pthread_join(thread, &retval);
    printf("Thread returned: %ld\n", (long)retval);
    printf("Main: Thread has finished execution.\n");
    return 0;
}
