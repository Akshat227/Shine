#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>

int win_width = 650;
int win_height = 600;
bool running = true;
SDL_Event event;


void DrawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius){

    for(int angle = 0; angle < 360; angle++){
        float rad = angle* M_PI / 180.0f;
        int x = centerX + radius* cos(rad);
        int y = centerY + radius* sin(rad);
        SDL_RenderDrawPoint(renderer, x, y);
        

    }




}



int main(int argc, char* argv[]){


    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
    return 1;
}

    SDL_Window* window = SDL_CreateWindow("Shine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_width, win_height, SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

while (running){  // main game loop

    while(SDL_PollEvent(&event)){

        if (event.type == SDL_QUIT)
            running = false;

    }
  // main game loop

 
        SDL_SetRenderDrawColor(renderer, 10, 10, 30, 255);  // dark blue bg
        SDL_RenderClear(renderer);

        
        SDL_SetRenderDrawColor(renderer, 255, 200, 0, 255);  // yellow

        
        DrawCircle(renderer, win_width / 2, win_height / 2, 100);

       
        SDL_RenderPresent(renderer);



}





SDL_DestroyWindow(window);
SDL_Quit();


return 0;

}