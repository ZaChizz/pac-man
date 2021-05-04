#include <iostream>
#include <iterator>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>
#include "getch.h"

#define ROWS 10
#define COLS 11

int main ( )
{
    int size = ROWS * COLS;
    char c; int i = ROWS / 2, j = ROWS / 2;
    char mass[ROWS][COLS];

    std::fill ( &(**mass), &(**mass)+size, '*' );

    for ( int k = 0; k < ROWS; k++ )
        mass[k][ROWS] = '\n';
    mass[i][j] = 'Q';

    do {
        system("cls");
        copy ( &(**mass), &(**mass) + size, std::ostream_iterator<char>( std::cout ) );
        c = getch();
        switch ( c) {
            case 72: 
                case 'w': if ( i >  0 ){ mass[i][j] = '*'; i--;}
            break;
            case 80: 
                case 's': if ( i < ROWS - 1 ){ mass[i][j] = '*'; i++;}
            break;
            case 75: 
                case 'a': if ( j >  0 ){ mass[i][j] = '*'; j--;}
            break;
            case 77: 
                case 'd': if ( j < ROWS - 1 ){ mass[i][j] = '*'; j++;}
            break;
        default: ;
        }
        mass[i][j] = 'Q';
    }

    while( c!= 27); // Esc
    system("pause");
    return 0;
}
