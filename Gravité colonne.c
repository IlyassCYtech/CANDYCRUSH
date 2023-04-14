#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void graviteColonne(int tab, int r, int v, int number){
    srand(time(NULL));
	int count=0;
	int j=v;
	int i=r;
	while(tab[i][j]==0){
		count++;
		i++;
	}
	i=r+(count-1);
	for(i, j; i>(count-1) ; i--){
		tab[i][j]=tab[i-count][j];
    	}
    	for(int d=0, j; d<=count ; i++){
        	tab[d][j]=rand()% number;
    	}
}
