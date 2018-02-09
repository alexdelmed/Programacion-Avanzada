all:
	gcc main.c -o speed.exe

main.o: main.c
	gcc -c main.c

runtest: main.o
	gcc main.c -o speed.exec
	./testmain.tcl ./speed.exe
