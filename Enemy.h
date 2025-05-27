#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace GameEngine {

    enum EnemyType { WITCH, DEMON, BEAST };

    class Character;  // Forward declaration

    class Enemy {
    protected:
        string name;
        int health;
        int damage;
        int defense;
        EnemyType type;

    public:
        Enemy(string n, int h, int d, int def, EnemyType t);
        Enemy();
        ~Enemy();

        string getName() const;
        /*string getName();*/
        void attack(Character& character);
        void getHit(int damage);
        void spawn();
        void die();
        virtual void describe() const;
        int getHealth() const;
        int getDamage() const;
        int getDefense() const;
        void increaseHealth(int amount);
        virtual void logStatus() = 0;
    };

}