#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#include <World.h>
#include <string>

class World;

class PlayerCharacter
{
    public:
        PlayerCharacter();
        virtual ~PlayerCharacter();
        int playerHealth = 5;
        int playerRelicPoints = 0;
        bool WinCondition = false;
        int pos_x = 0;
        int pos_y = 0;
        void setPlayerPos(World &world);
        void moveUp(World &world);
        void moveDown(World &world);
        void moveLeft(World &world);
        void moveRight(World &world);
        void playerStatus();
        void fieldCheck(World &world, char field);
        void conditionCheck(World &world);
        std::string statusMsg = "Start!";

    protected:

    private:
};

#endif // PLAYERCHARACTER_H
