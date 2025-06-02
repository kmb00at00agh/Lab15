#include "Boss.h"
#include "Minion.h"
#include "BossEnemy.h"
#include "MinionEnemy.h"
#include "BattleArena.h"
#include "Dummy.h"
#include "FieldModifier.h"
#include "DungeonMode.h"
#include "UI.h"
#include "Factory.h"
#include "Simulation.h"
#include<future>


using namespace GameEngine;

int main() {
    Simulation simulation;

    std::vector<Character*> characters = {
        new Boss("BossName", 150, 30, 20, GameEngine::CharacterType::SWORDSMAN, 100),
        new Minion("MinionName", 80, 15, 10, GameEngine::CharacterType::DRUID, 50),
        new Boss("BossName", 150, 30, 20, GameEngine::CharacterType::SWORDSMAN, 100),
        new Minion("MinionName", 80, 15, 10, GameEngine::CharacterType::DRUID, 50)
    };

    /*std::vector<std::future<std::string>> futures;

    for (Character* c : characters) {
        futures.push_back(std::async(std::launch::async, &Simulation::runComputeResult, &simulation, c));
    }

    for (auto& f : futures) {
        std::cout << f.get() << std::endl;
    }


    for (Character* c : characters) {
        delete c;
    }*/
    std::vector<std::future<int>> int_futures;

    // Run generateValue() asynchronously
    for (Character* c : characters) {
        int_futures.push_back(std::async(std::launch::async, &Simulation::runGenerate, &simulation, c));
    }

    // Once results are ready, pass to processValue
    for (size_t i = 0; i < characters.size(); ++i) {
        int value = int_futures[i].get();
        simulation.runProcess(characters[i], value);
    }

    // Clean up
    for (Character* c : characters) {
        delete c;
    }

    return 0;
    
}
