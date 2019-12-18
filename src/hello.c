#include <stdio.h>

int main() {
  int i;
  for (i = 0; i < 100000000; i++)
    i++;
  printf("... %d\n", i);
  printf("Hello, world!\n");
}

