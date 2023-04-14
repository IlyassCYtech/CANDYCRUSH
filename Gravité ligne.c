include <stdio.h>

void main(){

int count=0;
int stock=0;
int repj=0;
int repi=0;

for (int i = 0; i < size; i++) {
  for (int j = 0; j < size; j++) {
    if(tab[i][j]==0&&tab[i+1][j]==0){
      repj=j;
      repi=i
    }
  }
}

for (int i = repi; i < size; i++) {
  for (int j = repj; j < size; j++) {
    while(tab[i][j]==0){
      count++;
    }
  }
}

if(repj=!1){
  for(int z=0;z<repj-1;z++){
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if(tab[i][j]==0&&tab[i+1][j]==0){
          for(int w=0;w<count;w++){
            stock=tab[i+w][j-1];
            tab[i+w][j-1]=0;
            tab[i+w][j]=stock;
          }
        }
      }
    }  
  }
}
