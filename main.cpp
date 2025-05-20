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

    boss->addObserver(uiObserver);  
    boss->getHit(30);               
    boss->heal(20);     
    
    delete boss;
    delete uiObserver;

    return 0;
}