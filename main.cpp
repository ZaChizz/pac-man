#include <iostream>
#include <queue>
#include <iterator>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "getch.h"
#include "point.h"

#define COLS 41
#define ROWS 10
#define PACMAN 'H'
#define GHOST '$'

#include "matrix.h"
#include "pacman.h"

int main ( )
{
    FILE *map;
    int mapSize = ROWS * COLS; 
    char c;
    std::queue<char> buffer;

    Point pacmanCoord(0, 0);
    Point ghostCoord(0, 9);

    int i = 0, j = 0; // start point for Q, P

    int directionsCount;

    char way;
    char mass[ROWS][COLS];
    char direction[4];
    char forward = 'w';
    char backward = 's';
    char left = 'a';
    char right = 'd';

    map = fopen("map.in", "r");

    matrixScanChar(map, mass);

    buffer.push('*');

    mass[i][j] = PACMAN;
    mass[ghostCoord.getX()][ghostCoord.getY()] = GHOST;

    do {
        system("cls");
        copy ( &(**mass), &(**mass)+mapSize, std::ostream_iterator<char>(std::cout));
        c = getch();

//////////Ghost Start////////////////////////////////////////////////////
//////////Поиск возможного направления // В режими свободной навигации //

        directionsCount = 0;

        if ( moove(forward, mass, ghostCoord) ) {
            direction[directionsCount] = forward;
            directionsCount += 1;
        }
        if ( moove(right, mass, ghostCoord) ) {
            direction[directionsCount] = right;
            directionsCount += 1;
        }
        if ( moove(left, mass, ghostCoord) ) {
            direction[directionsCount] = left;
            directionsCount += 1;
        }
/////////Выбор направления для движения/////////
        if ( directionsCount > 1 ) {
            srand(time(NULL));
            way = direction[rand() % directionsCount];
        } else if ( directionsCount == 1 ) {
            way = direction[0];
        } else {
            way = backward;
        }
////////Настройка компаса/////////////
        if ( way == forward ) {

        }

        if ( way == backward ) {
            goBack(&forward, &backward);
        }

        if ( way == left ) {
            goTwist(&forward, &backward, &left, &right, 'l');
        }

        if ( way == right ) {
            goTwist(&forward, &backward, &left, &right, 'r');
        }
/////////Движение вперед с запоминанием ланшафта/////
        if ( way == 'w' ) {
            ghostCoord.decreaseX();
            buffer.push(mass[ghostCoord.getX()][ghostCoord.getY()]);
            ghostCoord.increaseX();
            mass[ghostCoord.getX()][ghostCoord.getY()] = buffer.front();
            buffer.pop();
            ghostCoord.decreaseX();
        }

        if ( way == 's' ) {
            ghostCoord.increaseX();
            buffer.push(mass[ghostCoord.getX()][ghostCoord.getY()]);
            ghostCoord.decreaseX();
            mass[ghostCoord.getX()][ghostCoord.getY()] = buffer.front();
            buffer.pop();
            ghostCoord.increaseX();
        }

        if ( way == 'a' ) {
            ghostCoord.decreaseY();
            buffer.push(mass[ghostCoord.getX()][ghostCoord.getY()]);
            ghostCoord.increaseY();
            mass[ghostCoord.getX()][ghostCoord.getY()] = buffer.front();
            buffer.pop();
            ghostCoord.decreaseY();
        }

        if ( way == 'd' ) {
            ghostCoord.increaseY();
            buffer.push(mass[ghostCoord.getX()][ghostCoord.getY()]);
            ghostCoord.decreaseY();
            mass[ghostCoord.getX()][ghostCoord.getY()] = buffer.front();
            buffer.pop();
            ghostCoord.increaseY();
        }
/////////////////Ghost End///////////////////////////////////////////////

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
        mass[i][j] = PACMAN;
        mass[ghostCoord.getX()][ghostCoord.getY()] = GHOST;
    }

    while( c!= 27); // Esc

    fclose(map);
    system("pause");
    
    return 0;
}
