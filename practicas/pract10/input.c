#include <stdio.h>

#define printDebug(...) do {                        \
	char *debug;                                    \
	debug = getenv("DEBUG");                        \
	if( debug != NULL && strcmp(debug, "y")){       \
		fprintf(stderr, format, __VA_ARGS__);       \
	}                                               \ 
}while(0)
	
int main(){
	int character;
	while(1){
		character = fgetc(stdin);  // fget   regresa un caracter
		if(feof(stdin)){  // feof    eod(ya no hay mas) quedarse ahi
			break;
		}
		fputc(character, stdout);    // fputc    imprimir la pantalla
		fprintf(stderr, "character = %c\n", character);
	}
	return 0;
}
