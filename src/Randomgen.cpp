#include "Randomgen.hpp"

            int Randomgen::getRandomInt(int min, int max) {
            static std::random_device rd;        // echte Entropie (sofern verfügbar)
            static std::mt19937 gen(rd());       // Mersenne Twister PRNG
            std::uniform_int_distribution<int> dist(min, max);

            return dist(gen);
        }