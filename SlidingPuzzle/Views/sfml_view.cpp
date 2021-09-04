/**
 * sfml_view.cpp
 *
 * Implementation of graphical view with SFML
 */

#include <cstdio>

#include "sfml_view.h"

const std::string kTitle             ("SlidingPuzzle");
const std::string kFontPath          ("./Fonts/PressStart2P-Regular.ttf");
const std::string kBannerStr         ("###################\n# 8-puzzle solver #\n###################");

constexpr int kWindowHeight          = 360;
constexpr int kWindowWidth           = 720;
constexpr int kTextSize              = 32;
constexpr int kNumBoxes              = 3;

constexpr float kBoxSize             = 100.0f;
constexpr float kOutlineThickness    = 10.0f;
constexpr float kStartingOffset      = 10.0f;

const sf::Color kOutlineColor         (255, 0, 0);
const sf::Color kBoxColor             (0, 0, 255);
const sf::Color kTextColor            (255, 255, 255);
 
sf::Font font_;

SFMLView::SFMLView()
    : window_(sf::VideoMode(kWindowWidth, kWindowHeight), kTitle)
{
    if (!font_.loadFromFile(kFontPath)) {
        fprintf(stderr, "%s\n", "Error font.loadFromFile()");
    }
}

SFMLView::~SFMLView()
{

}

void SFMLView::drawBanner()
{
    sf::Text banner;
    banner.setFont(font_);
    banner.setString(kBannerStr);
    banner.setCharacterSize(kTextSize >> 0x1);
    banner.setFillColor(kTextColor);
    banner.setStyle(sf::Text::Bold);
    banner.setPosition(kWindowWidth / 2.0f + kStartingOffset, 0);
    window_.draw(banner);
}

void SFMLView::drawMainMenu()
{

}

void SFMLView::drawState()
{
    float next_coord = kStartingOffset;
    for (int i = 0; i < kNumBoxes; i++) {
        for (int j = 0; j < kNumBoxes; j++) {
            // Draw rectangle and its border.
            sf::RectangleShape rectangle(sf::Vector2f(kBoxSize, kBoxSize));
 
            rectangle.setPosition(
                    next_coord + i * (kOutlineThickness * 2 + kBoxSize), 
                    next_coord + j * (kOutlineThickness * 2 + kBoxSize)
            );
 
            rectangle.setOutlineThickness(kOutlineThickness);
            rectangle.setOutlineColor(kOutlineColor);
            rectangle.setFillColor(kBoxColor);
             
            window_.draw(rectangle);
            
            // Draw digits.
            sf::Text digit_txt;
            digit_txt.setFont(font_);
            digit_txt.setString("1");
            digit_txt.setCharacterSize(kTextSize);
            digit_txt.setFillColor(kTextColor);
            digit_txt.setStyle(sf::Text::Bold);

            float left_coord = next_coord + i * (kOutlineThickness * 2 + kBoxSize) + kBoxSize / 3.0f;
            float right_coord = next_coord + j * (kOutlineThickness * 2 + kBoxSize) + kBoxSize / 3.0f;

            digit_txt.setPosition(left_coord, right_coord);

            window_.draw(digit_txt);
        }
    }
}

void SFMLView::Run()
{
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        // Clear the window with black color.
        window_.clear(sf::Color::Black);

        drawBanner();
        drawMainMenu();
        drawState();

        window_.display();
    }
}
