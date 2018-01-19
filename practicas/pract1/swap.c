#include <stdio.h>

int swap_no(int a, int b) {
	int t;
	t = b;
	b = a;
	a = t;
	return 0;
}

int swap(int *a, int *b){
	int t;
	t = *b;
	*b = *a;
	*a = t;
	return 0;
}

int main(){
	int i = 5, j = 10;
	swap_no(i, j);
	printf("i = %d, j = %d \n");
	swap(&i, &j);
	printf("i = %d, j = %d \n");
	return 0;
}
