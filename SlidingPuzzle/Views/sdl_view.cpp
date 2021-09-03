/**
 * sdl_view.cpp
 *
 * Implementation of sdl_view
 */

#include "sdl_view.h"

SDLView::SDLView()
    : puzzle_controller_(nullptr)
    , screen_(nullptr)
    , renderer_(nullptr)
    , success_(false)
    , error_(false)
{
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stderr, "Could not init SDL: %s\n", SDL_GetError());
        error_ = true;
        return;
    }

    screen_ = SDL_CreateWindow("SlidingWindow",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            kScreenWidth, kScreenHeight,
            0);
    
    if (screen_ == nullptr) {
        fprintf(stderr, "Could not create window\n");
        return;
    }

    renderer_ = SDL_CreateRenderer(screen_, -1, SDL_RENDERER_SOFTWARE);
    if (renderer_ == nullptr) {
        fprintf(stderr, "Could not create renderer\n");
        return;
    }

    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
    SDL_RenderPresent(renderer_);
    SDL_RenderPresent(renderer_);
    SDL_Delay(3000);
}

SDLView::SDLView(PuzzleController* c, State* is)
    : puzzle_controller_(c)
    , screen_(nullptr)
    , renderer_(nullptr)
    , success_(false)
    , error_(false)
{

}

SDLView::SDLView(PuzzleController* c)
    : puzzle_controller_(c)
    , screen_(nullptr)
    , renderer_(nullptr)
    , success_(false)
    , error_(false)
{
}

SDLView::~SDLView()
{
    //Free stuffs here.
    SDL_DestroyWindow(screen_);
    SDL_Quit();
}

void SDLView::Run()
{
    
}
