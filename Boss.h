#pragma once
#include "Character.h"

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


    };

}