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
#include "CharacterGroup.h"
#include<future>

using namespace GameEngine;

int main() {
        Character* boss1 = new Boss("BossName", 150, 30, 200, GameEngine::CharacterType::SWORDSMAN, 100);
        Character* boss2 = new Boss("BossName", 150, 30, 200, GameEngine::CharacterType::SWORDSMAN, 100);
        Character* minion1 = new Minion("MinionName", 80, 15, 100, GameEngine::CharacterType::DRUID, 50);
        Character* minion2 = new Minion("MinionName", 80, 15, 100, GameEngine::CharacterType::DRUID, 50);
        std::cout << "_________________________________" << endl;
        CharacterGroup* group1 = new CharacterGroup("Group1", 1000, 500, 300, GameEngine::CharacterType::HOARD);
        group1->add(minion1);
        group1->add(boss1);
        std::cout << "_________________________________" << endl;
        CharacterGroup* group2 = new CharacterGroup("Group2", 1200, 600, 400, GameEngine::CharacterType::HOARD);
        group2->add(minion2);
        group2->add(boss2);
        group2->add(group1); // Composite inside composite
        std::cout << "_________________________________" << endl;
        group2->performAction();
        std::cout << "_________________________________" << endl;
        std::cout << "Total Power Level of Group2: " << group2->getPowerLevel() << "\n";

        delete group2; 
        return 0;

}
