#include <SFML/Graphics.hpp>
#include <iostream>

#include "../includes/Board.hpp"

using namespace sf;

int main() {
    RenderWindow window(
        VideoMode(
            (BOARD_SIZE * BOARD_SHAPE_SIZE), 
            BOARD_SIZE * BOARD_SHAPE_SIZE
            ), 
        "Game Of Life (Conway's Game)"
        );
    window.setFramerateLimit(5);

    Board board;
    bool isGameRunning = false;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                board.handleClick(mouseX, mouseY);
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                isGameRunning ? (isGameRunning = false) : (isGameRunning = true);
                cout << isGameRunning << endl;
            }

        }

        if (isGameRunning)
        {
            board.genNextGeneration();
        }
        

        board.updateBoardColor();

        window.clear(Color(22, 22, 22));
        window.draw(board);
        window.display();
    
    }

    return 0;
}
