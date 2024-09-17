# Snake Game - Classic Version (C++ and SDL2)

This repository contains the source code for a classic snake game developed using C++ and SDL2 graphics. The game includes various features such as an intro screen, different game modes, and a game over screen.

## Table of Contents
- [Game Features](#game-features)
  - [Intro Screen](#intro-screen)
  - [Game](#game)
  - [Game Over Screen](#game-over-screen)
- [Set Up](#set-up)
  - [About SDL2](#about-sdl2)
  - [Steps to Download and Set Up SDL2_ttf](#steps-to-download-and-set-up-sdl2_ttf)
  - [Building and Running the Game](#building-and-running-the-game)

## Game Features

### Intro Screen
The game starts with an intro screen where players are presented with the title **"Snake"** and given the option to select between two game modes:

- **Classic:** In this mode, the snake will collide with the walls and end the game if it hits them.
- **Borderless:** In this mode, the snake can pass through the edges of the screen and re-appear from the opposite side.

### Game 
The game keeps track of the score the user achieves. Every time you eat the food, you get 10 points.

### Game Over Screen
When the player loses (either by colliding with the wall or their own tail), the game transitions to a game over screen. Players are given two options:

- **Play Again:** Restart the game in Classic or Borderless mode.
- **Exit:** Close the game.

## Set Up 

### About SDL2
SDL2 (Simple DirectMedia Layer) is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware. It is commonly used in the development of video games.

1. **Download SDL2:**

   - Visit the [SDL2 website](https://www.libsdl.org/download-2.0.php) to download the latest version.
   - Choose the development library for your operating system (Windows, Mac, or Linux).

2. **Unzip the SDL2 Files:**
   - Once downloaded, unzip the file.
   - Copy the `include` and `lib` folders from the unzipped SDL2 folder to the project directory.
   - Additionally, copy the necessary `.dll` files from the `bin` folder to your project directory to ensure the game runs properly.

### Steps to Download and Set Up SDL2_ttf

1. **Download SDL2_ttf:**

   - Visit the [SDL2_ttf download page](https://www.libsdl.org/projects/SDL_ttf/) to download the latest version.

2. **Unzip the SDL2_ttf Files:**
   - Unzip the file and copy the `include` and `lib` folders into the appropriate folders in your project directory (`include` and `lib`).
   - Copy the `SDL_ttf.h` file to the `/snake-game/include` folder from the unzipped folder.
   - Similarly, copy only the `.dll` files from the SDL2_ttf's `lib` folder to `/snake-game/lib`.

3. To **download TTF fonts** visit: [FontSpace](https://www.fontspace.com/category/ttf).

### Building and Running the Game

To compile and run the game, use the following command in your terminal:

```bash
g++ -Iinclude -Llib game.cpp -o snake
```

Once compiled run the following command to launch the game.
```bash
.\snake-game.exe

