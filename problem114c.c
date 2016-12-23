#include <stdio.h>
#include <unistd.h>

pid_t mygetpid(void);

int main() {
    printf("mygetpid = %d\n", mygetpid());
    printf("getpid = %d\n", getpid());
    return 0;
}
