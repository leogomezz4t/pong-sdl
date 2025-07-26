#include "numbers.hpp"
#include <stdio.h>

void Number::setTilesZero() {
    addTile(1, 0);
    addTile(2, 0);
    addTile(0, 1);
    addTile(3, 1);
    addTile(0, 2);
    addTile(3, 2);
    addTile(0, 3);
    addTile(3, 3);
    addTile(1, 4);
    addTile(2, 4);
}

void Number::setTilesOne() {
    addTile(3, 0);
    addTile(2, 1);
    addTile(3, 1);
    addTile(1, 2);
    addTile(3, 2);
    addTile(3, 3);
    addTile(3, 4);
}
void Number::setTilesTwo() {
    addTile(1, 0);
    addTile(2, 0);
    addTile(0, 1);
    addTile(3, 1);
    addTile(2, 2);
    addTile(1, 3);
    addTile(0, 4);
    addTile(1, 4);
    addTile(2, 4);
    addTile(3, 4);
}

void Number::setTilesThree() {
    addTile(1, 0);
    addTile(2, 0);
    addTile(0, 1);
    addTile(3, 1);
    addTile(2, 2);
    addTile(0, 3);
    addTile(3, 3);
    addTile(1, 4);
    addTile(2, 4);
}

void Number::setTilesFour() {
    addTile(2, 0);
    addTile(3, 0);
    addTile(1, 1);
    addTile(3, 1);
    addTile(0, 2);
    addTile(1, 2);
    addTile(2, 2);
    addTile(3, 2);
    addTile(3, 3);
    addTile(3, 4);
}

void Number::setTilesFive() {
    addTile(0, 0);
    addTile(1, 0);
    addTile(2, 0);
    addTile(3, 0);
    addTile(0, 1);
    addTile(1, 1);
    addTile(2, 1);
    addTile(3, 2);
    addTile(0, 3);
    addTile(3, 3);
    addTile(1, 4);
    addTile(2, 4);

}

void Number::setTilesSix() {
    addTile(2, 0);
    addTile(1, 1);
    addTile(0, 2);
    addTile(1, 2);
    addTile(2, 2);
    addTile(0, 3);
    addTile(3, 3);
    addTile(1, 4);
    addTile(2, 4);
}

void Number::setTilesSeven() {
    addTile(0, 0);
    addTile(1, 0);
    addTile(2, 0);
    addTile(3, 0);
    addTile(3, 1);
    addTile(2, 2);
    addTile(1, 3);
    addTile(0, 4);
}

void Number::setTilesEight() {
    addTile(1, 0);
    addTile(2, 0);
    addTile(0, 1);
    addTile(3, 1);
    addTile(1, 2);
    addTile(2, 2);
    addTile(0, 3);
    addTile(3, 3);
    addTile(1, 4);
    addTile(2, 4);
}

void Number::setTilesNine() { 
    addTile(1, 0);
    addTile(2, 0);
    addTile(0, 1);
    addTile(3, 1);
    addTile(1, 2);
    addTile(2, 2);
    addTile(3, 2);
    addTile(2, 3);
    addTile(1, 4);
}

void Number::setNumber(int n) {
    if (n < 0)
    {
        printf("Number set %d is less than 0\n", n);
        return;
    }

    if (n > 9)
    {
        printf("Number set %d is greater than 9\n", n);
        return;
    }

    num = n;
    
    // set tiles
    clearTiles();
    switch (n) {
        case 0:
            setTilesZero();
            break;
        case 1:
            setTilesOne();
            break;
        case 2:
            setTilesTwo();
            break;
        case 3:
            setTilesThree();
            break;
        case 4:
            setTilesFour();
            break; 
        case 5:
            setTilesFive();
            break;
        case 6:
            setTilesSix();
            break;
        case 7:
            setTilesSeven();
            break;
        case 8:
            setTilesEight();
            break;
        case 9:
            setTilesNine();
            break;
    }
}

int Number::getNumber() {
    return num;
}