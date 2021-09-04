/**
 * sfml_view.h
 *
 * Graphical view with SFML
 */

#ifndef SLIDING_PUZZLE_VIEWS_SFML_VIEW_H_
#define SLIDING_PUZZLE_VIEWS_SFML_VIEW_H_

#include <string>

#include <SFML/Graphics.hpp>

#include "../Controller/puzzle_controller.h"
#include "../Model/state.h"
#include "iview.h"

class SFMLView : public IView
{
public:
    SFMLView();
    SFMLView(PuzzleController*);
    SFMLView(PuzzleController*, State*);
    ~SFMLView();

    void Run();


private:
    void drawBanner();
    void drawMainMenu();
    void drawState();

    PuzzleController* puzzle_controller_;
    sf::RenderWindow window_;
};

#endif  // SLIDING_PUZZLE_VIEWS_SFML_VIEW_H_
