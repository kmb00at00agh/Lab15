#include "pch.h"
#include "Minion.h"
#include <iostream>

namespace GameEngine {

    Minion::Minion(string n, int h, int s, int d, CharacterType t, int l)
        : Character(n, h, s, d, t), loyalty(l) {
    }


    void Minion::cheerBoss() {
        cout << name << " cheers the boss with loyalty level " << loyalty << "!\n";
    }

    void Minion::describe() const {
        cout << name << " is a loyal minion with loyalty level " << loyalty << "\n";
    }

    Minion::~Minion() {
        cout << "Minion " << name << " destroyed. (destructor of the minion child class)\n";
    }

    Character* Minion::operator+(const Character& other) const {
        const Minion* otherMinion = dynamic_cast<const Minion*>(&other);
        if (otherMinion) {
            Minion* combined = new Minion(
                "Combined_" + this->name + "_" + otherMinion->name,
                this->health + otherMinion->health,
                this->strength + otherMinion->strength,
                this->defense + otherMinion->defense,
                this->type,
                this->loyalty + otherMinion->loyalty
            );
            return combined;
        }
        else {
            cout << "Cannot combine Minion with non-Minion character.\n";
            return nullptr;
        }
    }
}