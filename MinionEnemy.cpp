#include "pch.h"
#include "MinionEnemy.h"
#include <iostream>
namespace GameEngine {

    MinionEnemy::MinionEnemy(string n, int h, int d, int def, EnemyType t, int s) {
        name = n;
        health = h;
        damage = d;
        defense = def;
        type = t;
        sneakiness = s;

    }
    void MinionEnemy::sneakAttack(Character& target) {
        int bonus = sneakiness;
        cout << name << " does a sneak attack!\n";
        target.getHit(damage + bonus);
    }

    void MinionEnemy::describe() const {
        cout << "MinionEnemy " << name << " - sneaky and sly.\n";
    }

    MinionEnemy::~MinionEnemy() {
        cout << "MinionEnemy " << name << " destroyed. (destrcutor of child Minion Enemy)\n";
    }
}