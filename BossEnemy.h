#pragma once
#include "Enemy.h"

namespace GameEngine {

    class BossEnemy : public Enemy {
    private:
        bool enraged;

    public:
        BossEnemy(string n, int h, int d, int def, EnemyType t, bool e);
        void empower();
        ~BossEnemy();
        void describe() const override;
        void logStatus() override {
            std::cout << "[Enemy] HP: " << health << ", Damage: " << damage << ", Defense: " << defense << std::endl;
        }
    };

}