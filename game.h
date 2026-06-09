#ifndef GAME_H
#define GAME_H

typedef struct {
    char title[50];
    char janr[50];
    int year;
    float rate;
} Game;

void pip(Game gam[], int n);
void zapoln(Game gam[], int n);
void sort(Game gam[], int n);

#endif
