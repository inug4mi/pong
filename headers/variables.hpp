#pragma once
#include <random>
namespace GEngine{
    class Variables {
    public:
        Variables();  // Constructor to initialize default values
        std::random_device rd;
        std::mt19937 gen;

        int generateRandomInt(int from, int to);
    };
}
