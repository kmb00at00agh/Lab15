#pragma once
#include <iostream>
#include <string>

namespace ForrestMode {

    class Character {
    public:
        virtual void attack() = 0;
        virtual ~Character() {}
    };

    class Warrior : public Character {
    public:
        void attack() override {
            std::cout << "You fight in the forrest! You can not swing your sword!" << std::endl;
        }
    };
}

