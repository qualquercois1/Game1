#ifndef __PLAY_H
#define __PLAY_H

#define MAX_WIDTH 20
#define MAX_HEIGHT 15

typedef struct {
    int pos_x;
    int pos_y;
    int vel_x;
    int vel_y;
} Player;

void createPlayer(Player *p);
void draw(Player p, int matrix[MAX_WIDTH][MAX_HEIGHT]);
void clearScreen();
void movePlayer(Player *p);
void play();

#endif