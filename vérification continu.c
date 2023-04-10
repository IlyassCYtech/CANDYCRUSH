int vérificateurcontinu(int tab, int *r, int *v) {
    int valeur = 0; 
    
   
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille-2; j++) {
            if (tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2]) {
                valeur = 2;
              *r=i;
              *v=j;
                }
        }
    }
    
   
    for (int j = 0; j < taille; j++) {
        for (int i = 0; i < taille-2; i++) {
            if (tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j]) {
                valeur = 1;
              *r=i;
              *v=j;
                }
        }
    }
    
    return valeur;
}
