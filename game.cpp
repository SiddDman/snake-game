#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#undef main

using namespace std;

void startGame(int &window_height, int &window_width, auto &renderer, bool &walls)
{
    SDL_Event e;
    enum Direction
    {
        DOWN,
        LEFT,
        RIGHT,
        UP
    };

    int dir = 0;

    // Snake starting position
    SDL_Rect head{window_width / 2, window_height / 2, 10, 10};

    SDL_Rect topWall{0, 0, window_width, 0};                     // Top border
    SDL_Rect bottomWall{0, window_height - 10, window_width, 0}; // Bottom border
    SDL_Rect leftWall{0, 0, 0, window_height};                   // Left border
    SDL_Rect rightWall{window_width - 10, 0, 0, window_height};  // Right border

    // Walls
    if (walls)
    {
        topWall.h = 10;    // Top border
        bottomWall.h = 10; // Bottom border
        leftWall.w = 10;   // Left border
        rightWall.w = 10;  // Right border
    }

    // Snake body - Using deque as we have to add in left end when head is towards right and vice versa. Similar for vecrtical case.
    deque<SDL_Rect> rq;
    int size = 1;

    // Food
    SDL_Rect food;
    food.x = rand() % 980;
    food.y = rand() % 760;
    food.w = 10;
    food.h = 10;

    // Game Loop
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = false;
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    cout << "Right key was pressed" << endl;
                    dir = RIGHT;
                    break;
                case SDLK_UP:
                    cout << "Up key was pressed" << endl;
                    dir = UP;
                    break;
                case SDLK_DOWN:
                    cout << "Down key was pressed" << endl;
                    dir = DOWN;
                    break;
                case SDLK_LEFT:
                    cout << "Left key was pressed" << endl;
                    dir = LEFT;
                    break;
                case SDLK_ESCAPE:
                    SDL_Quit();
                    return;

                default:
                    break;
                }
            }
            else if (e.type == SDL_KEYUP)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    cout << "Right key was released" << endl;
                    break;
                case SDLK_UP:
                    cout << "Up key was released" << endl;
                    break;
                case SDLK_DOWN:
                    cout << "Down key was released" << endl;
                    break;
                case SDLK_LEFT:
                    cout << "Left key was released" << endl;
                    break;

                default:
                    break;
                }
            }
        }

        // Move head
        switch (dir)
        {
        case DOWN:
            head.y += 5;
            break;
        case UP:
            head.y -= 5;
            break;
        case LEFT:
            head.x -= 5;
            break;
        case RIGHT:
            head.x += 5;
            break;
        default:
            break;
        }

        // Collsion Detection
        // Collision between food and head of snake
        // if (head.x == food.x && head.y == food.y)
        if (SDL_HasIntersection(&head, &food))
        {
            size += 5;
            food.x = rand() % 980;
            food.y = rand() % 760;
        }

        // Collision between head and tail
        for_each(rq.begin(), rq.end(), [&](auto &tail)
                 {
            if(head.x==tail.x && head.y==tail.y){
                size=1;
                // running=false;
            } });

        // Collision between snake and wall
        if (walls)
        {
            if (SDL_HasIntersection(&head, &topWall) || SDL_HasIntersection(&head, &bottomWall) || SDL_HasIntersection(&head, &leftWall) || SDL_HasIntersection(&head, &rightWall))
            {
                running = false; // Stop the game if the snake hits a wall
            }
        }
        else
        {
            if (head.y < 0)
                head.y = window_height;
            else if (head.y >= window_height)
                head.y = 0;
            else if (head.x >= window_width)
                head.x = 0;
            else if (head.x < 0)
                head.x = window_width;
        }

        // Adding food to the body of the snake
        rq.push_front(head);

        // if the size of the queue is more than the size variable, then it means snake has hit his tail and now the size needs to be reduced to 1
        while (rq.size() > size)
            rq.pop_back();

        // Clear Window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw the snake
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for_each(rq.begin(), rq.end(), [&](auto &snake_segment)
                 { SDL_RenderFillRect(renderer, &snake_segment); });

        // Draw the food
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &food);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &topWall);
        SDL_RenderFillRect(renderer, &bottomWall);
        SDL_RenderFillRect(renderer, &leftWall);
        SDL_RenderFillRect(renderer, &rightWall);

        SDL_RenderPresent(renderer);
        SDL_Delay(25);
    }
}

void showIntroScreen(SDL_Renderer *renderer, TTF_Font *font, bool &walls, int &window_width, int &window_height)
{
    SDL_Event e;
    SDL_Color textColor = {28, 255, 15}; // White text

    // Create text surface and texture for the intro screen
    SDL_Surface *textSurface;
    SDL_Texture *textTexture;

    // Intro Screen Text
    SDL_Rect textRect = {0, 0, 0, 0};
    SDL_Rect titleRect = {window_width / 4 + 70, window_height / 4, 400, 100};
    SDL_Rect modeRect = {window_width / 4 + 100, window_height / 2, 400, 100};
    SDL_Rect instructionRect = {window_width / 4 + 150, static_cast<int>(window_height / 1.5), 400, 100};

    while (true)
    {
        // Handle events
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_1:
                    walls = true;
                    return;
                case SDLK_2:
                    walls = false;
                    return;
                case SDLK_ESCAPE:
                    SDL_Quit();
                    exit(0);
                default:
                    break;
                }
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render title text
        textSurface = TTF_RenderText_Solid(font, "Snake Game", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
        textRect.x = titleRect.x + (titleRect.w - textRect.w) / 2;
        textRect.y = titleRect.y + (titleRect.h - textRect.h) / 2;
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        // Render mode selection text
        textSurface = TTF_RenderText_Solid(font, "[ 1 ]: Classic (Walls)", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
        textRect.x = modeRect.x;
        textRect.y = modeRect.y - 40;
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        textSurface = TTF_RenderText_Solid(font, "[ 2 ]: Borderless", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
        textRect.x = modeRect.x - 1;
        textRect.y = modeRect.y;
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        // Render instructions text
        textSurface = TTF_RenderText_Solid(font, "Press 1 for Classic mode or 2 for Borderless mode", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textRect.w, &textRect.h);
        textRect.x = instructionRect.x + (instructionRect.w - textRect.w) / 2;
        textRect.y = instructionRect.y + (instructionRect.h - textRect.h) / 2;
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }
}

int main(int argc, char *argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    int window_width = 1200;
    int window_height = 780;

    auto window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event e;
    bool walls = true;

    // Load font
    TTF_Font *font = TTF_OpenFont("fonts/PixelLetters.ttf", 50);
    if (!font)
    {
        cerr << "Failed to load font" << endl;
        SDL_Quit();
        return -1;
    }

    // Intro Screen code
    showIntroScreen(renderer, font, walls, window_width, window_height);

    // Start the Game
    startGame(window_height, window_width, renderer, walls);

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
