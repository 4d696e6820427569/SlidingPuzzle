/**
 * sdl_view.h
 *
 * Graphical view with SDL2.
 */

#ifndef SLIDING_PUZZLE_VIEWS_SDL_VIEW_H_
#define SLIDING_PUZZLE_VIEWS_SDL_VIEW_H_

#include <cstdio>

#include <SDL.h>

#include "../Controller/puzzle_controller.h"
#include "../Model/state.h"
#include "iview.h"

class SDLView : public IView
{
public:
    SDLView();
    SDLView(PuzzleController*);
    SDLView(PuzzleController*, State*);
    ~SDLView();

    void Run();

private:
    PuzzleController* puzzle_controller_;
    SDL_Window* screen_;
    SDL_Renderer* renderer_;
    static constexpr int kScreenWidth = 640;
    static constexpr int kScreenHeight = 480;
    bool success_;
    bool error_;
};

#endif // SLIDING_PUZZLE_VIEWS_SDL_VIEW_H
