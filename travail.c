#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANNUAIRE 50



struct personne{
    char tele[ANNUAIRE];
    char Nom[ANNUAIRE];
};
struct carnet{
    struct personne pr[ANNUAIRE];
    int compt;
};
struct carnet c;
int i;
int test;
struct personne z;
void Acquisition()
{
 printf("entrer le nom : ");
 scanf("%s",c.pr[c.compt].Nom);
 printf("entrer le numero : ");
 scanf("%s",c.pr[c.compt].tele);;
 c.compt++;
}
/*
 la fonction ajouter qui ajouter les personnes
*/
void Ajouter(){
        Acquisition();
}

/*
la fonction qui nous permet d'afficher les elements a ecran
*/
void Afficher()
{
    for(i = 0; i< c.compt; i++){
        printf("le nom est : %s \n le numero est : %s \n", c.pr[i].Nom,c.pr[i].tele );
    }

}
/*
la fonction qui nous permet de faire une recherche le numero de telephone
*/

int Rechercher(char tele[ANNUAIRE]){

int pos;
pos = -1;
for(i = 0; i< c.compt; i++)
{
    if(strcmp(tele,c.pr[i].tele) == 0){
        pos = i;
    }

}
return pos;
}
/*
la fonction qui nous permet de faire une recherche le nom
*/

int RechercherN(char nom[ANNUAIRE]){

int poss;
poss = -1;
for(i = 0; i< c.compt; i++)
{
    if(strcmp(nom,c.pr[i].Nom) == 0){
        poss = i;
    }

}
return poss;
}


void Effacer(int pos){
 for(i = pos; i<c.compt; i++){
    c.pr[i] = c.pr[i = 1];
 }
 c.compt--;
}

//affiche par lettre alphabetique


void afficheA()
{
    i = 0;
    do{
        test = 0;
        for(int j = c.compt-1; j> i; j--){
            if(strcmp(c.pr[j].Nom, c.pr[j-1].Nom)<0){
                 z = c.pr[j];
                c.pr[j]= c.pr[j-1];
                c.pr[j-1]=z;

            }
        }
    }while(test == 1 && i< c.compt);

}
int main()
{
    int choix;
    char tele;
    char nom;
    do{
        printf(" 1: Ajouter : \n");
        printf(" 2: Afficher la liste : \n");
        printf(" 3: Rechercher telephone : \n");
        printf(" 4: Rechercher Nom : \n");
        printf(" 5: Effacer : \n");
        printf(" 6: Afficher par ordre : \n");
        printf(" 7: QUitter : \n");
        printf(" donner votre choix: ");
    scanf("%d",&choix);
        switch(choix)
        {

        case 1 :
            Ajouter();
            break;
         case 2 :
             Afficher();
            break;
         case 3 :
             {  printf("donner votre numero de telephon : ");
                scanf("%s",tele);
             if(Rechercher(tele) == -1){
                 printf("n'existe pas \n");

             }
             else{
                printf("le nom est : %s \n le numero est %s \n", c.pr[Rechercher(tele)].Nom, c.pr[Rechercher(tele)].tele);
             }

             }

            break;
         case 4 :
              {  printf("donner votre numero de telephon : ");
                scanf("%s",nom);
             if(RechercherN(nom) == -1){
                 printf("n'existe pas \n");

             }
             else{
                printf("le nom est : %s \n le numero est %s \n", c.pr[RechercherN(nom)].Nom, c.pr[RechercherN(nom)].tele);
             }

             }
            break;
         case 5 :
             {  printf("donner votre numero de telephon : ");
                scanf("%s",nom);
             if(RechercherN(nom) == -1){
                 printf("n'existe pas \n");

             }
             else{
                    Effacer(Rechercher(tele));
                    Effacer(RechercherN(nom));

             }
             }
            break;
         case 6 :
             afficheA();
            break;
        case 7 :
            exit(0);
            break;
        }
    }while(1);
    getch();
return 0;
}
