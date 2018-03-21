#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    scanf("%d%d", &W, &H);
    int N; // maximum number of turns before game over.
    scanf("%d", &N);
    int X;
    int Y;
    scanf("%d%d", &X, &Y);

    int X0 = X;
    int Y0 = Y;
    int X1 = W;
    int Y1 = H;
    int prevY = 0;
    int Yrepeated = 0;
    int prevX = 0;
    int Xrepeated = 0;
    int temp = 0;
    int done7 = 0;

    // game loop
    while (1) {
        char bombDir[4]; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        scanf("%s", bombDir);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        fprintf(stderr, "Turns: %d \n", N);
        fprintf(stderr, "bombDir: %s \n", bombDir);
        fprintf(stderr, "Batman position (%d,%d)\n", X, Y);
        fprintf(stderr, "X0 Y0 (%d,%d)\n", X0, Y0);
        fprintf(stderr, "X1 Y1 (%d,%d)\n", X1, Y1);

        if(strstr(bombDir, "U") != NULL){
            fprintf(stderr, " U worked\n");
            Y1 = Y - 1;
        }else if (strstr(bombDir, "D") != NULL){
            fprintf(stderr, " D worked\n");
            Y0 = Y + 1;
        }

        if(strstr(bombDir, "L") != NULL){
            fprintf(stderr, " L worked\n");
            X1 = X - 1;
        } else if (strstr(bombDir, "R") != NULL){
            fprintf(stderr, " R worked\n");
            X0 = X + 1;
        }

        fprintf(stderr, "X0 Y0 (%d,%d)\n", X0, Y0);
        fprintf(stderr, "X1 Y1 (%d,%d)\n", X1, Y1);
        fprintf(stderr, "prevY %d\n", prevY);

        X = (X0 + X1) / 2;
        Y = (Y0 + Y1) / 2;

        if(Yrepeated == 2){
            Y1 = Y;
            Y = temp;
            Y0 = temp;
            Yrepeated++;
        } else if (Yrepeated > 5){
         Yrepeated = 0;
        }

        if(prevY == Y){
         Yrepeated++;
        }

        if(Xrepeated == 5){
            X1 = Y;
            X = temp;
            X0 = temp;
            Xrepeated++;
        } else if (Xrepeated > 5){
         Xrepeated = 0;
        }

        if(prevX == X){
         Xrepeated++;
        }

        if(N == 7 && !done7){
            Y1 = H/2;
            Y = temp + 1;
            Y0 = temp + 1;
            X1 = temp;
            X = temp + 1;
            X0 = temp + 1;
            done7++;
        }
        fprintf(stderr, "X0 Y0 (%d,%d)\n", X0, Y0);
        fprintf(stderr, "X1 Y1 (%d,%d)\n", X1, Y1);
        fprintf(stderr, "prevY %d\n", prevY);
        prevY = Y;
        prevX = X;
        printf("%d %d\n", X, Y); // the location of the next window Batman should jump to.
    }

    return 0;
}
