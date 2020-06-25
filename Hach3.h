///1-PARTIE DICTIONNAIRE
/// DECLARATION DE LA STRUCTURE

typedef struct Liste Liste;  /// declaration la structure de liste
struct Liste
{
    char *mot;
    char *def;
    Liste *svt;

};

typedef struct             /// declaration du tableau
{
    char  *M;             ///M represente la definition
    char  *N;             ///N represente le MOT
    Liste *L;

} Tab_Hachage;


///Les fonctions de la listes

///  Initialisation_liste
Liste *initialisation_liste(char *y,char *R,unsigned x)
{

    Liste *liste=malloc(sizeof(liste));
    Liste *p=malloc(sizeof(p));
    p->mot=malloc(50*sizeof(unsigned));
    p->def=malloc(x*sizeof(unsigned));
    strcpy(p->mot,y);
    strcpy(p->def,R);
    liste=p;
    p->svt=NULL;

    return liste;
}

/// Insertion_liste_fin

void insertion_liste_fin(Liste*liste,char *y,char *R,unsigned x)

{
    Liste *p=malloc(sizeof(*p));
    Liste *q=liste;
    p->mot=malloc(50*sizeof(unsigned));
    p->def=malloc(x*sizeof(unsigned));

    strcpy(p->mot,y);
    strcpy(p->def,R);

    while(q->svt!=NULL)
    {
        q=q->svt;
    }
    q->svt=p;
    q=p;
    p->svt=NULL;


}


void suppression_liste_deb(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste!= NULL)
    {
        Liste*p = liste;
        liste= liste->svt;
        free(p);
    }
}

void suppression_liste_milieu(Liste *L, char *mot)
{

    if (L == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Liste*p=L;
    Liste*q;
    int i=0;
    while(p!=NULL && strcmp(L->mot,mot)!=0)
    {
        q=p;
        p=p->svt;
        i++;
    }
    q->svt=p->svt;
    free(p);

}


/// LA FONCTION DE HACHAGE

unsigned hachage(char *chaine)
{
    unsigned i = 0, nombreHache = 0;
    long long x=strlen(chaine)-1;

    for (i = 0 ; chaine[i] != '\0' ; i++)
    {
        nombreHache += toupper(chaine[strlen(chaine)-i-1])*5*pow(10,x);
        x--;
    }
    nombreHache %= 999999;

    if (strlen(chaine)<=2 && strlen(chaine)>=0)
    {
        nombreHache=nombreHache*10;
    }
    else
    {
        if (strlen(chaine)<=5 && strlen(chaine)>=3)
        {
            nombreHache=nombreHache*10+1;
        }
        else
        {
            if (strlen(chaine)<=7 && strlen(chaine)>=6)
            {
                nombreHache=nombreHache*10+2;
            }
            else
            {
                if (strlen(chaine)==8)
                {
                    nombreHache=nombreHache*10+8;
                }
                else
                {
                    if (strlen(chaine)==9)
                    {
                        nombreHache=nombreHache*10+9;
                    }
                    else
                    {
                        if (strlen(chaine)<=12 && strlen(chaine)>9)
                        {
                            nombreHache=nombreHache*10+3;
                        }
                        else
                        {
                            if (strlen(chaine)<=15 && strlen(chaine)>=13)
                            {
                                nombreHache=nombreHache*10+4;
                            }
                            else
                            {
                                if (strlen(chaine)<=18 && strlen(chaine)>=16)
                                {
                                    nombreHache=nombreHache*10+5;
                                }
                                else
                                {
                                    if (strlen(chaine)<=21 && strlen(chaine)>=19)
                                    {
                                        nombreHache=nombreHache*10+6;
                                    }
                                    else
                                    {
                                        if (strlen(chaine)<=24 && strlen(chaine)>=22)
                                        {
                                            nombreHache=nombreHache*10+7;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return nombreHache;
}


/// REMPLISSAGE DE LA TABLE

char* Remplissage(FILE*f)
{

    f=fopen("dictionnaire.txt","r");
    FILE* f1=fopen("projet.txt","w");
    unsigned x;
    int nb0=0,i=0,j=0,k1=1,k=0,nb=0;
    Tab_Hachage *u=malloc(100000000*sizeof(unsigned));
    int *T=NB_cara_ligne(f);   /// on calcule le nombre de caractere dans chaque ligne.
    char *s;
    char *d;
    Liste *p;
    int y=NB_ligne(f);   /// on calcule le nombre de lignes
    unsigned *test=malloc(y*sizeof(unsigned));
    int c;
    int col=0;

    while(!feof(f) && i<y)
    {
        s=malloc((T[i]+1)*sizeof(char));
        d=malloc((T[i]+1)*sizeof(char));
        j=0;
        s[0]='\0';
        d[0]='\0';
        k=0;
        k1=1;
        do                /// on prend le mot et on le met dans  une chaine et on met la phrase dans une autre chaine
        {
            s[j]=fgetc(f);
            s[j+1]='\0';

            if(s[j]!=':' && k1==1)
            {
                d[k]=s[j];
                d[k+1]='\0';
                k++;
            }
            if(s[j]==':')    /// si on trouve les : on arrete c'est la fin du mot
            {
                k1=0;
            }
            j++;
        }
        while(j<T[i] && (!feof(f)));
        s[j]='\0';   ///  confirme la bonne fermeture de notre fin de definition

        c=fgetc(f); /// on saute le "\n"

        x=hachage(d);  /// on décode la chaine
        /// on met le code dans un fichier afin de voir nos collision dans une fonction présenté ci dessus
        fprintf(f1,"%d\n",x);
        /// un petit traitement qui explique le choix des intervalles
        if(u[x].M!=NULL)  /// le remplissage de liste et le traitement des collisions
        {
            nb++;
            if(u[x].L==NULL)
            {
                u[x].L =initialisation_liste(d,s,T[i]);
            }
            else
            {
                insertion_liste_fin(u[x].L,d,s,T[i]);
            }
        }
        else
        {
            u[x].M=malloc((T[i]+1)*sizeof(unsigned)); /// remplissage de la table par definition
            strcpy(u[x].M,s);
            u[x].M[T[i]+1]='\0';

            u[x].N=malloc((strlen(d)+1)*sizeof(unsigned));/// remplissage de la table par MOT
            strcpy(u[x].N,d);
            u[x].N[strlen(d)+1]='\0';
        }
        /// on libere les chaines aprés chaque passage d'une seul definition
        free(s);
        free(d);
        i++;
    }
    fclose(f);
//printf("le nombre de mots en collision est: %d",nb);
    return u;
}


/// RECHERCHE D'ELEMENT DANS LA TABLE

void Recherche_D_Tab_hcha(Tab_Hachage *u,char *Mot)
{
    unsigned x=hachage(Mot);

    Liste*q=malloc(sizeof(q));
    Liste *p=malloc(sizeof(p));
    p=u[x].L;
    int i=0;
    int nb=0;
    if(strcmp(u[x].N,Mot)==0)
    {
        printf(" \n%d  %s  ",x,u[x].M); /// si on trouve le mot on l'affiche sinon on parcours la liste
    }
    else
    {
        nb++;
        while(strcmp(p->mot,Mot)!=0 && p!=NULL)
        {
            p=p->svt;
            nb++;
            i++;
        }
        if(strcmp(p->mot,Mot)==0)
        {
            printf(" \n%d  %s  ",x,p->def);
        }
    }
    printf("  %d  ",nb);
}

/// une fonction qui calcul le max dans un tableau
void Max(int T[],int n)
{
    int i, Max;
    Max=T[0];

    for(i=1; i<n; i++)
    {
        if(Max<T[i])
            Max=T[i];

    }
    printf("le Max de collision est de  %d  collisions\n",Max);
}



void Verif_collision(FILE*f)        /// verifie le nombre de repetition de chaque code
{

    f=fopen("non.txt","r");
    unsigned *T=malloc(1000000*sizeof(unsigned));
    unsigned *m=malloc(1000000*sizeof(unsigned));
    int *M;
    unsigned x;
    long long k,k1=0,i=0,j=0,nb=0;

    while(!feof(f))
    {
        fscanf(f,"%d\n",&x);
        T[i]=x;
        i++;
    }

    fclose(f);


    for(j=0; j<i; j++)
    {
        for(k=j+1; k<i; k++)
        {
            if(T[j]==T[k])
            {
                nb++;
            }
        }

        m[j]=nb;
        nb=0;
    }

    Max(m,i);   /// elle renvois le nombre maximale de repétition

}



///Question N°05 (non testé)
void Distance_hachage(FILE*f,char* M,int k)
{

    f=fopen("dictionnaire.txt","r");
    char c,*s=malloc(sizeof(char));
    int nb=1,i=0,j=1;
    while(!feof(f))
    {
        c=fgetc(f);
        s[i]=toupper(c);
        if(c==':' || c==' ')
        {
            s[i+1]='\0';
            nb=Distance(s,M);
            if(nb==k)
            {
                printf("%s\n",s);
            }
            i=-1;
        }
        i++;
    }
    fclose(f);
}



/// Question N°06 (testé)
void insertion(Tab_Hachage *u, char *mot,char *def)
{
    unsigned code=hachage(mot);
    int k=strlen(def);
    if(u[code].M!=NULL)
    {
        if(u[code].L==NULL)
        {
            u[code].L =initialisation_liste(mot,def,k);
        }
        else
        {
            insertion_liste_fin(u[code].L,mot,def,k);
        }
    }
    else
    {
        u[code].M=malloc((k+1)*sizeof(unsigned));
        strcpy(u[code].M,def);
        u[code].M[k+1]='\0';

        u[code].N=malloc((strlen(mot)+1)*sizeof(unsigned));
        strcpy(u[code].N,mot);
        u[code].N[strlen(mot)+1]='\0';
    }
}

/// Question N°06 (non testé)
void suppression_1(Tab_Hachage *u, char *mot)
{
    unsigned code=hachage(mot);
    Liste *p=u[code].L;
    if(strcmp(u[code].M,mot)==0)
    {
        while(!p->svt)
        {
            p=p->svt;
        }
        strcpy(u[code].M,p->def);
        strcpy(u[code].N,p->mot);
        free(p);

    }
    else
    {
        if(strcmp(u[code].L->mot,mot)==0)
            suppression_liste_deb(u[code].L);
        else
            suppression_liste_milieu(u[code].L,mot);
    }
}

void suppression(Tab_Hachage *u, char *mot)
{
    unsigned code=hachage(mot);
    Liste *p=u[code].L;
    if(strcmp(u[code].N,mot)==0)
    {
      strcpy (u[code].M ,"le mot a ete supprime");
    }
    else

        if(strcmp(u[code].L->mot,mot)==0)
           strcpy (u[code].L->def, "le mot a ete supprime");

        else
           p = u[code].L;

           while (p->svt != NULL && strcmp((p->mot),mot) != 0)
           {
               p=p->svt;
           }
           if (strcmp((p->mot), mot) == 0)
            strcpy(p->def , "le mot a ete supprime");

}

/// 2-PARTIE INDEX


typedef struct
{
    char *mot;
    int *t;

}index;
/// LES POSITIONS D'UN MOT DANS UN FICHIER

///Question N°8 ( testé )
index Pos_Mot(FILE* f, char* m)
{
    f = fopen("dictionnaire.txt", "r");
    char* s;
    int n = nb_mot_fich(f), nb=0, i=1;
    index t;
    t.t= malloc((n+1)* sizeof(int));
    s= malloc (sizeof(s));
    strcpy(t.mot,m);
    while (!feof(f))   /// trouvons la 1er positiion du mot dans le fichier
    {
        fscanf(f,"%s ",s);
        nb++;
        if ( strcmp(s,m) == 0)
        {
            t.t[i] = nb ;
            printf("%d ",nb);
            i++;
        }
    }
    t.t[0]=i; /// je met la taille du tableau dans la premiere case

    fclose(f);
    return (t);
}






