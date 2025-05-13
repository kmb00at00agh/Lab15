#pragma once
#include <iostream>
#include <string>

namespace DungeonMode {

    class Character {
    public:
        virtual void attack() = 0;
        virtual ~Character() {}
    };

    class Warrior : public Character {
    public:
        void attack() override;
    };
}
