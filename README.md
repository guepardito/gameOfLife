# Game of Life

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Controls](#controls)

## Introduction
The **Game of Life** is a cellular automaton devised by the British mathematician John Horton Conway. The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.

## Features
- Create random and customized game states.
- Simulate the evolution of the game board over time.
- Save and load game states from files. (pending)

## Installation
To run this project locally, follow these steps:

1. **Clone the repository**
    ```bash
    https://github.com/guepardito/gameOfLife.git
    cd gameOfLife
    ```

2. **create a build directory**
    ```bash
    mkdir build
    cd build
    ```

3. **build the project**
    ```
    cmake ..
    make
    ```

3. **run the executable**
    ```
    ./gameOfLife
    ```

## Controls

    Start/Pause: Spacebar
    Click con the squares to grow/kill a cell