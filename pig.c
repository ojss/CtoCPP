#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char str[10] = "Hello, pig";
  char *a = strtok(str, ";");
  printf("%s\n", a);
  return 0;
}
