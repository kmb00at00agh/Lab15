#include "BattleArena.h"
#include <iostream>

namespace GameEngine {
    BattleArena::BattleArena(Character& c, Enemy& e) : hero(c), villain(e) {}


    void BattleArena::battle() {

        cout << "***BATTLE STARTS!*** \n";
        hero.attack(villain);
        villain.attack(hero);

    }
}