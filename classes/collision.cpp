#include "collision.hpp"

namespace GEngine {
    bool Collision::betweenRectangleShape(const sf::RectangleShape& shape1, const sf::RectangleShape& shape2) {
        return shape1.getGlobalBounds().intersects(shape2.getGlobalBounds());
    }
}
