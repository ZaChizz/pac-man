#include <iostream>
#include <iterator>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>
#include "getch.h"

#define COLS 11
#define ROWS 10

#include "matrix.h"
#include "pacman.h"



int main ( )
{
    FILE *map;
    int mapSize = ROWS * COLS; 
    char c; 

    int i = 0, j = 0; // start point for Q, P

    char mass[ROWS][COLS];

    map = fopen("map.in", "r");

    matrixScanChar(map, mass);
    
    mass[i][j] = 'Q';

    do {
        system("cls");
        copy ( &(**mass), &(**mass)+mapSize, std::ostream_iterator<char>(std::cout));
        c = getch();

        switch ( c )
        {
            case 72: case 'w': if ( moove('w', mass, i, j) ){ mass[i][j] = '.'; i--;}
            break;
            case 80: case 's': if ( moove('s', mass, i, j) ){ mass[i][j] = '.'; i++;}
            break;
            case 75: case 'a': if ( moove('a', mass, i, j) ){ mass[i][j] = '.'; j--;}
            break;
            case 77: case 'd': if ( moove('d', mass, i, j) ){ mass[i][j] = '.'; j++;}
            break;
            default: ;
        }
        mass[i][j] = 'Q';
    }
    while( c!= 27); // Esc

    fclose(map);
    system("pause");
    
    return 0;
}
