#include <stdio.h>
#include <unistd.h>

int main(){
    int pid;
    pid = fork();
    if(pid == 0){
        exec("home/Users/drag/Documents/advProg/practicas/practica12/hijo.exe", "hijo.exe", (char *)0);
        printf("Hola soy el hijo\n");
    } else {
        printf("Hola soy el padre\n");
    }
    
    return 0;
}
