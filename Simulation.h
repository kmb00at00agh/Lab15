#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "Character.h"
#include "Boss.h"
#include "MinionEnemy.h"


class Simulation {
public:
    void simulateBoss() {
        GameEngine::Character* boss = new GameEngine::Boss("SimBoss", 100, 20, 10, GameEngine::CharacterType::SWORDSMAN, 50);

        {
            mtx.lock();
            std::cout << "[Boss Thread] ";
            boss->describe();
            mtx.unlock();
        }
        delete boss;
    }

    void simulateMinionEnemy() {
        GameEngine::Enemy* minionEnemy = new GameEngine::MinionEnemy("SimMinionEnemy", 80, 15, 5, GameEngine::EnemyType::WITCH, false);

        {
            mtx.lock();
            std::cout << "[Enemy Thread] ";
            minionEnemy->describe();
            mtx.unlock();
        }
        delete minionEnemy;
    }

    std::mutex mtx;

    void runCharacterWithStatus(GameEngine::Character* obj) {
        {   
            mtx.lock();
            obj->logStatus();
            mtx.unlock();
        }
        delete obj;
    }

    void runEnemyWithStatus(GameEngine::Enemy* obj) {
        {   
            mtx.lock();
            obj->logStatus();
            mtx.unlock();
        }
        delete obj;
    }

    void processCharacters(const std::vector<GameEngine::Character*>& characters) {
        for (auto* c : characters) {
            mtx.lock();
            c->logStatus();
            mtx.unlock();
        }
    }

    void processEnemies(const std::vector<GameEngine::Enemy*>& enemies) {
        for (auto* e : enemies) {
            mtx.lock();
            e->logStatus();
            mtx.unlock();
        }
    }

    

    static void useSharedResource(const std::string& name) {
        std::cout << name << " is waiting to access the shared resource...\n";
        std::mutex resourceMutex;

        {
            std::lock_guard<std::mutex> lock(resourceMutex);
            std::cout << name << " is using the resource...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));  // simulate work
            std::cout << name << " is done.\n";
        }
    }

    void runPerformTask(GameEngine::Character* character)
    {
        character->performTask();
    }

    std::string runComputeResult(GameEngine::Character* character) {
        return character->computeResult();
    }
};

