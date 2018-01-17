int main(){
    int a [5] = {4,3,5,2,6};
    int m = 9;
    set<int> s;
    for (int i = 0; i < 5; i++)
		for (int j = 1; j < 5; j++)
			if (a[i] + a[j] == m){
				printf( " Resultado %d + %d = %d",a[i],a[j],m);

    printf("False\n");
}
