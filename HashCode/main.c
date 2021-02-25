#include <stdio.h>
#include <stdlib.h>
typedef char string[31];
typedef struct
{
    int Nb_path;
    string Path[100];
}Car;
typedef struct
{
    int Debut;
    int Fin;
    char name[31];
    int L;
}Street;
typedef struct
{
    int Nb;
    int T;
}green_light;
typedef struct
{
    int Eff;
    int Nb_Street;
    green_light Streets[100];
}Intersection;


int main()
{
    int D,I,F,S,V;
    Car Cars[100];
    Intersection Inters[100];
    Street Streets[100];
    Init("a.txt",&D,&I,&S,&V,&F,Cars,Streets);
    return 0;
}

int Init(char nomt[20],int *D,int *I,int *S,int *V,int *F,Car *Cars,Street *Streets) ///affecter les val du fich au var
{
    FILE *f = fopen(nomt,"r");;
    char lign[1000],temp[20];
    int i=0,j=0,k,z;
    if ( f == NULL){
            printf("Error when opening the file %s\n",nomt);
            return 1;
    }

    while (!feof(f))
    {
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
            while ( (lign[i] != ' ')&& (lign[i] != '\n'))
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
                Streets[k].Fin=atoi(temp);
                i++;
                j=0;
                strcpy(temp,"");
                while ( lign[i] != ' ' )
                {
                    temp[j]=lign[i];
                    i++;
                    j++;
                }
                strcpy(Streets[k].name,temp);
                i++;
                j=0;
                strcpy(temp,"");
                while ( (lign[i] != ' ')&& (lign[i] != '\n'))
                {
                    temp[j]=lign[i];
                    i++;
                    j++;
                }
                Streets[k].L=atoi(temp);
                j=0;
                i=0;
                }
        }
        for (k=0;k<*V;k++)
        {
            if (fgets(lign, sizeof(lign),f))
            {
                i=0;
                strcpy(temp,"");
                while ( lign[i] != ' ' )
                {
                    temp[j]=lign[i];
                    i++;
                    j++;
                }
                temp[j]='\0';
                Cars[k].Nb_path=atoi(temp);
                i++;
                j=0;

                for (z=0;z<Cars[k].Nb_path;z++)
                {
                    strcpy(temp,"");
                    while ( (lign[i] != ' ')&& (lign[i] != '\n'))
                    {
                        temp[j]=lign[i];
                        i++;
                        j++;
                    }
                    temp[j]='\0';
                    i++;
                    strcpy(Cars[k].Path[z],temp);
                    j=0;
                }
            }
        }
}
 fclose(f);
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
        inters[Streets[k].Fin].Streets[inters[Streets[k].Fin].Nb_Street].Nb=k;
        inters[Streets[k].Fin].Streets[inters[Streets[k].Fin].Nb_Street].T=rand()%(D+1);
        inters[Streets[k].Fin].Nb_Street=inters[Streets[k].Fin].Nb_Street+1;
    }
}
