#include <iostream>
#include <stdlib.h>
#include "World.h"
#include "PlayerCharacter.h"

/*  zuviel Zeit in Optik investiert.
    zuwenig Planung der Klassen => methoden referenzieren Klassen-fremde Parameter
    ==> vlt. Attributs-Vergleich extern (in main()-code)
    ??korrekte Einbindung von Libraries, in jedem header notwendig? -> recherche!
*/


int main() {
    World world;
    PlayerCharacter myPC;
    char WorldArr[World::row][World::col];
    myPC.setPlayerPos(world);
    char playerInput;

    while (!myPC.WinCondition) {
        system("cls");
        //relic-test -> Algo für minimum Relic-Generation nicht stabil
        //std::cout<<"Max Relic: "<<world.relicCounter<<std::endl;
        //
        myPC.playerStatus();
        world.renderWorld(WorldArr);

        std::cout << "W/A/S/D to move: ";
        std::cin >> playerInput;

        switch (playerInput) {
            case 'W':
            case 'w':
                if(myPC.pos_x==0){
                    myPC.statusMsg = "Out of Bounds!";
                    break;
                }else{
                myPC.moveUp(world);
                //myPC.statusMsg = "Moved Up!";
                break;
                }
            case 'A':
            case 'a':
                if(myPC.pos_y==0){
                    myPC.statusMsg = "Out of Bounds!";
                    break;
                }else{
                myPC.moveLeft(world);
                //myPC.statusMsg = "Moved Left!";
                break;
                }
            case 'S':
            case 's':
                if(myPC.pos_x==4){
                    myPC.statusMsg = "Out of Bounds!";
                    break;
                }else{
                myPC.moveDown(world);
                //myPC.statusMsg = "Moved Down";
                break;
                }
            case 'D':
            case 'd':
                if(myPC.pos_y==4){
                    myPC.statusMsg = "Out of Bounds!";
                    break;
                }else{
                myPC.moveRight(world);
                //myPC.statusMsg = "Moved Right!";
                break;
                }
        }
    }
    system("cls");
    myPC.playerStatus();
    world.renderWorld(WorldArr);
    //std::cout << myPC.statusMsg << std::endl;


    return 0;
}
