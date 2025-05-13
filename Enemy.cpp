#include "Enemy.h"
#include "Character.h"
#include <iostream>

namespace GameEngine {

    Enemy::Enemy(string n, int h, int d, int def, EnemyType t) {
        name = n;
        health = h;
        damage = d;
        defense = def;
        type = t;
        cout << "Enemy " << name << " created!\n";
    }

    Enemy::Enemy() {
        name = "Unknown";
        health = 50;
        damage = 8;
        defense = 3;
        type = BEAST;
    }

    Enemy::~Enemy() { cout << "Enemy " << name << " destroyed. (stock Enemy destructor) \n"; }

    string Enemy::getName() const {
        return name;
    }

    void Enemy::attack(Character& character) {
        cout << name << " attacks " << character.getName() << "!\n";
        character.getHit(damage);
    }

    void Enemy::getHit(int damage) {
        int actualDamage = max(0, damage - defense);
        health -= actualDamage;
        cout << name << " takes " << actualDamage << " damage! Health: " << health << "\n";
        if (health <= 0) die();
    }

    void Enemy::spawn() {
        cout << "Angry " << name << " appears!\n";
    }

    void Enemy::die() {
        cout << name << " has been defeated!\n";
    }

    void Enemy::describe() const {
        cout << "This is a generic enemy.\n";
    }


    int Enemy::getHealth() const { return health; }

    void Enemy::increaseHealth(int amount) {
        health += amount;
    }

    int Enemy::getDefense() const { return defense; }

    int Enemy::getDamage() const { return damage; }


}