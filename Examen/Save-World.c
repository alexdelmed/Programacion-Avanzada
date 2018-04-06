#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    int a,b,j,len,l,flag;
    char p[1000001],v[1000001];   //maximos, como se pide en del programa p, v
    scanf("%d",&a);     //buscar
    while(t--)
    {
        int a=0;
        scanf("%s",p);scanf("%s",v);   //buscar
        len = strlen(p);l = strlen(v);
        
        for(i=0;i<=(len-l);i++)
        {
            flag=0;     //bandera que marca
            for(j=0;j<l;j++)
                if(p[b+j]==v[j])    //Verificacion
                   flag++;
                
            if((flag==l)||(flag==(l-1)))
            {
                a=1;printf("%d ",b);   // en caso que correcto los imprime
            }   
        }
        if(!a) printf("There Is No Match!");  // en caso que incorrecto, escribe no match
        printf("\n");
    }    
    return 0;
}    