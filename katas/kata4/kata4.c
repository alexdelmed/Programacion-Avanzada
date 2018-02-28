#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool ispoint(int c) {  // funciones para detectar si es punto
    return ((c == '.')); }

bool ise(int c) {   // E
        return ((c == 'e')); }

bool isdigit(int c) {   // digito
        return (c >= '0' && c <= '9'); }

int validNumb(char *s) {
  int size = strlen(s);
  int countNum = 0;
  bool hasPoint = false, hasE = false, checkNum = false;
  for (int i = 0; i < size; i++) { // revisa cada caracter
    if(isdigit(s[i])){
      checkNum = true;
    }

      else if(ispoint(s[i]) && hasPoint == false && hasE == false)) { // existe un solo punto
      checkNum = false;  // de un punto sigue un numero
      hasPoint = true;
    }

    else if(ise(s[i]) && checkNum == true) && !ispoint(s[i-1])){  // solo existe una "e"
      checkNum = false;  //una e debe ser seguida por un numero
      hasE = true;

    }

    else {  // en caso que no aplique ningun caso, terminar
      printf("%s\n","False");
      return 0;
    }
  }


  if (checkNum){  // regresa el resulado final
    printf("%s\n", "True"); // para imprimirlo
  } else {
    printf("%s\n","False");
  }
  return 0;
}

int main(){
  char a[] = "3e10";
  validNumb(a);
  return 0;
}
