#include <stdio.h>
#include <pthread.h>
 
void decrement(int *ptr);
 
static int counter;
 
static void *my_entrypoint(void *data) {
    for(int i = 0; i < 100000000; ++i) {
        decrement(&counter);
    }
    return NULL;
}
 
int main() {
    pthread_t thread1, thread2;
    counter = 200000000;
    pthread_create(&thread1, NULL, my_entrypoint, NULL);
    pthread_create(&thread2, NULL, my_entrypoint, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("counter = %d\n", counter);
    return 0;
}
