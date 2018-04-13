#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unisdt.h>
#include <sys/mman.h>

typedef struct s
{
    char name[20];
    char lastName[20];
    unsigned int id;
    unsigned char cal;
} Student;

int main(){
    char *fileName = "studentDb.data";
    int fd = open(fileName, O_RDWR);
    int id;
    char name[20];
    Student *pAvanzada = (Student *) mmap(NULL, 5*sizeof(Student), PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, fd, 0);
    printf("First Student %s \n", pAvanzada[0].name);
    strcpy(pAvanzada[1].name, "Pedro");
    printf("Second Student %s \n", pAvanzada[1].name);
    for(int i = 0; i < 4; i++){
        printf("Provide id, new name \n");
        scanf("%d %s", &id, name);
        strcpy(pAvanzada[id].name, name);
        msync(pAvanzada, 5*sizeof(Student))
    }
    munmap(pAvanzada, 5*sizeof(Student), MS_SYNC);
    close(fd);
    return 0;
}
