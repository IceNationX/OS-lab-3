/* Group 13  */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* printHello(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Hello from thread\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, printHello, NULL);
    pthread_join(thread, NULL);
    printf("Hello from main\n");
    return 0;
}
