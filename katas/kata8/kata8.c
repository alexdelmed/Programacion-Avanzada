#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int solution(int flight_length, int movie_lengths[]) {
  int arrsize = sizeof(movie_lengths)/sizeof(int);
  for (int i = 0; i < arrsize; i++) {
  	int first_movie = movie_lengths[i];
    for (int j = 1; j < arrsize; j++) {
      //not to choose the same movie twice
      if(j == i) {
        continue;
      }
      //if we find a matching second movie
    	if (first_movie + movie_lengths[j] == flight_length) {
          return 1;
      }
    }
  }
  return 0;
}

int main() {
  int flight_length = 240;
  int movie_lengths[] = {90, 160, 70, 210, 80, 60, 190};
  int result;

  result = solution(flight_length,movie_lengths);
  printf("The result: %s \n", result ? "true" : "false");

  return 0;
}
