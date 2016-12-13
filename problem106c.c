#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t mystrlen(const char* s);

struct testcase {
    const char* s;
    size_t result;
};

const struct testcase tests[] = {
    {"foo", strlen("foo")},
    {"", strlen("")},
    {"\n\0\n", strlen("\n\0\n")}
};

int main() {
    for (int i=0; i<(int)(sizeof(tests)/sizeof(*tests)); i++) {
        size_t ret = mystrlen(tests[i].s);
        printf("mystrlen(%s)==%zu\n", tests[i].s, ret);
        if (tests[i].result == ret) puts("ok");
        else puts("ng");
    }
    return 0;
}
