
#include "engine.hpp"
#include <iostream>

namespace GEngine {
    Engine::Engine(int width, int height, const std::string& title)
        : renderer(width, height, title) {}

    void Engine::run() {
        // iniciar aleatoriedad
        std::srand(std::time(nullptr));

        // barra izquierda
        int leftX = 30;
        int leftY = 600/2;
        sf::RectangleShape leftBar = shape.rectangle(leftX,leftY,sf::Vector2f(30,150), sf::Color::Red);

        // barra derecha
        int rightX = 800-60;
        int rightY = 600/2;
        sf::RectangleShape rightBar = shape.rectangle(800-60,600/2,sf::Vector2f(30,150), sf::Color::Green);

        // velocidad movimiento barras
        float barSpeed = 30;

        // bola
        int ballX = 800/2;
        int ballY = 600/2;
        sf::RectangleShape ball = shape.square(ballX, ballY, 30, sf::Color::White);
        // velocidad bola 
        float ballSpeedX = (std::rand() % 2 == 0) ? 5.0f : -5.0f;  // Aleatorio entre izquierda y derecha
        float ballSpeedY = (std::rand() % 2 == 0) ? 5.0f : -5.0f; 

        // textos puntaje
        int good = text.good();
        int leftScoreText = 0;
        int rightScoreText = 0;
        sf::Text rightScore;
        sf::Text leftScore;
        leftScore = text.write(std::to_string(leftScoreText), 50, sf::Vector2f(80, 600/2 - 50), sf::Color::White);
        rightScore = text.write(std::to_string(rightScoreText), 50, sf::Vector2f(800-30-80, 600/2 - 50), sf::Color::White);

        // framerate
        renderer.wsetFramerateLimit(45);

        while (renderer.wisOpen()) {
            renderer.wpollEvents();
            renderer.wclear(constants.BG_COLOR);

            // render your game logic and stuff
            renderer.wdraw(leftBar);
            renderer.wdraw(rightBar);
            renderer.wdraw(ball);
            renderer.wdraw(leftScore);
            renderer.wdraw(rightScore);

            // mover bola
            ballX += ballSpeedX;
            ballY += ballSpeedY;
            ball.setPosition(ballX,ballY);

            // Colisión con bordes superior e inferior
            if (ballY <= 0 || ballY + 30 >= 600) {
                ballSpeedY = -ballSpeedY;  // Invertir dirección en Y
            }

            // colision laterales de la pantalla (aumento de puntaje)
            if (ballX < 0 - 30){
                rightScoreText++;
                rightScore = text.write(std::to_string(rightScoreText), 50, sf::Vector2f(800 - 30 - 80, 600/2 - 50), sf::Color::White);
                ballX = 800/2;
                ballY = 600/2;
                ball.setPosition(ballX,ballY);
                ballSpeedX = (std::rand() % 2 == 0) ? 5.0f : -5.0f;  // Aleatorio entre izquierda y derecha
                ballSpeedY = (std::rand() % 2 == 0) ? 5.0f : -5.0f;   
            }
            if (ballX >= 800){
                leftScoreText++;
                leftScore = text.write(std::to_string(leftScoreText), 50, sf::Vector2f(80, 600/2 - 50), sf::Color::White);
                ballX = 800/2;
                ballY = 600/2;
                ball.setPosition(ballX,ballY);
                ballSpeedX = (std::rand() % 2 == 0) ? 5.0f : -5.0f;  // Aleatorio entre izquierda y derecha
                ballSpeedY = (std::rand() % 2 == 0) ? 5.0f : -5.0f;   
            }

            // Colisión con las barras
            if (collision.betweenRectangleShape(ball, leftBar) || collision.betweenRectangleShape(ball, rightBar)) {
                ballSpeedX = -ballSpeedX;  // Invertir dirección en X
            }

            // mover barras con input del usuario
            while (renderer.window.pollEvent(renderer.event))
            {
                if (renderer.event.type == sf::Event::Closed)
                    renderer.window.close();
                
                if (renderer.event.type == sf::Event::KeyPressed)
                {
                    if (renderer.event.key.code == sf::Keyboard::Escape){
                        //pass
                    }
            
                    switch (renderer.event.key.code)
                    {
                        case sf::Keyboard::W:
                            leftY -= barSpeed;
                            leftBar.setPosition(leftX, leftY);
                            break;
                        
                        case sf::Keyboard::S:
                            leftY += barSpeed;
                            leftBar.setPosition(leftX, leftY);
                            break;
                        
                        case sf::Keyboard::Up:
                            rightY -= barSpeed;
                            rightBar.setPosition(rightX, rightY);
                            break;
            
                        case sf::Keyboard::Down:
                            rightY += barSpeed;
                            rightBar.setPosition(rightX, rightY);
                            break;
            
                        default:
                            break;
                    }
                }
            }

            // ######

            renderer.wdisplay();
        }
    }
}
