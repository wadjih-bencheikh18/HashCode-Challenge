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
    green_light Streets[100000];
}Intersection;


int main()
{
    int D,I,F,S,V;
    Car Cars[1000];
    Intersection Inters[100000];
    Street Streets[100000];
    return 0;
}
void init_submision(Intersection *inters,Street *Streets,int S,int I)
{
    for(int k=0;k<I;k++)
    {
        inters[k].Eff=1;
        inters[k].Nb_Street=0;
    }
    for(int k=0;k<S;k++)
    {
        if (inters[Street[k].Debut].Eff==1) inters[Street[k].Debut].Eff=0;
        if (inters[Street[k].Fin].Eff==1) inters[Street[k].Debut].Eff=0;
        strcpy(inters[Street[k].Fin].Streets[inters[Street[k].Fin].Nb_Street].Name,Street[k].name);
        inters[Street[k].Fin].Nb_Street=inters[Street[k].Fin].Nb_Street+1;
        inters[Street[k].Fin].Streets[inters[Street[k].Fin].Nb_Street]=rand()%
    }
}
