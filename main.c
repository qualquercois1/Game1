#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "menu.h"
#include "play.h"

void setRawMode(int enable) {
    static struct termios oldt, newt;
    if (enable) {
        // Salva as configurações antigas do terminal
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        // Desativa o buffering e o eco de caracteres
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        // Restaura as configurações antigas do terminal
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

void hideCursor() {
    printf("\033[?25l");
    fflush(stdout); 
}
void showCursor() {
    printf("\033[?25h");
    fflush(stdout);
}

int main() {
    clearScreen();
    hideCursor();

    char c;

    setRawMode(1);

    int menuOption = 1;

    while(1) {
        menu(menuOption);
        c = getchar();
        if(c == '\033') {
            getchar();
            c = getchar();
            //seta para baixo
            if(c == 'B' && menuOption < 3) {
                menuOption++;
            } 
            //seta para cima
            else if(c == 'A' && menuOption > 1) {
                menuOption--;
            }
        }
        else if (c == ' ' || c == '\n') {
            if(menuOption == 1) {
                play();
            }
            else if (menuOption == 2) {
                continue;
            }
            else if (menuOption == 3) {
                break;
            }
        }
    }

    clearScreen();
    setRawMode(0);
    showCursor();

    return 0;
}