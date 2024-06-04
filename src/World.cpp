#include "World.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

/* Text-Colors:
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15
*/

void changeColor(int desiredColor){ //Aus einem Forum entnommen, da System(Color XX) die Farbe für das gesamte Terminal ändert
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void resetColor(){
    changeColor(15); //Set to White-Text
}

void World::generateWorld(){
    srand(time(0)); //Erstellt einen Seed abhaengig von derzeitiger Zeit
    relicCounter = 0; // Zähler für die Anzahl der Relikte

    for (int i = 0; i < World::row; i++) {
        for (int j = 0; j < World::col; j++) {
            int randomValue = rand() % 10 + 1; // Zufallszahl zwischen 1 und 10
                if (randomValue <= 4) {
                    World::worldMap[i][j] = 'e'; // Leeres Feld (4/10 Wahrscheinlichkeit)
                } else if (randomValue <= 8) {
                    World::worldMap[i][j] = 'D'; // Gefahrenfeld (4/10 Wahrscheinlichkeit)
                } else if (randomValue == 9) {
                    World::worldMap[i][j] = 'B'; // Brunnen (1/10 Wahrscheinlichkeit)
                } else if (randomValue == 10) {
                    World::worldMap[i][j] = 'R'; // Relikt (1/10 Wahrscheinlichkeit, !! mindestens ein Relikt !!)
                    relicCounter++;
                } else {
                    World::worldMap[i][j] = 'e'; // Standard: Leeres Feld
                }
            }
    }

    if (relicCounter == 0) {
    // Sicherstellen, dass mindestens ein Relikt vorhanden ist
        int x = rand() % World::row;
        int y = rand() % World::col;
            if(x==0 && y== 0){ //Damit das minimum-Relic nicht auf der Spieler-Startposition entsteht (womöglich nicht fail-safe)
                x = rand() % World::row;
                y = rand() % World::col;
            }
        World::worldMap[x][y] = 'R';
        relicCounter++;
    }
}

char World::fieldValue(int x,int y){
    switch(World::worldMap[x][y]){
    case('e'):
        changeColor(11);
        return World::worldMap[x][y];
        break;
    case('D'):
        changeColor(4);
        return World::worldMap[x][y];
        break;
    case('B'):
        changeColor(1);
        return World::worldMap[x][y];
        break;
    case('R'):
        changeColor(14);
        return World::worldMap[x][y];
        break;
    case('P'):
        changeColor(2);
        return World::worldMap[x][y];
        break;
    }
}


void World::printBorder(int maxVal) {
    for (int i = 0; i < maxVal; i++) {
        if (i == 0) {
            std::cout << " |";
        } else if (i == maxVal - 1) {
            std::cout << "| ";
        } else {
            std::cout << "---";
        }
    }
    std::cout << std::endl;
}

void World::printField(int maxVal, int rowNum) {
    for (int i = 0; i < maxVal; i++) {
        if (i == 0) {
            std::cout << " |";
            std::cout << fieldValue(rowNum, i);
            resetColor();
            std::cout << "|";
        } else {
            std::cout << fieldValue(rowNum, i);
            resetColor();
            std::cout << "|";
        }
    }
    std::cout << std::endl;
}

void World::renderWorld(char arr[row][col]) {
    for (int i = 0; i < row; i++) {
        printBorder(col);
        printField(col,i);
    }
    printBorder(col);
}

World::World(){
    generateWorld();
};

World::~World(){

};
