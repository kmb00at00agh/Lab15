#pragma once
#include "Character.h"
#include <thread> // Add this include for std::this_thread
#include <chrono> // Add this inc


namespace GameEngine {

    // Derived Character class - Minion
    class Minion : public Character {
    private:
        int loyalty;

    public:
        Minion(string n, int h, int s, int d, CharacterType t, int l);
        void cheerBoss();
        void describe() const override;
        ~Minion();
        Character* operator+(const Character& other) const override;
        void logStatus() override {
            std::cout << "[Minion] HP: " << health << ", Strength: " << strength << ", Defense: " << defense << std::endl;
        }
        void performTask() override
        {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            std::cout << "\033[35mMinion task coplete.\033[0m" << std::endl;
        }
        std::string computeResult() override {
            std::this_thread::sleep_for(std::chrono::seconds(1)); // shorter delay
            return "Minion result: quick report!";
        }
        int generateValue() override {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return 20;
        }

        void processValue(int val) override {
            std::cout << "Minion processed value: " << val + 10 << std::endl;
        }
        void performAction() const override {
            std::cout << "Minion strikes weakly.\n";
        }

        int getPowerLevel() const override {
            return 220;
        }
    };

}