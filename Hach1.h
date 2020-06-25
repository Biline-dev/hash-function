///Partie I
/// Fonctions utiles

char* Allo_TAB(int n)
{
    char *T;
    T=malloc((n+1)*sizeof(char));

    if(!T)
        exit(EXIT_FAILURE);
    return T;
}


char lireCaractere()
{
    char caractere = 0;

    caractere = getch(); // On lit le premier caractère
    // On lit les autres caractères mémorisés un à un jusqu'au \n (pour les effacer)
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}


void ajouter_cara(char ch[],char m,int pos)
{
    int i=0,j=0;
    while(i<strlen(ch) && j<pos)
    {
        i++;
        j++;
    }
    if(j==pos)
    {
        j=strlen(ch);
        while(j>=pos)
        {
            ch[j+1]=ch[j];
            j--;
        }
        ch[pos]=m;
        ch[strlen(ch)]='\0';
    }
}


/// Question N°01(testé)
void STR_insert1(char *ch1,char *ch2,int pos)
{
    int i;
    for(i=0;i<strlen(ch2);i++)
    {
        ajouter_cara(ch1,ch2[i],pos);
        pos++;
    }
}

/// Question N°02(testé)
void STR_insert2(char *ch1,char *ch2,int pos,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        ajouter_cara(ch1,ch2[i],pos);
        pos++;
    }
}


/// Question N°02(testé)
int* Max_Min(char T[],int n,int j)
{
    char Min, Max;
    int i=j;
    int *M=malloc(2*sizeof(int));

    Min=T[i];  Max=T[i];
    M[0]=i;     M[1]=i;
    while(i<n)
    {
     if(Min>=T[i])
        {
        if(Min!=T[i])
          {
              M[0]=i;
          }
          Min=T[i];
        }else
        {
         if(Max<=T[i])
         {
             if(Max!=T[i])
          {
              M[1]=i;
          }
             Max=T[i];
         }
        }
        i++;
    }

    return M;
}

/// Question N°03(testé)
void Alphabet(char *T,int n)
{
    int *M;
    int j=0,k=1;
    char x='\0',y='\0';
    while(j<n && k==1)
    {
        M= Max_Min(T,n,j);
        if(M[1]==j)
        {
        x=T[j];
        T[j]=T[M[0]];
        T[M[0]]=x;
        j++;
        }
    else
    {
        x=T[j];
        T[j]=T[M[0]];
        T[M[0]]=x;

        y=T[n-1];
        T[n-1]=T[M[1]];
        T[M[1]]=y;
        j++;
        n--;
    }
    }
}


/// Question N°04(testé)
int Freq_char(char *M,char c)
{
    int i=0,nb=0;
    while(i<strlen(M))
    {
        if(M[i]==c)
        {
            nb++;
        }
        i++;
    }
   return nb;
}


/// Question N°05(testé)
typedef struct
{
    char c;
    int x;
}Freq;

int Verif_exit(Freq *M,char c)
{
    int i=1;
    while(i<=strlen(M) && M[i].c!=c)
    {
        i++;
    }
        if (M[i].c==c)
         return 1;
        else
         return 0;
}

Freq* Frequence(char *M)
{
    int i,nb=0,j=1;
    Freq *T=malloc((strlen(M)+1)*sizeof(Freq));
    for(i=1;i<strlen(M);i++)
    {
     if (Verif_exit(T,M[i])==0)
        {
             T[j].c=M[i];
             T[j].x=Freq_char(M,M[i]);
             j++;
       }
    }
    T[0].x=j;

   return T;
}


/// Question N°06(testé)
char* STR_nchr(char *s,char c, int n)
{
    int nb=0,i=0;
    while(nb!=n)
    {
        if(s[i]==c)
        {
            nb++;
        }
            i++;
    }
      if(nb>=n)
      {
        return s+i;
      }
      else
      {
        if(nb!=NULL)
        return s+i;
        else
        return NULL;
      }
}


/// Question N°07(non testé)
int Distance(char* L1, char* L2)
{
   int  nb=0,j=0,i=0;
   int x=strlen(L1),y=strlen(L2);

    while(i<x)
    {
        while(j<y)
        {
            if(L1[i]!=L2[j])
            {
                nb++;
            }
            j++;
        }
        i++;
    }
    return nb;
}


/// Question N°08(testé)
char* STR_nstr(char *s,char *p,int n)
{
    int i=0,j,k=1,m,nb=0;
    char *sh=malloc(strlen(p)*sizeof(char));
    sh[0]='\0';
    while(nb!=n)
    {
     while(i<strlen(s))
     {
         m=i;
        for(j=0;j<strlen(p);j++)
        {
            sh[j]=s[m];
            m++;
        }
        sh[strlen(p)]='\0';
        if(strcmp(sh,p)==0)
        {
          nb++;
        }
       i++;
     }
    }
      if(nb>=n)
      {
        return s+i-strlen(p);
      }
      else
      {
        if(nb!=NULL)
        return s+i-strlen(p);
        else
        return NULL;
      }
}

/// Question N°08(testé)
 char* STR_rstr(char *s, char *p)
{
    int i=strlen(s),j,k=1,m;
    char *sh=malloc(strlen(p)*sizeof(char));
    sh[0]='\0';
    while(i>=0 && k==1)
    {
        m=i;
        j=strlen(p);
        while(j>=0)
        {
         sh[j]=s[m];
            m--;
            j--;
        }
        sh[strlen(p)]='\0';
        if(strcmp(sh,p)==0)
        {
            return s+i;
        }
        i--;
    }
    return NULL;
}

///Question N°09
char*strndl(char *s,int n, int i)
{
    int j;
    char *d=malloc((strlen(s)+1)*sizeof(char));
    int k=strlen(s);
    for(j=i;j<k;j++)
    {
        s[j]=s[j+n];
        k--;
    }

    for(j=0;j<k;j++)
    {
        d[j]=s[j];
    }
    return s;
}



/// fonction utiles
void Afficher_TAB(char *T,int n)
{
    int i;
     for(i=0;i<n;i++)
    {
        printf(" T[%d] = %c",i,T[i]);
    }

}


