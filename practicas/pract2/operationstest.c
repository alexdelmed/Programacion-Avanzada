#include <stdio.h>
#include "operations.h"

int printTestMassage(int testResult, 
					char *passageMessage, 
					char *failedMessage){
	if(testResult)
	{
		printf("%s\n", passageMessage);
	} 
	else
	{
		printf("%s\n", failedMessage);
	}
}
int main() {
	// test addition
	int a = 2147483644;
	int b = 2;
	int result = add(a,b);
	int expected = a + b;
	printTestMassage(result == expected, 
					"Addition test passed", 
					"Addition test failed");
	
	// test substaction
	int d = 2147483644;
	int f = 2;
	int resultSubstraction = substraction(d,f);
	int expectedSubstraction = d - f;
	
	printTestMassage(resultSubstraction  == expectedSubstraction, 
					"Addition test passed", 
					"Addition test failed");
	
	return 0;
}
