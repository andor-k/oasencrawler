#include "PlayerCharacter.h"
#include <World.h>
#include <iostream>
#include <windows.h>

void changeColorP(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);    //Aus einem Forum entnommen, da System(Color XX) die Farbe für das gesamte Terminal ändert
}

void resetColorP(){ //Muss bei jedem Move verwendet werden, da es sonst die Farbe durch die Field-Value für die gesamte Konsole übernimmt.
    changeColorP(15);
}

void PlayerCharacter::conditionCheck(World &world) {
    if (playerHealth <= 0) {
        statusMsg = "You Died! Game Over...";
        WinCondition = TRUE;
    } else if (playerRelicPoints == world.relicCounter) {
        statusMsg = "All Relics Collected. You Win!";
        WinCondition = TRUE;
    }
}

void PlayerCharacter::fieldCheck(World &world, char field){
    resetColorP();
    switch(field){
    case 'B':
        if(playerHealth==5){
                statusMsg="Already Full Health!";
                break;
        }else{
            playerHealth += 1;
            statusMsg="Healed 1 Life!";
            break;
        }
    case 'R':
        playerRelicPoints += 1;
        statusMsg="Relic collected";
        conditionCheck(world);
        break;
    case 'e':
        statusMsg="Landed on Empty Field";
        break;
    case 'D':
        int dangerRisk = rand()%6 +1;
        if (dangerRisk==6){
            playerHealth -= 1;
            statusMsg="Lost 1 Life!";
            conditionCheck(world);
            break;
        }else{
            statusMsg="Lucky! Danger Averted!";
            break;
        }
    }
}

void PlayerCharacter::setPlayerPos(World &world) {
    world.worldMap[pos_x][pos_y] = 'P';
}

void PlayerCharacter::moveUp(World &world){
    world.worldMap[pos_x][pos_y] = 'e';
    pos_x -= 1;
    char field = world.fieldValue(pos_x, pos_y);
    setPlayerPos(world);
    fieldCheck(world, field);
};
void PlayerCharacter::moveDown(World &world){
    world.worldMap[pos_x][pos_y] = 'e';
    pos_x += 1;
    char field = world.fieldValue(pos_x, pos_y);
    setPlayerPos(world);
    fieldCheck(world, field);
};
void PlayerCharacter::moveLeft(World &world){
    world.worldMap[pos_x][pos_y] = 'e';
    pos_y -= 1;
    char field = world.fieldValue(pos_x, pos_y);
    setPlayerPos(world);
    fieldCheck(world, field);
};
void PlayerCharacter::moveRight(World &world){
    world.worldMap[pos_x][pos_y] = 'e';
    pos_y += 1;
    char field = world.fieldValue(pos_x, pos_y);
    setPlayerPos(world);
    fieldCheck(world, field);
};
void PlayerCharacter::playerStatus() {
    std::cout << "Health: " << playerHealth << " | Relic Points: " << playerRelicPoints << std::endl;
    std::cout << "Status: " << statusMsg << std::endl;
}

PlayerCharacter::PlayerCharacter()
{

}

PlayerCharacter::~PlayerCharacter()
{

}
