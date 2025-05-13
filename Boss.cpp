#include "Boss.h"
#include <iostream>

namespace GameEngine {

    Boss::Boss(string n, int h, int s, int d, CharacterType t, int rage) {
        name = n;
        health = h;
        strength = s;
        defense = d;
        type = t;
        rageLevel = rage;

        ++Character::objectCount;
        cout << "Boss " << name << " enters the battlefield!\n";
    }


    void Boss::unleashRage() {
        strength += rageLevel;
        cout << name << " unleashes rage! Strength is now " << strength << "!\n";
    }

    void Boss::describe() const {
        cout << name << " is a powerful boss with rage level " << rageLevel << "\n";
    }

    Boss::~Boss() {
        cout << "Boss " << name << " destroyed. (Boss individual destructor)\n";
    }

    Character* Boss::operator+(const Character& other) const {
        const Boss* otherBoss = dynamic_cast<const Boss*>(&other);
        if (otherBoss) {
            Boss* combined = new Boss(
                "Combined " + this->name + " " + otherBoss->name,
                this->health + otherBoss->health,
                this->strength + otherBoss->strength,
                this->defense + otherBoss->defense,
                this->type,
                this->rageLevel + otherBoss->rageLevel
            );
            return combined;
        }
        else {
            cout << "Cannot combine Boss with non-Boss character.\n";
            return nullptr;
        }
    }

    bool Boss::operator==(const Boss& other) const {
        return this->rageLevel == other.rageLevel;
    }

    bool Boss::operator&&(const Boss& other) const {
        return (this->health > 100 && this->rageLevel > 5) &&
            (other.health > 100 && other.rageLevel > 5);
    }

    int Boss::getDefaultRageLevel() {
        return 10;  // default rage
    }

    void Boss::shoutBattleCry(const string& cry) const {
        /*cry = "Modified Cry"; */
        cout << name << " roars: " << cry << "!\n";
    }

    int Boss::getRageLevel() const{
        //++rageLevel;
        return rageLevel;
    }

}

