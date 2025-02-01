#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace GEngine {
    class Renderer {
    public:
        Renderer(int width, int height, const std::string &title);
        
        void wclear(const sf::Color &color);                       
        
        void wclose();
        
        void wdisplay();                                 
        
        bool wisOpen() const;                
        
        void wsetFramerateLimit(unsigned int limit); 
        
        template <typename T>
        void wdraw(const T &object) {
            window.draw(object);
        }

        void wpollEvents();   

        // hacer privado variable window
        sf::RenderWindow window;  
        sf::Event event;         
    };
}
