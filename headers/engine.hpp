#pragma once
#include "renderer.hpp"
#include "shape2D.hpp"
#include "constants.hpp"
#include "text.hpp"
#include "collision.hpp"

namespace GEngine {
    class Engine {
    public:
        Engine(int width, int height, const std::string& title);
        void run();

    private:
        Renderer renderer;
        Shape2D shape;
        Text text;
        Constants constants;
        Collision collision;
    };
}
