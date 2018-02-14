#include <stdio.h>

int Maximum(int N){      

     if (N == 0)
        return 0;
     else if (N == 1)
        return 1;
     else if( (N % 2) == 0 )
        return Maximum(N/2)  ;
     else 
        return ( Maximum(N/2) + Maximum(N/2 + 1) );

}

int main(void){
 
    long i,num,max;
    long number[100001];

    for(i = 0 ; i <= 100000 ; i++){
         number[i]=Maximum(i);
    }

    while(scanf("%ld",&num)!=EOF){
       if (num==0) break;
       for(i=0,max=0;i<=num;i++)
            if(number[i]>max) max=number[i];
       printf("%ld\n",max);
    }      
return 0;
}
