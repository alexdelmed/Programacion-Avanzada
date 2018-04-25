#include <stdio.h>
#include <stdbool.h>

int firstZero(int num) {  //regresar al primer cero
  int count = 0;
  while ((num & 128) != 0) {  //operacion binaria AND para sumar
    count++;
    num = num << 1;  //moverlo a la izquierda
  }
  return count > 4 ? -1 : count;
}

bool utf8V(int* data) {
  int dataSize = sizeof(data)/sizeof(int);
    int count = 0;
    for(int i = 0; i < dataSize; i++){
      int zero = firstZero(data[i]);
      if (zero == -1){
        return false;  //regresar que no se puede
      }
      else if (zero == 1 && count-- <= 0){
        return false;
      }
      else if (zero > 1) {
        if (count > 0){
          return false;
        }
        count = zero - 1;
      }
      if (i == dataSize - 1 && count != 0){
        return false;
      }
    }
    return true;
}

int main() {
  int data1[] = {197,130,1};   //escribir numeros
  bool result = utf8V(data1);  // ejecutar
  printf("[197,130,1] Result: %s \n", result ? "true" : "false");  //mostrar resultado

  return 0;
}
