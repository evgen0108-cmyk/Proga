
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

#define N 5

int main() {
    srand(time(NULL));
    
    Game gam[N];
    
    zapoln(gam, N);
    
    printf("ДО СОРТИРОВКИ:");
    pip(gam, N);
    
    sort(gam, N);
    
    printf("ПОСЛЕ СОРТИРОВКИ:");
    pip(gam, N);
    
    return 0;
}

