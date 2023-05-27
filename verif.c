#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>


#include "Tab.h"

// the function checks the combinations
int supprimeur(int *score, int rows, int columns,int tab[MAX_SIZE][MAX_SIZE],int *xcoord,int *ycoord, int *xcoord2, int *ycoord2, int* bomb){
  	int typerows, typecolumns;
  	int reaction=0;
	typerows =verificateurcontinuligne(rows,columns, tab,xcoord,ycoord);
  	typecolumns = verificateurcontinucolonne(rows,columns,tab,xcoord2,ycoord2);
    switch(typecolumns){
      case 3:
      tab[*xcoord2%rows][*ycoord2]=0;
    	tab[(*xcoord2+1)%rows][*ycoord2]=0;
    	if(*bomb==1){
    	tab[(*xcoord2+2)%rows][*ycoord2]=0;
    	}
    	if(*bomb==0){
    	tab[(*xcoord2+2)%rows][*ycoord2]=9;
    	*bomb=1;
    	}
    	tab[(*xcoord2+3)%rows][*ycoord2]=0;
    	tab[(*xcoord2+4)%rows][*ycoord2]=0;
    	*score =*score +5;
    	reaction=1;
      break;
    	
      case 2:
    	tab[*xcoord2%rows][*ycoord2]=0;
    	tab[(*xcoord2+1)%rows][*ycoord2]=0;
    	tab[(*xcoord2+2)%rows][*ycoord2]=0;
    	tab[(*xcoord2+3)%rows][*ycoord2]=0;
    	*score =*score +4;
    	reaction=1;
      break;
      case 1:
  	 	tab[(*xcoord2)%rows][*ycoord2]=0;
    	tab[(*xcoord2+1)%rows][*ycoord2]=0;
    	tab[(*xcoord2+2)%rows][*ycoord2]=0;
    	*score =*score +3;
    	reaction=1;
  	  break;
    }

      switch(typerows){
  
        case 3:
    	tab[*xcoord][*ycoord%columns]=0;
    	tab[*xcoord][(*ycoord+1)%columns]=0;
    	if(*bomb==1){
    	tab[*xcoord][(*ycoord+2)%columns]=0;
    	}
    	if(*bomb==0){
    	tab[*xcoord][(*ycoord+2)%columns]=9;
    	*bomb=1;
    	}
    	tab[*xcoord][(*ycoord+3)%columns]=0;
    	tab[*xcoord][(*ycoord+4)%columns]=0;
    	*score =*score +5;
    	reaction=1;
  	  break;
      case 2:
    	tab[*xcoord][*ycoord%columns]=0;
    	tab[*xcoord][(*ycoord+1)%columns]=0;
    	tab[*xcoord][(*ycoord+2)%columns]=0;
    	tab[*xcoord][(*ycoord+3)%columns]=0;
    	*score =*score +4;
    	reaction=1;
  	  break;
      case 1:
  	 	tab[*xcoord][(*ycoord)%columns]=0;
    	tab[*xcoord][(*ycoord+1)%columns]=0;
    	tab[*xcoord][(*ycoord+2)%columns]=0;
    	*score =*score +3;
    	reaction=1;
      break;
  	}
	return reaction;
}
// the function checks the combinations
int verificateurcontinuligne(int rows,int columns,int tab[MAX_SIZE][MAX_SIZE],int *xcoord,int *ycoord) {
	int valeur = 0; 
    *xcoord=0;
    *ycoord=0;
  	//ligne
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (tab[i][j%columns] == tab[i][(j+1)%columns] && tab[i][j%columns] == tab[i][(j+2)%columns] && tab[i][j%columns] == tab[i][(j+3)%columns]&& tab[i][j%columns] == tab[i][(j+4)%columns] && tab[i][j%columns] !=0) {
                valeur = 3;
                *xcoord=i;
                *ycoord=j;
                return valeur;
            }
        }
    }
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (tab[i][j%columns] == tab[i][(j+1)%columns] && tab[i][j%columns] == tab[i][(j+2)%columns] && tab[i][j%columns] == tab[i][(j+3)%columns] && tab[i][j%columns] && tab[i][j%columns] !=0) {
            valeur = 2;
            *xcoord=i;
            *ycoord=j;
            return valeur;
            }
        }
    }
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (tab[i][j%columns] == tab[i][(j+1)%columns] && tab[i][j%columns] == tab[i][(j+2)%columns] && tab[i][j%columns] !=0) {
                valeur = 1;
                *xcoord=i;
                *ycoord=j;
                return valeur;
            }
        }
    }
	return valeur;    
}
// the function checks the combinations 
int verificateurcontinucolonne(int rows,int columns, int tab[MAX_SIZE][MAX_SIZE],int *xcoord2,int *ycoord2) {
	int valeur = 0;
	*xcoord2=0;
	*ycoord2=0;
    //colonne
   	for (int j = 0; j < columns; j++) {
        for (int i = 0; i <rows; i++) {
            if (tab[i%rows][j] == tab[(i+1)%rows][j] && tab[i%rows][j] == tab[(i+2)%rows][j] && tab[i%rows][j] == tab[(i+3)%rows][j] && tab[i][j] == tab[(i+4)%rows][j] && tab[i%rows][j] !=0) {
                valeur = 3;
                *xcoord2=i;
                *ycoord2=j;
                return valeur;
            }
        }
    }
	for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            if (tab[i%rows][j] == tab[(i+1)%rows][j] && tab[i%rows][j] == tab[(i+2)%rows][j] && tab[i%rows][j] == tab[(i+3)%rows][j] && tab[i%rows][j] !=0) {
                valeur = 2;
                *xcoord2=i;
                *ycoord2=j;
                return valeur;
            }
        }
    }
	for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            if (tab[i%rows][j] == tab[(i+1)%rows][j] && tab[i%rows][j] == tab[(i+2)%rows][j] && tab[i%rows][j] !=0) {
                valeur = 1;
                *xcoord2=i;
                *ycoord2=j;
                return valeur;
            }
        }
    }
    return valeur;
}
// This fonction verifie a compatibility
bool verifTab(int rows,int columns, int tab[MAX_SIZE][MAX_SIZE]) {
  	for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < columns; j++) {
      		if (tab[i][(j+columns)%columns] == tab[i][(j+columns+1)%columns] && tab[i][(j+columns)%columns] == tab[i][(j +columns + 2)%columns] &&
          tab[i][j%columns] != 0) {
        		return true;
      		}
    	}
  	}
	for (int j = 0; j < columns; j++) {
    	for (int i = 0; i < rows; i++) {
      		if (tab[(i+rows)%rows][j] == tab[(i +rows +1)%rows][j] && tab[(i+rows)%rows][j] == tab[(i +rows+ 2)%rows][j] && tab[(i+rows)%rows][j] != 0) {
        	return true;
      		}
    	}
  	}
	return false;
}
// The fonction checks that there is at least one possibility of movement
bool calculateurdecout(int tab[MAX_SIZE][MAX_SIZE], int rows, int columns){
    int test[MAX_SIZE][MAX_SIZE];
    int feur;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          	test[i][j] = tab[i][j];
          	if(tab[i][j]==9){
          	return 1;
          	}
        }
    }
    for (int i = 0; i < rows-1; i++) {
        for (int j = 0; j < columns; j++) {
            feur= test[i][j];
            test[i][j]=test[i+1][j];
            test[i+1][j]= feur;
            if(verifTab(rows, columns, test)==1){
                return 1;
            } 
            test[i+1][j]=test[i][j];
            test[i][j]=feur;
        }
  	}
  	for (int i = 1; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            feur= test[i][j];
            test[i][j]=test[i-1][j];
            test[i-1][j]= feur;
            if(verifTab(rows, columns, test)==1){
                return 1;
            }
            test[i-1][j]=test[i][j];
            test[i][j]=feur;
        }
    }     
	for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns-1; j++) {
            feur= test[i][j];
            test[i][j]=test[i][j+1];
            test[i][j+1]= feur;
            if(verifTab(rows, columns, test) ==1){
                return 1;
            } 
            test[i][j+1]=test[i][j];
            test[i][j]=feur;
        }
    }
	for (int i = 0; i < rows; i++) {
        for (int j = 1; j < columns; j++) {
            feur= test[i][j];
            test[i][j]=test[i][j-1];
            test[i][j-1]= feur;
            if(verifTab(rows, columns, test)==1){
                return 1;
            }
            test[i][j-1]=test[i][j];
            test[i][j]=feur;
        }
    }   
	return 0;
}
// this fonction use the bomb and testroy it  
void destroybonus(int tab[MAX_SIZE][MAX_SIZE], struct point p, int rows, int columns, int* score){
    int value;

	if(tab[p.lengh][p.widht]==9 && tab[p.lengh2][p.widht2] !=0){
      	value= tab[p.lengh2][p.widht2];
      	tab[p.lengh][p.widht]=0;
      	tab[p.lengh][p.widht]=0;
      	for (int i = 0; i < rows; i++) {
          	for (int j = 0; j < columns; j++) {
            	if(tab[i][j]==value){
            		tab[i][j] = 0;
            		*score++;
            	}
          	}
        }
    }
  	if(tab[p.lengh][p.widht]!=0 && tab[p.lengh2][p.widht2]==9){
      	value= tab[p.lengh][p.widht];
      	tab[p.lengh2][p.widht2]=0;
      	tab[p.lengh][p.widht]=0;
      	for (int i = 0; i < rows; i++) {
          	for (int j = 0; j < columns; j++) {
            	if(tab[i][j]==value){
            		tab[i][j] = 0;
            		*score++;
            	}
          	}
        }
    }
}
