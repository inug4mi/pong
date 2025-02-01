#pragma once

#include <SFML/Graphics.hpp>

namespace GEngine{
    class Constants{
    public:
        static constexpr int SCREEN_WIDTH = 500;
        static constexpr int SCREEN_HEIGHT = 500;
    
        const sf::Color BG_COLOR = sf::Color(15,15,15); 
        const sf::Color GRID_COLOR = sf::Color(30,30,30);
        const sf::Color TEXT_COLOR = sf::Color(20,20,20);
        const sf::Color RED = sf::Color(255,20,20);
};
}