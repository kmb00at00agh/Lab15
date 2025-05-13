#include "Boss.h"
#include "Minion.h"
#include "BossEnemy.h"
#include "MinionEnemy.h"
#include "BattleArena.h"
#include "Dummy.h"
#include "FieldModifier.h"
#include "DungeonMode.h"

using namespace GameEngine;

int main() {
    try {
        Boss boss1("Big foot", -100, 20, 10, SWORDSMAN, 5);
        boss1.validateHealth();
    }
    catch (const invalid_argument& e) {
        cout << "ERROR: " << e.what() << "\n";
    }

    try {
        Boss boss2("Yeti", 120, 10, 15, SHAMAN, 8);
        boss2.powerStrike();
    }
    catch (const runtime_error& e) {
        cout << "ERROR: " << e.what() << "\n";
    }

    try {
        Boss boss3("jin", 150, 25, 20, DRUID, 5);
        boss3.equipRareItem();
    }
    catch (const logic_error& e) {
        cout << "ERROR: " << e.what() << "\n";
    }

    try {
        Boss boss4("Thor", 150, 30, 20, SWORDSMAN, 5);
        boss4.setDizzy(true);  
        boss4.powerStrike();   
    }
    catch (const logic_error& e) {
        cout << "ERROR - Logic Error: " << e.what() << "\n";
    }
    
    return 0;
}