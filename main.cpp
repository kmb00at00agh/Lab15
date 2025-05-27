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

    std::vector<std::future<std::string>> futures;

    for (Character* c : characters) {
        futures.push_back(std::async(std::launch::async, &Simulation::runComputeResult, &simulation, c));
    }

    for (auto& f : futures) {
        std::cout << f.get() << std::endl;
    }

    for (Character* c : characters) {
        delete c;
    }

    return 0;
    //Character* boss = new Boss("BossName", 150, 30, 20, GameEngine::CharacterType::SWORDSMAN, 100);
    //Character* minion = new Minion("MinionName", 80, 15, 10, GameEngine::CharacterType::DRUID, 50);

    //Simulation* simulation = new Simulation();

    //std::future<void> f1 = std::async(std::launch::async, &Simulation::runPerformTask, simulation, minion);
    //std::future<void> f2 = std::async(std::launch::async, &Simulation::runPerformTask, simulation, boss);

    return 0;
    
}
