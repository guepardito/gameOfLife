#pragma once

#include <SFML/Graphics.hpp>
#include <cstring>

#include "Board.hpp"
#include "consts.hpp"

using namespace sf;
using namespace std;

class Menu : public Drawable {
    private:
        int grid[MENU_GRID_SIZE];
        RectangleShape gridShape[MENU_GRID_SIZE];
        Text gridText[MENU_GRID_SIZE];
        Font font;

        Board& board;
    public:
        Menu(Board& b);
        void handleButtonClick(int x, int y, Event::EventType event);
        void changeButtonClickStyle(int button, Event::EventType event);
        
        virtual void draw(RenderTarget&, RenderStates) const;
};