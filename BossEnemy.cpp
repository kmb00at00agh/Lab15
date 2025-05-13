#include "BossEnemy.h"
#include <iostream>

namespace GameEngine {
    BossEnemy::BossEnemy(string n, int h, int d, int def, EnemyType t, bool e) {
        name = n;
        health = h;
        damage = d;
        defense = def;
        type = t;
        enraged = e;
    }

    void BossEnemy::empower() {
        if (enraged) {
            damage += 5;
            cout << name << " is enraged! Damage increased to " << damage << "!\n";
        }
    }

    void BossEnemy::describe() const {
        cout << "BossEnemy " << name << " - terrifying and enraged!\n";
    }

    BossEnemy::~BossEnemy() {
        cout << "BossEnemy " << name << " destroyed. (destrcutor of Boss Enemy child class)\n";
    }
}