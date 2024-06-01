#include <iostream>

#include "Menu.hpp"

using namespace std;

Menu::Menu() {
    if (!font.loadFromFile("../fonts/Gohu.ttf")) {
        cout << "no se ha podido cargar la fuente Gohu.ttf" << endl;
    } else {
        cout << "se ha cargado la fuente Gohu.ttf" << endl;
    }
    
    for (int i = 0; i < MENU_GRID_SIZE; i++) {
        gridShape[i] = RectangleShape(Vector2f(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT));
        gridShape[i].setPosition(BOARD_SIZE * BOARD_SHAPE_SIZE + 25, i*MENU_BUTTON_HEIGHT + 25*i + 25);
        gridShape[i].setFillColor(Color(50, 50, 50));
        gridShape[i].setOutlineColor(Color(0, 0, 0));
        gridShape[i].setOutlineThickness(2);

        switch (i) {
            case 0:
                gridText[i].setString("Generate universe");
                break;

            case 1:
                gridText[i].setString("Clean universe");
                break;

            case 2:
                gridText[i].setString("Save universe");
                break;

            case 3:
                gridText[i].setString("Load universe");
                break;

            case 4:
                gridText[i].setString("About");
                break;
            
            default:
                break;
        }

        gridText[i].setFont(font);
        gridText[i].setCharacterSize(30);
        gridText[i].setFillColor(Color(255, 255, 255));
        gridText[i].setStyle(Text::Bold);

        int xDiff = MENU_BUTTON_WIDTH - gridText[i].getLocalBounds().width;
        int textPosX = (BOARD_SIZE * BOARD_SHAPE_SIZE) + 25 + xDiff/2;
        int textPosY = i * (MENU_BUTTON_HEIGHT + 25) + 25;
        gridText[i].setPosition(textPosX, textPosY);

        cout << gridText[i].getPosition().x << " " << gridText[i].getPosition().y << endl;
    }
}

void Menu::draw(RenderTarget& rt, RenderStates rs) const {
    for (int i = 0; i < MENU_GRID_SIZE; i++) {
        rt.draw(gridShape[i]);
        rt.draw(gridText[i]);
    }
}