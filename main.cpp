#include "Boss.h"
#include "Minion.h"
#include "BossEnemy.h"
#include "MinionEnemy.h"
#include "BattleArena.h"
#include "Dummy.h"
#include "FieldModifier.h"
#include "ForrestMode.h"
#include "DungeonMode.h"

using namespace GameEngine;

int main() {
    DummySpace::Dummy* dummy = new DummySpace::Dummy();
    dummy->sayProvocation(); 
    delete dummy;

    ForrestMode::Character* warriorForrest = new ForrestMode::Warrior();
    warriorForrest->attack(); 
    delete warriorForrest;

    DungeonMode::Character* warriorDungeon = new DungeonMode::Warrior();
    warriorDungeon->attack(); 
    delete warriorDungeon;


    cout << "Default Boss Rage Level: " << Boss::getDefaultRageLevel() << endl;

    Boss b1("King", 150, 30, 20, SHAMAN, 12);
    Boss b2("Prince", 160, 28, 18, SWORDSMAN, 8);

    string inf = "You are a coward!";

    b1.shoutBattleCry(inf);

    cout << "King's rage level: " << b1.getRageLevel() << endl;
    cout << "Prince's rage level: " << b2.getRageLevel() << endl;

    cout << "Total Characters Created: " << Character::getObjectCount() << endl;
    cout << "Total Bosses Created: " << Boss::getObjectCount() << endl;

    
    

    return 0;
}