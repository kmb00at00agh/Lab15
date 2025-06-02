#pragma once

#include <iostream>
#include <string>
#include "Subject.h"
#include <vector>

using namespace std;

namespace GameEngine {

    enum CharacterType { SWORDSMAN, DRUID, SHAMAN };
    class Enemy;  // Forward declaration
    class Character : public Subject {
    protected:
        std::vector<Observer*> observers;
        string name;
        int health;
        int strength;
        int defense;
        CharacterType type;
    public:
        Character(string n, int h, int s, int d, CharacterType t);
        Character();
        virtual ~Character();
        string getName() const;
        virtual void describe() const = 0;
        void attack(Enemy& enemy);
        void getHit(int damage);
        void heal(int amount);
        void spawn();
        void die();
        int getHealth() const { return health; }
        int getStrength() const { return strength; }
        int getDefense() const { return defense; }
        virtual Character* operator+(const Character& other) const = 0;
        static int objectCount;  // Tracks total number of objects created
        static int getObjectCount();  // Returns object count
        virtual void logStatus() = 0;
        virtual void performTask() = 0;
        virtual std::string computeResult() = 0;
        virtual int generateValue() = 0;
        virtual void processValue(int val) = 0;
        void addObserver(Observer* observer) override {
            observers.push_back(observer);
        }

        void removeObserver(Observer* observer) override {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notifyObservers() override {
            for (Observer* observer : observers) {
                observer->update();
            }
        }
    };
}
