#include <stdio.h>

int main(){
	char operations[200];
	int operator1, operator2;
	printf("%s", "what is the operation");
	scanf("%s", operations);
	scanf("%d %d",&operator1,&operator2);  //  &direccion
	printf("result: %d", add(operator1, operator2));
	
	return 0;
}
