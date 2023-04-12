#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int premier_vérificateur(int tab[][],int size) {
    int valeur = 0; 
    
   
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-2; j++) {
            if (tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2]) {
                valeur = 1;
              
                }
        }
    }
    
   
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size-2; i++) {
            if (tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j]) {
                valeur = 1; 
                }
        }
    }
    
    return valeur;
}




struct point {
    int longueur;
    int largeur;
    int longueur2;
    int largeur2;
};

void demandeur(struct point *p, int size) {
    do {
        printf("Quelles sont les coordonnées du point en longueur ? ");
        scanf("%f", &(p->longueur));
    } while (p->longueur < 0 || p->longueur >= size || p->longueur != (int)p->longueur);

    do {
        printf("Quelles sont les coordonnées du point en largeur ? ");
        scanf("%f", &(p->largeur));
    } while (p->largeur < 0 || p->largeur >= size || p->largeur != (int)p->largeur);

    do {
        printf("Quelles sont les coordonnées du point 2 en longueur ? ");
        scanf("%f", &(p->longueur2));
    } while (p->longueur2 < 0 || p->longueur2 >= size || p->longueur2 != (int)p->longueur2);

    do {
        printf("Quelles sont les coordonnées du point 2 en largeur ? ");
        scanf("%f", &(p->largeur2));
    } while (p->largeur2 < 0 || p->largeur2 >= size || p->largeur2 != (int)p->largeur2);
}





void inverse(int tab[][], int size, struct point *p) {
    int r = 0;
    int h = 0;
    int* tab1 = (int*)malloc(size * sizeof(int));
    
    do {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                tab1[i][j] = tab[i][j];
            }
        }
        
        demandeur(&p, size);
        int temp = tab1[p->longueur][p->largeur];
        tab1[p->longueur][p->largeur] = tab1[p->longueur2][p->largeur2];
        tab1[p->longueur2][p->largeur2] = temp;
    
        r = premier_vérificateur(tab1, size);
        if (r == 1) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    tab[i][j] = tab1[i][j];
                }
            }
            h = 1;
        }        
    } while (r == 0);
}

void create_tableau(int tab[size][size],int size, int number) {
    srand(time(NULL)); 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            tab[i][j] = rand() % number; 
        }
    }
}

int main() {
    struct point p; 
    int size, number, r;
    printf("quel est la taille");
    do{ scanf("%d", &size);
       if (size<0 && size%1 !=0){
           printf("donnez une valeur qui marche");}
      }while(size<0 && size%1 != 0); 
    printf("Combien d'élément différent voulez-vous?");
    do{scanf("%d", &number);
       if (number<0 && number%1 !=0){
           printf("donnez une valeur qui marche");}
       if (number<4 || number>6){
           printf("donnez une valeur qui marche");}
      }while(number<4 && number%1 !=0 && number>6);
    
    int* tab = (int*)malloc(size * sizeof(int));
    do {
        create_tableau(tab, size, number);
        r = premier_vérificateur(tab, size);
    } while(r == 1);
    
    inverse(tab, size, p);   
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
