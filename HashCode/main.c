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
