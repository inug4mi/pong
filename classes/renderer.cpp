#include "renderer.hpp"
#include "constants.hpp"
namespace GEngine {
    Renderer::Renderer(int width, int height, const std::string &title) {
        window.create(sf::VideoMode(width, height), title, sf::Style::Close);
        window.setFramerateLimit(60); // Default frame limit
    }

    void Renderer::wclear(const sf::Color &color) {
        window.clear(color); // Clear the window
    }

    void Renderer::wclose(){
        window.close();
    }

    void Renderer::wdisplay() {
        window.display(); // Display the rendered frame
    }

    bool Renderer::wisOpen() const {
        return window.isOpen(); // Return window status
    }

    void Renderer::wsetFramerateLimit(unsigned int limit) {
        window.setFramerateLimit(limit); // Set the framerate limit
    }

    void Renderer::wpollEvents() {
    
        //while (window.pollEvent(event))
        //{
        //    if (event.type == sf::Event::Closed)
        //        window.close();
        //    
        //    if (event.type == sf::Event::KeyPressed)
        //    {
        //        if (event.key.code == sf::Keyboard::Escape){
        //            //pass
        //        }
        //
        //        switch (event.key.code)
        //        {
        //            case sf::Keyboard::W:
        //                break;
        //            
        //            case sf::Keyboard::S:
        //                break;
        //            
        //            case sf::Keyboard::A:
        //                break;
        //
        //            case sf::Keyboard::D:
        //                break;
        //
        //            default:
        //                break;
        //        }
        //    }
        //}
    }

}
