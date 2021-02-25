#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Nb_path;
    char Path[1000][40];
}Car;
typedef struct
{
    int Debut;
    int Fin;
    char name[40];
    int L;
}Street;
typedef struct
{
    char Name[40];
    int T;
}green_light;
typedef struct
{
    int Eff;
    int Nb_Street;
    green_light Streets[10];
}Intersection;


int main()
{
    int D,I,F,S,V;
    Car Cars[1000];
    Intersection Inters[100000];
    Street Streets[100000];
    return 0;
}

int Init(char nomt[20],int *D,int *I,int *S,int *V,int *F,Car *Cars,Street *Streets) ///affecter les val du fich au var
{
    FILE *f = NULL;
    char lign[256],temp[10];
    int i=0,j=0,k,z;

    f = fopen(nomt,"r");
    if ( f == NULL){
            printf("Error when opening the file %s\n",nomt);
            return 1;
    }

    while (!feof(f))
        if (fgets(lign, sizeof(lign),f))
        {
            while ( lign[i] != ' ' )
            {
                temp[i]=lign[i];
                i++;
            }
            temp[i]='\0';
            *D = atoi(temp);
            i++;
            strcpy(temp,"");
            while ( lign[i] != ' ' )
            {
                temp[j]=lign[i];
                i++;
                j++;
            }
            temp[j]='\0';
            *I = atoi(temp);
            i++;
            j=0;
            strcpy(temp,"");

            while ( lign[i] != ' ' )
            {
                temp[j]=lign[i];
                i++;
                j++;
            }
            temp[j]='\0';
            *S = atoi(temp);
            i++;
            j=0;
            strcpy(temp,"");
            while ( lign[i] != ' ' )
            {
                temp[j]=lign[i];
                i++;
                j++;
            }
            temp[j]='\0';
            *V = atoi(temp);
            i++;
            j=0;
            strcpy(temp,"");
            while ( lign[i] != ' ' )
            {
                temp[j]=lign[i];
                i++;
                j++;
            }
            temp[j]='\0';
            *F = atoi(temp);
            i=0;
            j=0;
            strcpy(temp,"");
        }
        for (k=0;k<*S;k++)
        {
            if (fgets(lign, sizeof(lign),f))
            {
                while ( lign[i] != ' ' )
                {
                    temp[j]=lign[i];
                    i++;
                    j++;
                }
                temp[j]='\0';
                Streets[k].Debut=atoi(temp);
                i=0;
                j=0;
                strcpy(temp,"");
                while ( lign[i] != ' ' )
                {
                    temp[j]=lign[i];
                    i++;
                    j++;
                }
                temp[j]='\0';
                Streets[k].Fin=atoi(temp);
                i=0;
                j=0;
                strcpy(temp,"");
                while ( lign[i] != ' ' )
                {
                j=0;
                strcpy(temp,"");
            }
        }
        for (k=0;k<*V;k++)
        {
            if (fgets(lign, sizeof(lign),f))
            {
                while ( lign[i] != ' ' )
                {
                    temp[j]=lign[i];
                    i++;
                    j++;
                    temp[j]=lign[i];
                    i++;
                    j++;
                }
                temp[j]='\0';
                strcpy(Streets[k].name,temp);
                i=0;
                j=0;
                strcpy(temp,"");
                while ( lign[i] != ' ' )
                {
                    temp[j]=lign[i];
                    i++;
                    j++;
                }
                temp[j]='\0';
                Streets[k].L=atoi(temp);
                i=0;
                }
                temp[j]='\0';
                Cars[k].Nb_path=atoi(temp);
                i=0;
                j=0;
                strcpy(temp,"");
                for (z=0;z<Cars[k].Nb_path;z++)
                {
                    while ( lign[i] != ' ' )
                    {
                        temp[j]=lign[i];
                        i++;
                        j++;
                    }
                    temp[j]='\0';
                    strcpy(Cars[k].Path[z],temp);
                    j=0;
                }
                i=0;
                strcpy(temp,"");
            }
        }
    fclose(f);
    return 0;
}

void init_submision(Intersection *inters,Street *Streets,int S,int I,int D)
{
    for(int k=0;k<I;k++)
    {
        inters[k].Eff=1;
        inters[k].Nb_Street=0;
    }
    for(int k=0;k<S;k++)
    {
        if (inters[Streets[k].Debut].Eff==1) inters[Streets[k].Debut].Eff=0;
        if (inters[Streets[k].Fin].Eff==1) inters[Streets[k].Fin].Eff=0;
        strcpy(inters[Streets[k].Fin].Streets[inters[Streets[k].Fin].Nb_Street].Name,Streets[k].name);
        inters[Streets[k].Fin].Streets[inters[Streets[k].Fin].Nb_Street].T=rand()%(D+1);
        inters[Streets[k].Fin].Nb_Street=inters[Streets[k].Fin].Nb_Street+1;
    }
}
