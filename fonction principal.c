#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_tableau(int tableau[10][10]) {
    srand(time(NULL)); 
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tableau[i][j] = rand() % 4; 
        }
    }
}

int main() {
    int tableau[10][10];
    
    create_tableau(tableau);
    
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
