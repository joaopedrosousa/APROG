#include<stdio.h>
#include"winColors.h"

int main()
{
    demoColor();
    printf("\n\n");

    setForegroundColor(1,1,1,1); // Foreground Branco
    setBackgroundColor(0,1,1,0); // Background Amarelo
    printf("Cartas Amarelas\n\n");
    printf(" 0 ");
    printf(" 1 ");
    printf(" 2 ");
    printf(" 3 ");
    printf(" 4 ");
    printf(" 5 ");
    printf(" 6 ");
    printf(" 7 ");
    printf(" 8 ");
    printf(" 9 \n\n");

    setForegroundColor(1,1,1,1); // Foreground Branco
    setBackgroundColor(0,0,0,1); // Background Azul
    printf("Cartas Azuis\n\n");
    printf(" 0 ");
    printf(" 1 ");
    printf(" 2 ");
    printf(" 3 ");
    printf(" 4 ");
    printf(" 5 ");
    printf(" 6 ");
    printf(" 7 ");
    printf(" 8 ");
    printf(" 9 \n\n");



    setForegroundColor(1,1,1,1); // Foreground Branco
    setBackgroundColor(0,0,1,0); // Background Verde
    printf("Cartas Verdes\n\n");
    printf(" 0 \n");
    printf(" 1 \n");
    printf(" 2 \n");
    printf(" 3 \n");
    printf(" 4 \n");
    printf(" 5 \n");
    printf(" 6 \n");
    printf(" 7 \n");
    printf(" 8 \n");
    printf(" 9 \n\n");


    setForegroundColor(1,1,1,1); // Foreground branco
    setBackgroundColor(0,1,0,0); // Background Vermelho
    printf("Cartas vermelhas\n\n");
    printf(" 0 \n");
    printf(" 1 \n");
    printf(" 2 \n");
    printf(" 3 \n");
    printf(" 4 \n");
    printf(" 5 \n");
    printf(" 6 \n");
    printf(" 7 \n");
    printf(" 8 \n");
    printf(" 9 \n\n");


    setBackgroundColor(1,1,1,1); // Background Branco
    setForegroundColor(0,0,0,0); // Foreground Preto
    printf("Mistura de Cartas de varias cores\n\n");
    setForegroundColor(1,1,1,1); // Foreground branco
    setBackgroundColor(0,1,0,0); // Background Vermelho
    printf(" 0 ");
    printf(" 1 ");
    printf(" 2 ");
    setForegroundColor(1,1,1,1); // Foreground Branco
    setBackgroundColor(0,0,1,0); // Background Verde
    printf(" 3 ");
    printf(" 4 ");
    printf(" 5 ");
    setForegroundColor(1,1,1,1); // Foreground Branco
    setBackgroundColor(0,0,0,1); // Background Azul
    printf(" 6 ");
    printf(" 7 ");
    printf(" 8 ");
    setForegroundColor(1,1,1,1); // Foreground Branco
    setBackgroundColor(0,1,1,0); // Background Amarelo
    printf(" 9 ");
    printf(" 0 ");
    printf(" 1 ");

    setForegroundColor(1,1,1,1); // Foreground Branco
    setBackgroundColor(0,0,0,0); // Background Preto
    getchar();
    return 0;

}
