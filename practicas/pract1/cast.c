#include <stdio.h>

int main() {
	int a = 2147483647;
	long int d = (long)a * a;
	int j = 0, k = 0, l = 0;
	int *p;
	float f = 4.67;
	int e = 4;
	int c = (int)f + e;
	p = &a;
	p++;
	*p = 5555;

	//printf("a = %d, d = %ld, f = %f, e = %d, c = %d \n",a,d,f,e,c);  // d, i = entero
	//printf("a = %p",&a); // da ubicacion de a en archivo
	printf("a = %d, p = %p, j = %d, k = %d, l = %d \n",a,p,j,k,l);
	return 0;
}
