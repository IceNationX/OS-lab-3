/*      Rida Siddiqi -100825212
	Ishmeet kaur -100809450
 	Muhammad Mujtaba Madad -100790195
 	-
 */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// hello world  main function that use thread concept with to delay the output
void* printHello(void* arg) {
// make for loop to delay the output using the sleep function
    for (int i = 0; i < 5; i++) {
        printf("Hello from thread\n");
        sleep(1);
    }
    // printf("Hello from thread\n");
    return NULL;
}

// hello world  main function that use thread concept with to delay the output
void* printHello2(void* arg) {
// make for loop to delay the output using the sleep function
    for (int i = 0; i < 5; i++) {
        printf("Hello from thread 2\n");
        sleep(2);
    }
    // printf("Hello from thread\n");
    return NULL;
}
int main() {
    pthread_t thread[2];

    pthread_create(&thread[0], NULL, printHello, NULL);
    pthread_create(&thread[1], NULL, printHello2, NULL);
    for (int i = 0; i < 2; i++) {
        pthread_join(thread[i], NULL);
    }
    // pthread_join(thread, NULL);
    printf("Hello from main\n");
    return 0;
}
