#pragma once

#include <iostream>
#include "Character.h"
#include "Enemy.h"

using namespace std;

namespace GameEngine {

    // Function template to get the higher stat of a specific field
    template <typename T>
    T getHigherStat(T a, T b) {
        return (a > b) ? a : b;
    }

    template <typename T>
    class FieldModifier {
    public:
        void increaseHealth(T* obj, int amount);
        void printStats(T* obj);
    };

    // Specialization for Character
    template <>
    class FieldModifier<Character> {
    public:
        void increaseHealth(Character* obj, int amount);
        void printStats(Character* obj);
    };

    // Specialization for Enemy
    template <>
    class FieldModifier<Enemy> {
    public:
        void increaseHealth(Enemy* obj, int amount);
        void printStats(Enemy* obj);
    };

    // Function to describe a Character
    void describeCharacter(const Character* c);

}
