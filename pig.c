#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str[10] = "Hello, pig";
  char *a = str;
  printf("%c\n", *a);
  return 0;
}
