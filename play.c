#include <stdio.h>
#include <unistd.h>
#include "play.h"
#include "menu.h"

#define MAX_WIDTH 20
#define MAX_HEIGHT 15

void createPlayer(Player *p) {
    p->pos_x = 3;
    p->pos_y = 1;
    p->vel_x = 1;
    p->vel_y = 1;
    //criar um tam_x e tam_y e implementar a logica disso
}

void draw(Player p, int matrix[MAX_WIDTH][MAX_HEIGHT]) {
    printf("\n\n\n");
    for(int i=0; i<MAX_HEIGHT; i++) {
        printf("\t\t\t");
        for(int j=0; j<MAX_WIDTH; j++) {
            if(p.pos_x == j && p.pos_y == i) printf("@ ");
            else printf("o ");
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void movePlayer(Player *p) {
    if((p->pos_x >= MAX_WIDTH-1 && p->vel_x >= 0)||(p->pos_x <= 0 && p->vel_x <= 0)) p->vel_x *= -1;
    if((p->pos_y >= MAX_HEIGHT-1 && p->vel_y >= 0)||(p->pos_y <= 0 && p->vel_y <= 0)) p->vel_y *= -1;
    p->pos_x += p->vel_x;
    p->pos_y += p->vel_y;
}

void play() {
    Player p;
    createPlayer(&p);

    clearScreen();

    while(1) {
        int matrix[MAX_WIDTH][MAX_HEIGHT] = {{0}};
        draw(p, matrix);
        //espera 0,5 segundo ou 500.000 microsegundos
        usleep(500000);
        clearScreen();
        movePlayer(&p);
        
    }
}