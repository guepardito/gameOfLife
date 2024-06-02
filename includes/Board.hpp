#pragma once

#include <SFML/Graphics.hpp>
#include <cstring>

#include "consts.hpp"

using namespace sf;
using namespace std;

class Board : public Drawable {
    private:
        int board[BOARD_SIZE][BOARD_SIZE];
        RectangleShape boardShapes[BOARD_SIZE][BOARD_SIZE];
    public:
        Board();
        void updateBoardColor();
        void handleClick(int x, int y);
        int countCells(int x, int y);
        void genNextGeneration();

        void genRandomBoard();
        void cleanBoard();

        virtual void draw(RenderTarget&, RenderStates) const;
};