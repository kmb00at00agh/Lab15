#pragma once
#include "Character.h"

namespace GameEngine {

    // Derived Character class - Minion
    class Minion : public Character {
    private:
        int loyalty;

    public:
        Minion(string n, int h, int s, int d, CharacterType t, int l);
        void cheerBoss();
        void describe() const override;
        ~Minion();
        Character* operator+(const Character& other) const override;
    };

}