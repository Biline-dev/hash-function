///Partie II les fichiers textes

/// creation d'un fichier
FILE* creation()
{
    FILE* fich;
    char *s=malloc(sizeof(s));
    printf("donner le nom du fichier ");
    scanf("%s",s);
    fich=fopen(s,"w");

    return fich;
}

/// Question N°01
char* Lire(FILE *f)
{
    f=fopen("dictionnaire.txt","r");
    long i=taille(f);
    char *s=Allo_TAB(i+1);

    rewind(f);
    fread(s,i,1,f);
    fclose(f);

    return s;
}

/// Question N°02
int taille(FILE*f)
{
fseek(f,0,SEEK_END);

return ftell(f);
}

/// Question N°03
int NB_ligne(FILE *fich)
{
    char *s=malloc(sizeof(s));
    int nb=1;
    fich=fopen("dictionnaire.txt","r");
    if(fich!=NULL)
    {
       while(!feof(fich))
        {
         s=malloc(sizeof(s));
          s=fgetc(fich);
          if(s=='\n')
            nb++;
        }
    }
    fclose(fich);

    return nb;
}

/// fonction qui calcule le nombre de caracteres par lignes
int* NB_cara_ligne(FILE *fich)
{
    char s;
    int i=0,k=1;
    int *M=malloc((NB_ligne(fich))*sizeof(int));
    int nb;
    fich=fopen("dictionnaire.txt","r");

       while(!feof(fich))
        {
          nb=0;
          do
          {
             s=fgetc(fich);
             nb++;

          }while(!feof(fich) && s!='\n');

             M[i]=nb-1;
               i++;
        }

    fclose(fich);
    return M;
}

///Question N°04
char** Lignes(FILE*fich)
{
   int i;
   fich=fopen("dictionnaire.txt","r");
   char **M=malloc((NB_ligne(fich)+1)*sizeof(char*));
   int *T=NB_cara_ligne(fich);
   char*s;
   for(i=0;i<NB_ligne(fich);i++)
   {
       M[i]=malloc((T[i])*sizeof(char));
       M[i]=fgets(s,T[i]+2,fich);
       printf("%s ",M[i]);
   }

    fclose(fich);
    return M;
}

/// Question N°05
int Trouver(FILE*f,char*m)
{
    char *s=malloc(sizeof(s));
    f=fopen("dictionnaire.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s ",s);
        if(strcmp(s,m)==0)
           return 1;
    }
        fclose(f);

   return 0;
}

/// Question N°06
int Freque(FILE*f,char*m)
{
    int nb=0;
    char *s=malloc(sizeof(s));
    f=fopen("dictionnaire.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s ",s);
        if(strcmp(s,m)==0)
           nb++;
    }
        fclose(f);

   return nb;
}

/// une fonction qui calcul le nombre de mot dans un fichier (elle utilisé pour la partie INDEX)
int nb_mot_fich(FILE *f)
{
    int nb=1;
    char c;
    f=fopen("dictionnaire.txt","r");
    while(!feof(f))
    {
        c=fgetc(f);
        if(c==':' || c==' ')
        {
            nb++;
        }
    }
      fclose(f);
    return nb;
}


// ajouter un element dans un fichier
void Ajout_mot_fich(char x,FILE*f)
     {
   char s[30];
   FILE*f1;
   int k=1;

   scanf("%s",x);

   f=fopen("le pendu.txt","r");

    while(!feof(f) && k==1)
    {
      fscanf(f,"%s\n",s);
        if(strcmp(x,s)==0)
        {
          k=0;
        }
    }
    fclose(f);

    if(k==1)
    {
    f1=fopen("le pend.txt","w");
    f=fopen("le pendu.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s\n",s);
        fprintf(f1,"%s\n",s);
    }
   fclose(f);
   fclose(f1);

    f=fopen("le pendu.txt","w");
    f1=fopen("le pend.txt","r");

    fprintf(f,"%s\n",x);
    while(!feof(f1))
    {
        fscanf(f1,"%s\n",s);
        fprintf(f,"%s\n",s);
    }
   fclose(f);
   fclose(f1);
    }

    }
// travail de maniere aléatoire
int Fich_aleatoire(FILE*f)
 {
    int nb=0,i;

    f=fopen("le pendu.txt","r");
    char x[100];
    srand(time(NULL));
    while(!feof(f))
    {
        fscanf(f,"%s",x);
         nb++;
    }
    nb = (rand() % (nb - 1 + 1)) + 0;
    fclose(f);

    return nb;
 }
