#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct point {
    float longueur;
    float largeur;
};

void create_tableau(int tab[size][size],number) {
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tab[i][j] = rand() % number; 
        }
    }
}

int main() {
    struct point p; 
    struct point c; 
    int size, number;
    printf("quel est la taille");
    do{ scanf("%f", &size);
       if (size<0 && size%1 !=0){
           printf("donnez une valeur qui marche");}
      }while(size<0 && size%1 != 0); 
    printf("Combien d'élément différent voulez-vous?");
    do{scanf("%f", &number);
       if (number<0 && number%1 !=0){
           printf("donnez une valeur qui marche");}
       if (number<4 || number>6){
           printf("donnez une valeur qui marche");}
      }while(number<4 && number%1 !=0 && number>6);
    
    
    int tableau[size][size];
    do {create_tableau(tab,number);
        
    
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tableau[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
