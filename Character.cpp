#include "Character.h"
#include "Enemy.h"
#include <iostream>

namespace GameEngine {

    Character::Character(string n, int h, int s, int d, CharacterType t) {
        name = n;
        health = h;
        strength = s;
        defense = d;
        type = t;
        cout << "Character " << name << " created!\n";
    }

    Character::Character() {
        name = "Unknown";
        health = 100;
        strength = 10;
        defense = 5;
        type = SWORDSMAN;
    }

    Character::~Character() { cout << "Character " << name << " destroyed. (stock character destructor)\n"; }

    string Character::getName() const {
        return name;
    }

    //void Character::describe() const {
    //    cout << "This is a generic character.\n";
    //}

    void Character::attack(Enemy& enemy) {
        cout << name << " attacks " << enemy.getName() << "!\n";
        enemy.getHit(strength);
    }

    void Character::getHit(int damage) {
        int actualDamage = max(0, damage - defense);
        health -= actualDamage;
        cout << name << " takes " << actualDamage << " damage! Health: " << health << "\n";
        if (health <= 0) die();
    }

    void Character::heal(int amount) {
        health += amount;
        cout << name << " heals for " << amount << " HP! Health is now " << health << "\n";
    }

    void Character::spawn() {
        cout << "Mighty " << name << " appears!\n";
    }

    void Character::die() {
        cout << name << " has died!\n";
    }

    // Define the static member
    int Character::objectCount = 0;

    // Static function definition
    int Character::getObjectCount() {
        return objectCount;
    }

}