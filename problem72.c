#include <stdio.h>
#include <string.h>

#define SIZE 1000

void init(char a[][100], int j)
{
    int i;
    for (i = 0; i < j; i++) {
        a[i][0] = '\0';
    }
}

void puta(char a[][100], int j)
{
    int i;
    for (i = 0; i < j; i++) {
        printf("%s\n", a[i]);
    }
}
void swap(char *a, char *b) {
    char temp;
    while ((*a != '\0') && (*b != '\0')) {
        temp = *a;
        *a = *b;
        *b = temp;
        a++; b++;
    }
    while (*a != '\0') {
        *b++ = *a; *a++ = '\0';
    }
    while (*b != '\0') {
        *a++ = *b; *b++ = '\0';
    }
    *a = '\0';
    *b = '\0';
}

void my_qsort(char a[][100], int i, int j)
{
    /* 適当に埋める。 */
    // ばぶるそーと
    int k, r, m;
    for (k = i; k < j; k++) {
        m = k;
        for (r = k+1; r < j; r++) {
            if (strcmp(a[m], a[r])>0) m = r;
        }
        swap(a[k], a[m]);
    }

}

void my_sort(char a[][100], int n)
{
    my_qsort(a, 0, n);
}

int main(int argc, char *argv[])
{
    char a[SIZE][100];
    int j;

    init(a, SIZE);

    for (j = 0; j < SIZE; j++) {
        if (scanf("%99s", a[j]) == EOF) break;
    }

    my_sort(a, j);

    puta(a, j);

    return 0;
}
