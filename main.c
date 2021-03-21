#include <stdio.h>

void deplace_personnage(int tableauD[20][20],int coordonesD[1][2]);
void affiche_carte(int tableauA[20][20],int coordonesA[1][2]);
int init_carte(int tableauI[20][20],int coordonesI[1][2]);


int main() {

    int start;
    int tableau[20][20];
    int coordones[1][2];

    start=init_carte(tableau,coordones);

    return 0;
}
/*Procédure pour initialize la carte:*/

int init_carte(int tableauI[20][20],int coordonesI[1][2]){

    int i;
    int j;
    int z;
    int t;
    int x;
    int y;

    for(x=0;x<1;x++){
        for(y=0;y<2;y++){
            coordonesI[x][y]=0;
        }
    }

    for (i = 0 ; i < 20 ; i = i + 1) {
        for (j = 0 ; j < 20 ; j = j + 1) {
            tableauI[i][j]=0;
        }
    }

    for (i = 0 ; i < 20 ; i = i + 1) {
        for (j = 0 ; j < 20 ; j = j + 1) {

            //herbe//
            tableauI[i][j]=0;
            //fleur
            tableauI[3][6]=1;
            tableauI[4][12]=1;
            tableauI[7][15]=1;
            tableauI[11][19]=1;
            //obtacles//
            //arbre//
            tableauI[2][2]=3;
            tableauI[3][2]=3;
            tableauI[4][2]=3;
            tableauI[19][2]=3;
            tableauI[19][4]=3;
            tableauI[1][12]=3;
            tableauI[1][3]=3;
            tableauI[14][2]=3;
            tableauI[1][2]=3;
            tableauI[16][10]=3;
            tableauI[7][8]=3;
            //piece d'or//
            tableauI[6][5]=5;
            tableauI[3][5]=5;
            tableauI[6][2]=5;
            tableauI[19][5]=5;
            tableauI[13][5]=5;
            tableauI[0][13]=5;
            tableauI[10][7]=5;
            tableauI[14][5]=5;
            tableauI[1][17]=5;
            tableauI[2][19]=5;
            tableauI[0][5]=5;

            printf("%d ", tableauI[i][j]);
        }
        printf("\n");
    }
    deplace_personnage(tableauI,coordonesI);

}
/*Procédure pour deplace le personnage:*/

void deplace_personnage(int tableauD[20][20],int coordonesD[1][2]){

    int p;
    int z=0;
    int t=0;
    int x=0;
    int y=0;
    int vie=10;
    int oro=0;

    coordonesD[0][0]=0;
    coordonesD[0][1]=0;

    do{
        printf("\n");
        printf("Appuyez sur 0 si vouz voulez quitter\n");
        printf("Choisissez le Deplacemment :)\n");
        printf("Vie: %d\n", vie);
        printf("pieces d'or: %d\n", oro);
        scanf("%d", &p);


        //Assignation de ordonnes à une variable x:
        x=coordonesD[0][0];
        //Assignation de ordonnes à une variable y:
        y=coordonesD[0][1];

        //Changement de coordonnées du personnage selon la valeur de la variable p:

        if(p==8){
            coordonesD[0][0]=x-1;
            if(x<0){
                coordonesD[0][0]=x+2;
            }
            coordonesD[0][1]=y;
        }
        if(p==2){
            coordonesD[0][0]=x+1;
            if (x>=19){
                coordonesD[0][0]=x-2;
            }
            coordonesD[0][1]=y;
        }
        if(p==4){
            coordonesD[0][1]=y-1;
            if (y<0){
                coordonesD[0][1]=y+2;
            }
            coordonesD[0][0]=x;
        }
        if(p==6){
            coordonesD[0][1]=y+1;
            if (y>19){
                coordonesD[0][1]=y-2;
            }
            coordonesD[0][0]=x;
        }
        /*	VARIABLE VIE:*/
        /*Obstacles(rocher) [-] de vie] :*/

        if(((x==2) && (y==2)) || ((x==3) && (y==2)) || ((x==4) && (y==2)) || ((x==19) && (y==2))){
            vie=vie-1;
            tableauD[x][y]=0;
        }
        if(((x==19) && (y==4)) || ((x==1) && (y==12)) || ((x==1) && (y==3)) || ((x==14) && (y==2))){
            vie=vie-1;
            tableauD[x][y]=0;
        }
        if(((x==1) && (y==2)) || ((x==16) && (y==10)) || ((x==7) && (y==8))){
            vie=vie-1;
            tableauD[x][y]=0;
        }

        /*OBJET*/
        /*Pieces d'or):*/

        if(((x==6) && (y==5)) || ((x==3) && (y==5)) || (x==6) && (y==2)|| (x==19 && (y==5))){
            oro=oro+1;
            tableauD[x][y]=0;
        }
        if(((x==13) && (y==5)) || ((x==0) && (y==13)) || (x==10) && (y==7)|| (x==14 && (y==5))){
            oro=oro+1;
            tableauD[x][y]=0;
        }
        if(((x==1) && (y==17)) || ((x==2) && (y==19)) || (x==0) && (y==5)){
            oro=oro+1;
            tableauD[x][y]=0;
        }

        /* Freur*/

        if(((x==3) && (y==6)) || ((x==4) && (y==12)) || (x==7) && (y==15)|| (x==11 && (y==19))){
            vie=vie+1;
            tableauD[x][y]=0;
        }
        affiche_carte(tableauD,coordonesD);

    } while ((p!=0) && (vie!=0) && (oro!=10));


    /*Après avoir sortie du jeux on affiche:*/
    if(oro==10){
        printf("Felicitations vous avez Gagne!!!\n");
    }
    if(vie==0){
        printf("Vous avez perdu :( !!!\n");
    }
    if(p==0){
        printf("Vous avez decide de quitter le jeux:)\n");
    }
}

/*Procédure pour afficher la carte:*/
void affiche_carte(int tableauA[20][20],int coordonesA[1][2]){

    int z;
    int t;
    int x;
    int y;

    x=coordonesA[0][0];
    y=coordonesA[0][1];

    /*Boucle du tableauA pour affiché la carte:*/
    for(z=0;z<20;z++){
        for(t=0;t<20;t++){
            if((z==x)&&(t==y)){
                printf("X ");
            }
            else{
                printf("%d ", tableauA[z][t]);
            }
        }
        printf("\n");
    }
    printf("\n");
    /*Affichage des coordonnes [x,y]:*/
    printf("%d , %d \n", coordonesA[0][0],coordonesA[0][1]);
}









