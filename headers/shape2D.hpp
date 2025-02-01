#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "constants.hpp"

namespace GEngine{
    class Shape2D{
    public:
        sf::RectangleShape square(double xi, double yi, double size, sf::Color color);
        sf::RectangleShape rectangle(double xi, double yi, sf::Vector2f size, sf::Color color);
        sf::VertexArray line(double xi, double yi, double xf, double yf, sf::Color color);
        sf::CircleShape circle(double xi, double yi, double radius, sf::Color color);
        sf::VertexArray triangle(double xi1, double yi1, double xi2, double yi2, double xi3, double yi3, sf::Color color);
        std::vector<sf::VertexArray> grid();
        //bool collisionBetween(sf::RectangleShape rectangleShape1, sf::RectangleShape rectangleShape2);
    };
}