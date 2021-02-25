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
    int L;
}green_light;
typedef struct
{
    int Id;
    int Nb_Street;
    green_light Streets[100000];
}Intersection;


int main()
{
    int D,I,F,S,V;
    Car Cars[1000];
    Intersection Inters[100000];
    Street Streets[100000];
    printf("Hello world!\n");
    return 0;
}
