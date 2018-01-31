#include <stdio.h>
#include <string.h>

int strongPasswordChecker(char *s) {
  int size = strlen(s);
  int repeatChar = 0, countChar = 0, haveLower = 0, haveUpper = 0, haveDigit = 0, changes = 0;
  char prevChar = (char) 0, nextChar;
  for (int i = 0; i < size; i++) {
    nextChar = s[i];   //Para revisar caracteres que se repiten
    if(nextChar == prevChar){
      countChar++;
    } else {
      countChar = 0;
    }
    if(countChar >= 2){
      repeatChar++;
    }
    prevChar = s[i];

    if(islower(s[i])){ //Para revisar si es minuscula
      haveLower++;
    }

    
    if(isupper(s[i])){  //Para revisar si es mayuscula
      haveUpper++;
    }

    
    if(isdigit(s[i])){  //Para revisar si tiene digito
      haveDigit++;
    }
  }
  
  changes = repeatChar;  //contar los cambios necesarios
  if(haveLower == 0){
    changes++;
  }
  if(haveUpper == 0){
    changes++;
  }
  if(haveDigit == 0){
    changes++;
  }
  if(size < 6){   //Si no, revisar casos segun tamaño de contraseña, si faltan o sobran caracteres aun con los cambios
    if(size+changes < 6){   //En el caso de que aun con cambios sigue teniendo menos de 6 caracteres es necesario contar el numero de caracteres a agregar
      return ((-1)*((size+changes)-6)) + changes;
    } else {
      return changes;
    }
  }
  if(size > 20){
    if(size-changes > 20){ //En el caso de que aun con cambios sigue teniendo más de 20 caracteres es necesario contar el numero de caracteres a borrar
      return ((size-changes)-20) + changes;
    } else {
      return changes;
    }
  }
  if(changes == 0 && size >= 6 && size <= 20){  //Si la contraseña cumple con los criterios regresar 0
    return 0;
  }
  return changes; //Si la contraseña se encuentra en el intervalo de tamaño, solo regresar el numero de cambios
}

int islower(int c) {  // funciones para detectar si es minuscula, mayuscula o digito
    return ((c >= 'a' && c <= 'z')); }

int isupper(int c) {
        return ((c >= 'A' && c <= 'Z')); }

int isdigit(int c) {
        return (c >= '0' && c <= '9'); }

int main(){
  char a[] = "Corr48se";
  printf("Minimum change(s) needed: %i\n", strongPasswordChecker(a));
}
