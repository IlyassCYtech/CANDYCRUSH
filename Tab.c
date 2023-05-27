#include "Tab.h"

void createTab(int *elements, int *rows,int *columns,int tab[MAX_SIZE][MAX_SIZE], char name[100]){
    srand(time(NULL));
    float a, b, c;
    char input[100];
    initscr();
    clear();
     char get[100];
    do{
      clear();
      printw("What's your name ?\n");
      refresh();
      getstr(input);
           
    }while(strlen(input)<2 || strlen(input)>100);
    strcpy(name, input);
    clear();
    printw("How many line do you want ?\n ");
  	refresh();
  	do{
       
    	getstr(input);      
      	if (sscanf(input, "%f", &a) != 1 || a < MIN_SIZE || a> MAX_SIZE){ 
        	printw("Give a value that works greater than %d and less than %d : ", MIN_SIZE, MAX_SIZE);
            refresh();         
      	}     
    }while(a < MIN_SIZE || a > MAX_SIZE);
    clear();
    printw("How many column do you want ? ");
  	refresh();
  	do{
      
    	getstr(input);      
      	if (sscanf(input, "%f", &c) != 1 || c < MIN_SIZE || c> MAX_SIZE){ 
        	printw("Give a value that works greater than %d and less than %d : ", MIN_SIZE, MAX_SIZE);
            refresh();         
      	}     
    }while(c < MIN_SIZE || c > MAX_SIZE);

    clear();
	printw("How many different elements do you want ? ");
    refresh();
    do{
       	get[0]=getch();
      	if (sscanf(get, "%f", &b) != 1 || b < MIN_ELEMENTS || b > MAX_ELEMENTS){
           clear();
           printw("Give a correct value between %d and %d : ", MIN_ELEMENTS, MAX_ELEMENTS);
           refresh();
      	}
    } while (b < MIN_ELEMENTS || b > MAX_ELEMENTS);
    *rows = (int)a;
    *columns = (int)c;
    *elements = (int)b;
    clear();
    printw("Nom du joueur: %s\n", name);
    printw("Number of lines : %d\n", *rows);
    printw("Number of columns : %d\n", *columns);
    printw("Element : %d\n", *elements);
    printw("\n");
    refresh();
    sleep(1);
    for (int i = 0; i < *rows; i++){
        for (int j = 0; j < *columns; j++){
            tab[i][j] = rand() % (*elements)+1;
        }
    }
}

void gravity(int rows, int columns, int tab[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (j = 0; j < columns; j++) {
        for (i = 0; i < rows; i++) {
            if (tab[i][j] == 0) {
                int k;
                for (k = i + 1; k < rows; k++) {
                    if (tab[k][j] != 0) {
                        tab[i][j] = tab[k][j];
                        tab[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

int countelement(int rows,int columns, int tab[MAX_SIZE][MAX_SIZE]){
	int one=0;
	int two=0;
	int three=0;
	int four=0;
	int five=0;
	int six=0;
  	for (int j = 0; j < columns; j++) {
        for (int i = 0; i < rows; i++) {
            switch (tab[i][j]){
            	case 6:
                	six++;
                	break;
            	case 1:
                	one++;
                	break;
            	case 2:
                	two++;
                	break;
            	case 3:
                	three++;
                	break;
            	case 4:
                	four++;
                	break;
            	case 5:
                	five++;
                	break;
        	}
        }
    }
  	int count = 0;
    if (one != 0){
      	count++;
    }
    if (two != 0){
      	count++;
    }
    if (three != 0){
      	count++;
    }
    if (four != 0){
      	count++;
    }
    if (five != 0){
      	count++;
    }
    if (six != 0){
      	count++;
    }
	if(count >2){
  		return 0;
	}
	if(count <= 2){
  		return 1;
	}
	return 0;
}
