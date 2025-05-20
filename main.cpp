#include "Boss.h"
#include "Minion.h"
#include "BossEnemy.h"
#include "MinionEnemy.h"
#include "BattleArena.h"
#include "Dummy.h"
#include "FieldModifier.h"
#include "DungeonMode.h"
#include "UI.h"

using namespace GameEngine;

int main() {
    Boss* boss = new Boss("MadDog", 150, 25, 10, SWORDSMAN, 8);
    UI* uiObserver = new UI();

    boss->addObserver(uiObserver);  // Hook UI to observe the boss
    boss->getHit(30);               // UI should get notified
    boss->heal(20);                 // UI gets notified again

    delete boss;
    delete uiObserver;

    return 0;
}