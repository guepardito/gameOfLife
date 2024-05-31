#include <iostream>

#include "../includes/Board.hpp"

using namespace std;

Board::Board() {
    memset(board, 0, sizeof(board));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            boardShapes[i][j] = RectangleShape(Vector2f(BOARD_SHAPE_SIZE, BOARD_SHAPE_SIZE));
            boardShapes[i][j].setPosition(i*BOARD_SHAPE_SIZE, j*BOARD_SHAPE_SIZE);
            boardShapes[i][j].setFillColor(Color(50, 50, 50));
            boardShapes[i][j].setOutlineColor(Color(0, 0, 0));
            boardShapes[i][j].setOutlineThickness(2);
        }
    }
}

void Board::updateBoardColor() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case 0: 
                    boardShapes[i][j].setFillColor(Color(50, 50, 50)); // muelto
                    break;
                case 1: 
                    boardShapes[i][j].setFillColor(Color(123, 224, 173)); // vivo
                    break;
            }
        }
    }
}

void Board::handleClick(int x, int y) {
    int i = x / BOARD_SHAPE_SIZE;
    int j = y / BOARD_SHAPE_SIZE;

    if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
        board[i][j] = (board[i][j] + 1) % 2;

        cout << "Se ha cambiado la celula x: " << i << ", y: " << j;
        cout << "... ahora esta " << ((board[i][j] == 0) ? "muelto" : "vivo") << endl;
    }
}

int Board::countCells(int x, int y) {
    int suma = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nuevaFila = x + i;
            int nuevaColumna = y + j;
            
            if (nuevaFila >= 0 && nuevaFila < BOARD_SIZE && nuevaColumna >= 0 && nuevaColumna < BOARD_SIZE) {
                suma += board[nuevaFila][nuevaColumna];
            }
        }
    }

    return suma;
}

// implementacion del algoritmo principal del juego de conway

void Board::genNextGeneration() {
    int tempBoard[BOARD_SIZE][BOARD_SIZE];

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int liveNeighbors = countCells(i, j);

            if (board[i][j] == 1) {  // si la celda esta viva
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    tempBoard[i][j] = 0;  // muere por subpoblacion o sobrepoblacion
                } else {
                    tempBoard[i][j] = 1;  // sobrevive
                }
            } else {  // si la celda esta muerta
                if (liveNeighbors == 3) {
                    tempBoard[i][j] = 1;  // nace por reproduccion
                } else {
                    tempBoard[i][j] = 0;  // sigue muerta
                }
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }

}

void Board::draw(RenderTarget& rt, RenderStates rs) const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            rt.draw(boardShapes[i][j]);
        }
    }
}