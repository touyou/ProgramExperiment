#include <stdio.h>
#include <stdlib.h>

int mystrcmp(const char *s1, const char *s2);

struct testcase {
  const char *s1;
  const char *s2;
  int result;
};

const struct testcase tests[] = {
  {"app", "apple", -1},
  {"pine", "apple", 1},
  {"foo\0bar", "foo", 0},
  {"string", "string", 0},
  {"desert", "dessert", -1},
  {"compliment", "complement", 1},
  {"", "orange", -1},
  {"kiwi", "", 1},
  {"", "", 0}
};

int main() {
  /* tests の各テストを実行し、結果を表示する。失敗したらexit */
  int i;
  for(i = 0; i < (int)(sizeof(tests) / sizeof(*tests)); ++i) {
    int r = mystrcmp(tests[i].s1, tests[i].s2);
    printf("mystrcmp(\"%s\", \"%s\") = %d\n", tests[i].s1, tests[i].s2, r);
    if(r < 0) r = -1;
    if(r > 0) r = 1;
    if(r != tests[i].result) {
      printf("%d != %d\n", r, tests[i].result);
      exit(1);
    }
  }
  return 0;
}

