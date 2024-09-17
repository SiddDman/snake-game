#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#undef main

using namespace std;

int main(int argc, char *argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);
    auto window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 780, 0);
    auto renderer = SDL_CreateRenderer(window, -1, 0);
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
    SDL_Rect head{500, 390, 10, 10};
    // Snake body - Using deque as we have to add in left end when head is towards right and vice versa. Similar for vecrtical case.
    deque<SDL_Rect> rq;
    int size=1;

    // Food
    vector<SDL_Rect> food;

    // Create Food on the map
    for (int i = 0; i < 100; i++)
        food.emplace_back(rand() % 100 * 0, rand() % 100 * 10, 10, 10);


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
                    return EXIT_SUCCESS;

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
            head.y += 10;
            break;
        case UP:
            head.y -= 10;
            break;
        case LEFT:
            head.x -= 10;
            break;
        case RIGHT:
            head.x += 10;
            break;
        default:
            break;
        }

        // Clear Window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw Body
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &head);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    return 0;
}