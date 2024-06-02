#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Board.hpp"
#include "Menu.hpp"

using namespace sf;

int main() {
    RenderWindow window(
        VideoMode(
            BOARD_WIDTH + MENU_SIZE,
            BOARD_WIDTH
            ), 
        "Game Of Life (Conway's Game)"
        );
    window.setFramerateLimit(60);

    Board board;
    Menu menu(board);

    bool isGameRunning = false;

    Clock generationClock;
    const float generationInterval = .2f;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                board.handleClick(mouseX, mouseY);
                menu.handleButtonClick(mouseX, mouseY, event.type);
            }

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;
                menu.handleButtonClick(mouseX, mouseY, event.type);
            }

            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                isGameRunning = !isGameRunning;
                if (isGameRunning) {
                    generationClock.restart();
                }
            }
        }

        if (isGameRunning) {
            if (generationClock.getElapsedTime().asSeconds() >= generationInterval) {
                board.genNextGeneration();
                generationClock.restart(); // Reiniciar el reloj después de llamar a la función
            }
        }

        board.updateBoardColor();

        window.clear(Color(22, 22, 22));
        window.draw(board);
        window.draw(menu);
        window.display();
    }

    return 0;
}
