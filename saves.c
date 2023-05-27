#include "Tab.h"



//fonction load the game
int load_game(const char* filename, int *score, int *rows,int *columns, int tab[MAX_SIZE][MAX_SIZE], int *bomb, int* elapsedTime, char name[100]) {
    FILE* fp = fopen(filename, "r");
    clear();
    if (!fp) {
        printw("Could not open file '%s'\n", filename);
        refresh();
        return 0;
    }
	// Read grid dimensions
    if (fscanf(fp, "%d\n", rows) != 1) {
        printw("Error reading grid dimensions ligne for player \n");
        refresh();
        sleep(2);
        fclose(fp);
        return 0;
    }
	if (fscanf(fp, "%d\n", columns) != 1) {
        printw("Error reading grid dimensions for player \n");
        refresh();
    	sleep(2);
        fclose(fp);
        return 0;
    }
	// Read grid values
    for (int r = 0; r < *rows; r++) {
        for (int c = 0; c < *columns; c++) {
            if (fscanf(fp, "%d ", &tab[r][c]) != 1) {
                printw("Error reading grid value at (%d, %d) for player \n", r, c);
                refresh();
                fclose(fp);
                return 0;
            }
        }
        fscanf(fp, "\n"); // skip the end-of-line character
    }
	// Read bombstate and score
    if (fscanf(fp, "%d\n%d\n%d\n", score, bomb, elapsedTime) != 3) {
        printw("Error reading BombState and score for player \n");
        refresh();
        sleep(2);
        fclose(fp);
        return 0;
    }

     if (fgets(name, 100, fp) == NULL) {
        printw("Error reading name for player\n");
        refresh();
        sleep(2);
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return 1;
}
//Save the game to start it a next time
int save(const char* filename, int score, int rows,int columns, int tab[MAX_SIZE][MAX_SIZE], int bomb, int elapsedTime, char name[100]) {
    FILE* fp = fopen(filename, "w");
    if (!fp) {
        printw("Could not open file '%s'\n", filename);
        refresh();
        return 0;
    }
	// Read grid dimensions
    fprintf(fp, "%d\n%d\n", rows, columns);
    // Read grid values
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            fprintf(fp, "%d ", tab[r][c]);
        }
        fprintf(fp, "\n"); // skip the end-of-line character
    }
	// Read moves left and score
    fprintf(fp, "%d\n%d\n%d\n", score, bomb, elapsedTime);
    fprintf(fp, "%s\n", name);    
    fclose(fp);
    return 1;
}
//this fonction test the files given by you and return 1 if it exist
bool testfile(char* filename) {
  FILE* file = fopen(filename, "r");  // Ouvre le fichier en mode lecture
  if (file == NULL) {  // Le fichier n'a pas pu être ouvert
    return false;
  }
  if (strcmp(filename, "record.txt") == 0) {  // Comparaison avec "record.txt"
    fclose(file);  // Ferme le fichier
    return false;
  }  
  fclose(file);  // Ferme le fichier
  return true;
}
//thid fonction ask you to give the name of your save
char yourfiles(char filename[1000]) {
  do {
    clear();
    printw("Enter file name : ");
    refresh();
    getstr(filename);
  } while (!testfile(filename));
  return *filename;
}
//this fonction save the game with your past choice of save
void savechoice(char* namesave, int saves,int score,int rows,int columns,int tab[MAX_SIZE][MAX_SIZE],int bomb,int elapsedTime, char name[100]){
    if(saves==0){
        save("save.txt", score, rows, columns,tab, bomb, elapsedTime, name);
    }
    if(saves==1){
        save(namesave, score, rows, columns,tab, bomb, elapsedTime, name);
    }
}
