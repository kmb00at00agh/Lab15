#pragma once
#include "Character.h"
#include <thread> // Add this include for std::this_thread
#include <chrono> // Add this inc

namespace GameEngine {

    class Boss : public Character {
    private:
        int rageLevel;
        bool isDizzy;

    public:
        Boss(string n, int h, int s, int d, CharacterType t, int rage);
        void unleashRage();
        void describe() const override;
        ~Boss();
        Character* operator+(const Character& other) const override;
        // Operator ==
        // Operator overloads
        bool operator==(const Boss& other) const;
        bool operator&&(const Boss& other) const;
        static int getDefaultRageLevel();
        void shoutBattleCry(const string& cry) const; // takes const argument
        int getRageLevel() const;
        void setDizzy(bool dizzy);
        bool getDizzy() const;
        void powerStrike();
        void equipRareItem();
        void validateHealth();
        void logStatus() override {
            std::cout << "[Boss] HP: " << health << ", Strength: " << strength << ", Defense: " << defense << std::endl;
        }
        void performTask() override
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Boss task complete." << std::endl;
        }

       /* std::string computeResult() override 
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return "Result from Boss";
        }*/
        std::string computeResult() override {
            std::this_thread::sleep_for(std::chrono::seconds(10)); // longer delay
            return "Boss result: massive power surge!";
        }
        int generateValue() override {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return 50;
        }

        void processValue(int val) override {
            std::cout << "Boss processed value: " << val * 2 << std::endl;
        }

        void performAction() const override {
            std::cout << "Boss performs a powerful attack!\n";
        }

        int getPowerLevel() const override {
            return 100;
        }

    };

}