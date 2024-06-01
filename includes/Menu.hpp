#pragma once

#include <SFML/Graphics.hpp>
#include <cstring>

#include "consts.hpp"

using namespace sf;
using namespace std;

class Menu : public Drawable {
    private:
        int grid[MENU_GRID_SIZE];
        RectangleShape gridShape[MENU_GRID_SIZE];
        Text gridText[MENU_GRID_SIZE];
        Font font;
    public:
        Menu();
        
        virtual void draw(RenderTarget&, RenderStates) const;
};