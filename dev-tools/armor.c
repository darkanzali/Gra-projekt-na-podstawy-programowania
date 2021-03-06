/******************************/
/* Gra ASCII "Przygody kloca" */
/* © 2016 Kamil Poniatowski   */
/******************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ILE 10
#define MAX_NAME 10

#pragma pack(push)
#pragma pack(1)

typedef struct { // Potwór
    int def;
    char name[ MAX_NAME ];
    int weight;
} Armor;

#pragma pack(pop)

int main() {
    int count = ILE;

    FILE *file;
    file = fopen( "armors.bin", "wb" );

    fwrite( &count, sizeof( int ), 1, file );

    Armor a[ ILE ];

    a[ 0 ].def = 0;
    strcpy( a[ 0 ].name, "brak" );
    a[ 0 ].weight = 0;

    a[ 1 ].def = 1;
    strcpy( a[ 1 ].name, "Koszula" );
    a[ 1 ].weight = 0;

    a[ 2 ].def = 2;
    strcpy( a[ 2 ].name, "Płaszcz" );
    a[ 2 ].weight = 0;

    a[ 3 ].def = 4;
    strcpy( a[ 3 ].name, "Skóra" );
    a[ 3 ].weight = 0;

    a[ 4 ].def = 5;
    strcpy( a[ 4 ].name, "Pancerz" );
    a[ 4 ].weight = 0;

    a[ 5 ].def = 7;
    strcpy( a[ 5 ].name, "Kolczuga" );
    a[ 5 ].weight = 0;

    a[ 6 ].def = 8;
    strcpy( a[ 6 ].name, "Płytowa" );
    a[ 6 ].weight = 0;

    a[ 7 ].def = 9;
    strcpy( a[ 7 ].name, "Złota" );
    a[ 7 ].weight = 0;

    a[ 8 ].def = 11;
    strcpy( a[ 8 ].name, "Platynowa" );
    a[ 8 ].weight = 0;

    a[ 9 ].def = 12;
    strcpy( a[ 9 ].name, "Rycerska" );
    a[ 9 ].weight = 0;

    fwrite( a, sizeof( Armor ), ILE, file );

/*
0. nic
1. Płaszcz
2. Skóra
3. Kolczuga
4. Płytowy
5. Platynowy
*/

    return 0;
}
