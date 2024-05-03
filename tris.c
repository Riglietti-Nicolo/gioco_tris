#include <stdio.h>
#include <stdlib.h>

void stampa_tebella(int tabella_gioco[3][3]){

    int x, y;
    printf(" 0   1    2\n");

    for (x = 0; x < 3; x++ ){

        for(y = 0; y < 3; y++) {
            
            if (y != 2) {
                printf(" %c |", tabella_gioco[x][y]);
            } else {
                printf(" %c ", tabella_gioco[x][y]);
            }           
        }
        
        if (x != 2) {
            printf(" %d\n------------\n", x);
        } else {
            printf(" %d\n", x);
        }
    }
}

void vincitore(int tabella_gioco[3][3]){
    int righe, colonne;

    //verifica righe
    for(righe = 0; righe < 3; righe++) { 
        if(tabella_gioco[righe][0] != ' ' && tabella_gioco[righe][0] == tabella_gioco[righe][1] && tabella_gioco[righe][1] == tabella_gioco[righe][2]) {
            printf("\nVINCITORE %c \n", tabella_gioco[righe][0]);
            exit(0);
        } 
    }
    
    //verifica colonne
    for(colonne = 0; colonne < 3; colonne++) { 
        if(tabella_gioco[0][colonne] != ' ' && tabella_gioco[0][colonne] == tabella_gioco[1][colonne] && tabella_gioco[1][colonne] == tabella_gioco[2][colonne]) {
            printf("\nVINCITORE %c \n", tabella_gioco[0][colonne]);
            exit(0);
        } 
    }

    //verifica diagonale1
    if(tabella_gioco[0][0] != ' ' && tabella_gioco[0][0] == tabella_gioco[1][1] && tabella_gioco[1][1] == tabella_gioco[2][2]) {
        printf("\nVINCITORE %c \n", tabella_gioco[0][0]);
        exit(0);
    } 
    
    //verifica diagonale2
    if(tabella_gioco[0][2] != ' ' && tabella_gioco[0][2] == tabella_gioco[1][1] && tabella_gioco[1][1] == tabella_gioco[2][0]) {
        printf("\nVINCITORE %c \n", tabella_gioco[0][2]);
        exit(0);
        
    }
  
}

int main(void) {
    char giocatore[2] = {'X', 'O'};
    int tabella_gioco[3][3];
    int x, y;
    int px, py;
    int turno = 0; //tiene traccia del turno dei giocatori

    for(x=0; x<3; x++) {
        for(y=0; y<3; y++)
            tabella_gioco[x][y]= ' ';
    }

    printf("\n");

    stampa_tebella(tabella_gioco);

    for (int i = 0; i < 9; i++){

        vincitore(tabella_gioco);

        do {

            printf("\n turno giocatore %c \n", giocatore[turno]);
            scanf("%d %d", &px, &py);
        } while (tabella_gioco[px][py] != ' ');         
        
        tabella_gioco[px][py] = giocatore[turno];
        printf("\n");
        stampa_tebella(tabella_gioco);
        
        turno = (turno + 1) % 2;
    }

    printf("PAREGGIO \n");

  return 0;  
}