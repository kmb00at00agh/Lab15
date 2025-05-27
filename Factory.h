#pragma once  
#include "Character.h"  
#include "Enemy.h"
#include "Boss.h"
#include "BossEnemy.h"
#include <string>
namespace GameEngine {
    class CharacterFactory {
    public:
        virtual Character* createCharacter() = 0;   
        virtual ~CharacterFactory() {}
    };
    class EnemyFactory {
    public:
        virtual Enemy* createEnemy() = 0;
        virtual ~EnemyFactory() {}
    };
    class BossFactory : public CharacterFactory {
    public:
        Character* createCharacter() override {
            return new Boss("DefaultBoss", 100, 20, 10, CharacterType::SWORDSMAN, 50); 
        }
    };
    class MinionFactory : public CharacterFactory {
    public:
        Character* createCharacter() override {
            return new Minion("DefaultMinion", 100, 20, 10, CharacterType::SWORDSMAN, 50);
        }
    };
    class EnemyBossFactory : public EnemyFactory
    {
    public:
        Enemy* createEnemy() override
        {
            return new BossEnemy("DefaultEnemyBoss", 100, 20, 10, EnemyType::WITCH, false);
        }
    };
    class EnemyMinionFactory : public EnemyFactory
    {
    public:
        Enemy* createEnemy() override
        {
            return new MinionEnemy("DefaultEnemyMinion", 100, 20, 10, EnemyType::WITCH, false);
        }
    };
    
    /*template <typename T>
    class AutoCharacterFactory : public CharacterFactory {
    private:
        std::string name;
        int health;
        int strength;
        int defense;
        CharacterType type;
        int extra; 
    public:
        AutoCharacterFactory(const std::string& n, int h, int s, int d, CharacterType t, int e)
            : name(n), health(h), strength(s), defense(d), type(t), extra(e) {}

        Character* createCharacter() override {
            return new T(name, health, strength, defense, type, extra);
        }
    };*/

    template <typename T>
    class AutoEnemyFactory : public EnemyFactory {
    public:
        Enemy* createEnemy() override {
            return new T("AutoEnemy", 80, 15, 5, EnemyType::WITCH, true); 
        }
    };
}