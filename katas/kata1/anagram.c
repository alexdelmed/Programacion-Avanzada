#include <stdio.h>

int main(){
    int a[6] = {8,3,1,9,11,6};
    int b[6] = {1,11,3,8,6,9};
    
    for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			if (a[i] == b[j]){
				printf("[%d", j);
			}
}
