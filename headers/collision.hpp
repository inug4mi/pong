// CollisionDetector.hpp
#pragma once
#include <SFML/Graphics.hpp>

namespace GEngine {
    class Collision {
    public:
        bool betweenRectangleShape(const sf::RectangleShape& shape1, const sf::RectangleShape& shape2);
    };
}
