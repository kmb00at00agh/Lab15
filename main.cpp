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


using namespace GameEngine;

int main() {
    Simulation* sim = new Simulation();

    std::thread t1(&Simulation::simulateBoss, sim);
    std::thread t2(&Simulation::simulateMinionEnemy, sim);

    t1.join();
    t2.join();

    std::cout << "Simulation complete.\n";

    std::cout << "__________________________Task2__________________________\n";


    Character* boss = new Boss("ThreadBoss", 120, 30, 15, CharacterType::SWORDSMAN, 60);
    Enemy* minionEnemy = new MinionEnemy("ThreadMinion", 90, 20, 8, EnemyType::WITCH, false);

    t1 = std::thread(&Simulation::runCharacterWithStatus, sim, boss);
    t2 = std::thread(&Simulation::runEnemyWithStatus, sim, minionEnemy);

    t1.join();
    t2.join();

    std::cout << "Concurrent status logging complete.\n";

    std::cout << "__________________________Task3__________________________\n";

    Character* c1 = new Boss("Boss1", 100, 20, 10, CharacterType::SWORDSMAN, 40);
    Character* c2 = new Minion("Minion1", 80, 15, 8, CharacterType::SHAMAN, 25);
    Character* c3 = new Boss("Boss2", 110, 22, 12, CharacterType::SHAMAN, 45);
    Character* c4 = new Minion("Minion2", 85, 17, 9, CharacterType::SHAMAN, 30);

    std::vector<Character*> group1 = { c1, c2 };
    std::vector<Character*> group2 = { c3, c4 };

    t1=std::thread(&Simulation::processCharacters, sim, group1);
    t2=std::thread(&Simulation::processCharacters, sim, group2);

    t1.join();
    t2.join();
    std::cout << "__________________________Task4__________________________\n";


    t1=std::thread(Simulation::useSharedResource, "Boss");
    t2=std::thread(Simulation::useSharedResource, "Minion");

    t1.join();
    t2.join();

    return 0;
    
}
