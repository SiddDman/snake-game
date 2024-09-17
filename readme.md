# Snake Game - Classic Version (C++ and SDL2)

This repository contains the source code for a classic snake game developed using C++ and SDL2 graphics. The game includes various features such as an intro screen, different game modes, and a game over screen.

## About SDL2

SDL2 (Simple DirectMedia Layer) is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware. It is commonly used in the development of video games.

### Steps to Download and Set Up SDL2

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

### Compiling and Running the Game

To compile and run the game, use the following command in your terminal:

```bash
g++ -Iinclude -Llib game.cpp -o snake-game -lSDL2 -lSDL2main -lSDL2_ttf
```

Once compiled, you can run the game using:

```bash
.\snake-game.exe
```
