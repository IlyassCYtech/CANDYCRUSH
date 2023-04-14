#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void graviteColonne(int tab, int *r, int *v, int number){
    srand(time(NULL));
	int j=v;
	int i=r+2;
	for(i, j; i>2 ; i--){
		tab[i][j]=tab[i-3][j];
    }
    	for(int d=0, j; d<3 ; i++){
        	tab[d][j]=rand()% number;
    	}
}
