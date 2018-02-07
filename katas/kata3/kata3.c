#include <stdio.h>
#include <string.h>

int circle(char *moves) {
	int ver = 0;  //vertical
	int hor = 0;  //horizontal
	int size = strlen(moves); //size of array
	
	for (int i = 0; i < size; i++) {
		if(moves[i] == 'U'){
			ver ++;
		}
		if(moves[i] == 'D'){
			ver --;
		}
		if(moves[i] == 'L'){
			hor --;
		}
		if(moves[i] == 'R'){
			hor ++;
		}
	}
	if(ver == 0 && hor == 0){
		printf("true\n");
	} else {
		printf("false\n");
	}
	return 0;
}

int main(){
  char moves[] = "UDLRU";
  circle(moves);
}
