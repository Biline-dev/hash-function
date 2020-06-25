#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "Hach1.h"
#include "Hach2.h"
#include "Hach3.h"
#include <windows.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


int main()
{
    FILE *f=fopen("dictionnaire","r");
    int k=1,k1=1,d;
    int **t;
    int *t1;
    char **ch;
    char *s=malloc(sizeof(char));
    char *sh=malloc(sizeof(char));
    Tab_Hachage *u;
    u=Remplissage(f);
   /// la recherche dans le Dictionnaire
   Color(12,0);
   printf("-------------------------------------------------------------Menu-------------------------------------------------------\n");
   while(k1==1)
   {
       printf("------------------------------------------------------------------------------------------------------------------------\n");
   Color(9,0);
   printf("Projet\n");
   Color(15,0);
   printf("1-Chercher un mot dans le dictionaire\n");
   printf("2-Nombre de collision \n");
   printf("3-l'ajout d'un mot\n");
   printf("4-suppression d'un mot donne\n");
   printf("5-Les mots distants\n");
   printf("6-Exit\n");
   Color(12,0);
      printf("------------------------------------------------------------------------------------------------------------------------\n");
   Color(9,0);
   printf("Donner votre choix : ");
   scanf("%d",&d);
   switch(d)
   {
   case 1:
    while(k==1)
    {
    s=malloc(sizeof(char));
    Color(13,0);
    printf("\nDonner votre mot: ");
    scanf("%s",s);

    if(s[0]!=toupper(s[0]))         /// le cas ou le mot donné est en minuscule
    {
       for(int i=0;i<strlen(s);i++)
        s[i]=toupper(s[i]);
    }
    Color(15,0);
    Recherche_D_Tab_hcha(u,s);

    Color(10,0);
    printf("\nVoulez vous  rechercher un autre mot?\n");
    printf("1-oui\n");
    printf("2-non\n");
    scanf("%d",&d);

    if(d==2)
        k=0;
    }
    break;

   case 2:
       Color(10,0);
       printf("\n");
    Verif_collision(f);
       printf("\n");
    break;
   case 3:

       insertion(u, "ISIL B","ISIL B:filiere et section");
       Recherche_D_Tab_hcha(u,"ISIL B");
    break;

   case 4:
        suppression(u,"CAVE");
        Recherche_D_Tab_hcha(u,"CAVE");
    break;
    case 5:
        Color(15,0);
        Distance_hachage(f,"OR",2);
    break;

   case 6:
       Color(14,0);
       printf("\n");
       printf("\n");
       printf("                                               Merci pour votre attention");
       printf("\n");
       printf("\n");
       k1=0;
    break;
   }
   }
   Color(15,0);


    return 0;
}
