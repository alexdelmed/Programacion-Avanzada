#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "hash.h"

bool ispunctuation(int c) { // saber si es signo
    return ((c == '.')||(c == ':')||(c == '!')||(c == '?'));
}

bool isletter(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char * getword(char * line){
    int size = 0;
    char *c;
    for (c = line; isletter(*c); ++c){
        ++size;
    }
    char *word = malloc(sizeof(char) * (size+1));
    for (int i = 0; i < size; ++i){
        word[i] = tolower(line[i]);
    }
    word[size] = '\0';
    return word;
}

static int wordcloud(char *text){
  HashInt myHash;
  hashInit(&myHash, 55);//El string de 52 palabras
  char *c;
  for (c = text; *c != '\0'; ++c) {
    if(ispunctuation(*c)){
      ++c;
      continue;
    }
    if (isletter(*c)){
        char *word = getword(c);
        int *result = hashGet(&myHash, word);
        if (result == NULL){
          hashInsert(&myHash, word, 1);
        } else {
          hashInsert(&myHash, word, *result++);
          free(word);
        }

        while (isletter(*c)){
            ++c;
          }
        }
      }
      for (int i = 0; i < myHash.size; ++i)
      {
        for (int j = 0; j < myHash.data[i].length; ++j)
        {
          char *word = myHash.data[i].elements[j].key;
          int value = myHash.data[i].elements[j].value;
          if(word != NULL){
            printf("%s = %d\n", word, value);
          }
        }
      }
  }

int main(){
  char test[] = "Cuanto más lees, más cosas sabrás. Cuantas más cosas aprendas, a más lugares viajaras.-Dr. Seuss";
  wordcloud(test);
  return 0;
}
