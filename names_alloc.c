#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Word {
  char* word;
  struct Word* left;
  struct Word* right;
};

int main() {
  int i;
  char* temp;
  struct Word words[3];
  temp = (char*)malloc(101 * sizeof(char));
  for (i = 0; i < 3; i++) {
    scanf("%s", temp);
    words[i].word = (char*)malloc(strlen(temp) + 1 * sizeof(char));
    strcpy(words[i].word, temp);
    words[i].left = words + i;
    words[i].right = i != 2 ? words + i + 1 : NULL;
  }
  free(temp);
  struct Word* now;
  now = words;
  printf("---------\n");
  do {
    printf("now: %p | %s | right: %p\n", now, now->word, now->right);
    now = now->right;
  } while (now != NULL);
  printf("---------\n");
  return 0;
}
