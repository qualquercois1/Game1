#include <stdio.h>
#include "menu.h"

void drawMenu(int options) {
    //vermelho  
    printf("\033[31m");  
    printf("\tTitulo");
    //padrao
    printf("\033[0m");
    printf("\n\n\n\t");
    //botao de start
    if(options == 1)  {
        //amarelo
        printf("\033[33m");
        printf("> Start <");
        //padrao
        printf("\033[0m");
    }
    else printf("  Start  ");
    printf("\n\n\t");
    //botao de options
    if(options == 2) {
        //amarelo
        printf("\033[33m");
        printf("> Options <");
        //padrao
        printf("\033[0m");
    }
    else printf("  Options  ");
    printf("\n\n\t");
    //botao de exit
    if(options == 3) {
        //amarelo
        printf("\033[33m");
        printf("> Exit <");
        //padrao
        printf("\033[0m");
    }
    else printf("  Exit  ");
    printf("\n\n\n");
}

void clearScreen() {
    printf("\033[H\033[J");
}

void menu(int option) {
    clearScreen();
    drawMenu(option);
}