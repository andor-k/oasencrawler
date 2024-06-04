#ifndef WORLD_H
#define WORLD_H


class World
{

    public:
        static const int row = 5;
        static const int col = 5;
        char worldMap[row][col];
        char fieldValue(int x,int y);
        int relicCounter=0;
        World();
        virtual ~World();

        void printBorder(int maxVal);
        void printField(int maxVal, int rowNum);
        void renderWorld(char arr[row][col]);
        void generateWorld();


};

#endif // WORLD_H
