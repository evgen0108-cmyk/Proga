
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

void pip(Game gam[], int n) {
    printf("\n===========================\n");
    for (int i = 0; i < n; i++) {
        printf("Game[%d]: Title: %s, Janr: %s, Year: %d, Rate: %.1f\n", 
               i + 1, gam[i].title, gam[i].janr, gam[i].year, gam[i].rate);
    }
    printf("===========================\n");
}

void zapoln(Game gam[], int n) {
    char* titles[] = {"Minecraft", "Dota 2", "CS:GO", "GTA V", "Cyberpunk"};
    char* janrs[] = {"Adventure", "MOBA", "Shooter", "Action", "RPG"};
    
    for (int i = 0; i < n; i++) {
        int t = rand() % 5;
        int j = rand() % 5;
        
        int k = 0;
        while (titles[t][k] != '\0') {
            gam[i].title[k] = titles[t][k];
            k++;
        }
        gam[i].title[k] = '\0';
        
        k = 0;
        while (janrs[j][k] != '\0') {
            gam[i].janr[k] = janrs[j][k];
            k++;
        }
        gam[i].janr[k] = '\0';
        
        gam[i].year = 2000 + rand() % 24;
        gam[i].rate = (rand() % 100) / 10.0;
    }
}

void sort(Game gam[], int n) {
    Game temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (gam[j].year > gam[j + 1].year) {
                temp = gam[j];
                gam[j] = gam[j + 1];
                gam[j + 1] = temp;
            }
        }
    }
}

