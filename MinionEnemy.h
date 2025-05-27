#pragma once
#include "Enemy.h"
#include "Character.h" 
namespace GameEngine {

    class MinionEnemy : public Enemy {
    private:
        int sneakiness;

    public:
        MinionEnemy(string n, int h, int d, int def, EnemyType t, int s);
        void sneakAttack(Character& target);
        void describe() const override;
        ~MinionEnemy();
        void logStatus() override {
            std::cout << "[Minion Enemy] HP: " << health << ", Damage: " << damage << ", Defense: " << defense << std::endl;
        }
    };
}



