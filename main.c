#include "Tab.h"

int main(void) {
	setlocale(LC_ALL, "");
  	start_color();
  	int score, temp;
  	int rows, columns;
  	int elements;
  	int tab[MAX_SIZE][MAX_SIZE];
  	int tab1[MAX_SIZE][MAX_SIZE];
  	int cout, create;
  	int xcoord, ycoord, xcoord2, ycoord2;
  	struct point p;
  	score = 0;
  	int result = 0;
  	bool result2 = 0;
  	int saves=0;
  	int CHOICE;
  	int game= 0;
  	char filename[1000];
  	char namesave[1000];
    char name[100];
  	int open=0;
  	int selfsave=0;
  	int bomb=0;
    time_t startTime = time(NULL);;
    int elapsedTime;
	time_t currentTime;
  	newgame:
  	initscr();
  	start_color();
  	assume_default_colors(COLOR_WHITE, COLOR_BLACK);
  	game=0;
  	create=0;
    curs_set(0);
    
  	Homepage();
 	CHOICE =menu(game);
 	switch(CHOICE){
      	case 1:
 			 //le cas où on veut charger une partie
       		saves = menusauvegarde(game);
        	if(saves==0){
          		load_game("save.txt", &score, &rows, &columns ,tab, &bomb, &elapsedTime, name);
          	break;
        	}
        	if(saves==1){
          		yourfiles(filename);
          		strcpy(namesave, filename);
          		selfsave=1;
          		if(load_game(namesave, &score, &rows, &columns ,tab, &bomb, &elapsedTime, name)==0){
            		printw("file not recognized");
            		refresh();
            		sleep(2);
            	goto newgame;
          		}
        	
        	if ((calculateurdecout(tab, rows ,columns) == 0) || (countelement(rows, columns, tab)==1)){
            	printw("Game already finished or lost");
            	refresh();
            	sleep(2);
            	goto newgame;            
        	}
        	}
        	if(saves==2){
          	saves=0;
          	goto restart;          
        	}
    		break;
    	case 0:
		// le cas on on veut créer une nouvelle partie
    		saves=0;
    		create=1;
    		break;
    	case 2:
      	//le cas où on quitte le jeu
        	endwin();
        	return 0;
    		break;
    }
	//partie pour la création de partie
	if(create ==1){ 
		restart: 
		createTab(&elements, &rows, &columns, tab, name);
		do {
		// vérifie si il ya pas 3 cases qui se suivent  
   			result = supprimeur(&score, rows, columns, tab, &xcoord, &ycoord, &xcoord2, &ycoord2, &bomb);
   			fillTab(tab, rows, columns, &elements);
   			
  		} while (result == 1);
		score=0;
		bomb=0;
    startTime = time(NULL);
	}
	
  	//la partie en elle même 
  	do {
    //état de la partie passe à 1
    	game=1;
    	//retour du menu
  		Tocontinue:  
		//si la fonction au dessus retourne 1 alors le programme continue sinon ça veut dire qu'aucun cout n'est possible
  		// ancienne fonction inverse
    	do {
      	// ze vérifie que le coût permet de casser au moins 3 elements
      		result2 = 0;
     		if (calculateurdecout(tab, rows,columns) == 0 && countelement(rows, columns, tab)==0) {
         		printGameover();
         		printTab(tab, rows, columns);
         		getch();
          		goto newgame;       
  			}
      		for (int i = 0; i < rows; i++) {
        		for (int j = 0; j < columns; j++) {
          			tab1[i][j] = tab[i][j];
        		}
      		}
      		// le retour de la fonction permet de savoir si on veut aller au menu ou pas
			open=0;
      		// permet de naviguer dans la grille 
    		open = navigate_2d_array(score, rows, columns, tab, &p, name);
      		if(open==1){
        		CHOICE = menu(game);
          		if(CHOICE==1){
            		goto restart;
        		}
          		if(CHOICE==2){
          			saves = menusauvegarde(game);
            			if(saves==1 && selfsave==0){
            				yourfiles(filename);
            				strcpy(namesave, filename);
            				selfsave=1;
						}
						      currentTime = time(NULL);
                  elapsedTime = (int)(currentTime - startTime);
            			savechoice(namesave, saves, score, rows, columns, tab, bomb, elapsedTime, name);
             			goto Tocontinue;
        		}
         		if(CHOICE==3){
           			endwin();
           			return 0;
        		}
         		if(CHOICE==0){
          			goto Tocontinue;
        		}
      		}
			// les lignes suivantes récupérent les valeurs et changes le tableau en consequence
      		temp = tab[p.lengh][p.widht];
      		tab[p.lengh][p.widht] = tab[p.lengh2][p.widht2];
      		tab[p.lengh2][p.widht2] = temp;
			if((tab[p.lengh][p.widht]==9 && tab[p.lengh2][p.widht2] !=0) || (tab[p.lengh][p.widht]!=0 && tab[p.lengh2][p.widht2]==9)){
 				destroybonus(tab, p, rows, columns, &score);
  				gravity(rows, columns, tab);
  				result2=1;
  				
			}
			else{      
			// est le témoins qui permet de savoir si le coût est autorisé 
      			result2 = verifTab(rows, columns, tab);
			
      		        if (result2 == false) {
        		for (int i = 0; i < rows; i++) {
          			for (int j = 0; j < columns; j++) {
            			tab[i][j] = tab1[i][j];
          			}
        		}
        		}
     		}
      		
    	} while (result2 == 0);
    	// la fonction delete permet de récupérer les coordonnées des points alignés et des mettras les cases à 0 
    	supprimeur(&score, rows, columns, tab, &xcoord, &ycoord, &xcoord2, &ycoord2, &bomb);
    	// la fonction gravity permet d'appliquer une gravité normale sur les cases égales à 0 pour en faire une gravité inverse 
    do{	
       	//cette boucle permet de la faire pour vérifier et faire les cassage engendre par la première gravité 
    	do {
    		result= supprimeur(&score, rows, columns, tab, &xcoord, &ycoord, &xcoord2, &ycoord2, &bomb);     
      	} while (result == 1);
      gravity(rows, columns, tab);
      result= supprimeur(&score, rows, columns, tab, &xcoord, &ycoord, &xcoord2, &ycoord2, &bomb);
    }while(result ==1);
		// fin de la partie 
  	} while (countelement(rows, columns, tab)==0);
	int tab_record[1000]; 
    currentTime = time(NULL);
    elapsedTime = (int)(currentTime - startTime);
	savechoice(namesave, saves, score, rows, columns, tab, bomb, elapsedTime, name);  
	int line_record = write_score_to_file(score, "record.txt", tab_record);
  	sort_array_descending(tab_record, line_record);
  	clear();
  	printTab(tab, rows, columns);
  	printw("\nyou won\n\n");
  	printw("Press 'enter' to leave");
  	refresh();
  	getch();
  	print_record(tab_record, score);
  	refresh();
  	game=0;
  	goto newgame;
  	endwin();
  	return 0;
}
