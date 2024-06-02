#include <iostream>

#include "Menu.hpp"

using namespace std;

Menu::Menu(Board& b) : board(b) {
    if (!font.loadFromFile("../fonts/Gohu.ttf")) {
        cout << "no se ha podido cargar la fuente Gohu.ttf" << endl;
    } else {
        cout << "se ha cargado la fuente Gohu.ttf" << endl;
    }
    
    for (int i = 0; i < MENU_GRID_SIZE; i++) {
        gridShape[i] = RectangleShape(Vector2f(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT));
        gridShape[i].setPosition(BOARD_WIDTH + 25, i*MENU_BUTTON_HEIGHT + 25*i + 25);
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
        int textPosX = (BOARD_WIDTH) + 25 + xDiff/2;
        int textPosY = i * (MENU_BUTTON_HEIGHT + 25) + 25;
        gridText[i].setPosition(textPosX, textPosY);

        cout << gridText[i].getPosition().x << " " << gridText[i].getPosition().y << endl;
    }
}

void Menu::handleButtonClick(int x, int y, Event::EventType event) {
    const int menuXStart = BOARD_WIDTH + 25;
    const int menuXEnd = BOARD_WIDTH + MENU_SIZE - 25;

    // Verificar que se haya clicado en la zona x de los botones
    if (x > menuXStart && x < menuXEnd) {
        for (int i = 0; i < MENU_GRID_SIZE; ++i) {
            const int buttonYStart = i * (MENU_BUTTON_HEIGHT + 25) + 25;
            const int buttonYEnd = buttonYStart + MENU_BUTTON_HEIGHT;

            // Verificar que se haya clicado en el botón i
            if (y > buttonYStart && y < buttonYEnd) {
                changeButtonClickStyle(i, event);

                switch (i) {
                    case 0:
                        board.genRandomBoard();
                        break;
                    case 1:
                        board.cleanBoard();
                        break;
                    case 2:
                        cout << "save" << endl;
                        break;
                    case 3:
                        cout << "load" << endl;
                        break;
                    case 4:
                        cout << "about" << endl;
                        break;
                    default:
                        break;
                }
                break; // Salir del bucle después de encontrar el botón correcto
            }
        }
    }

}

void Menu::changeButtonClickStyle(int button, Event::EventType event) {
    if (event == Event::MouseButtonReleased) {
        gridText[button].setFillColor(Color(255, 255, 255));
        gridShape[button].setFillColor(Color(50, 50, 50));
    } else {
        gridText[button].setFillColor(Color(50, 50, 50));
        gridShape[button].setFillColor(Color(255, 255, 255));
    }
}

void Menu::draw(RenderTarget& rt, RenderStates rs) const {
    for (int i = 0; i < MENU_GRID_SIZE; i++) {
        rt.draw(gridShape[i]);
        rt.draw(gridText[i]);
    }
}