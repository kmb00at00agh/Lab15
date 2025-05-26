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

using namespace GameEngine;

int main() {
    
    // Using manually defined factories
    CharacterFactory* bossFactory = new BossFactory();
    CharacterFactory* minionFactory = new MinionFactory();
    EnemyFactory* minonEnemyFactory = new EnemyMinionFactory();
    EnemyFactory* bossEnemyFactory = new EnemyBossFactory();

    Character* boss = bossFactory->createCharacter();
    Character* minion = minionFactory->createCharacter();
    Enemy* enemyMinion = minonEnemyFactory->createEnemy();
    Enemy* enemyBoss = bossEnemyFactory->createEnemy();

    boss->describe();  
    minion->describe();   
    enemyMinion->describe();  
    enemyBoss->describe();     

    // Using AutoFactory
    AutoCharacterFactory<Boss> autoBossFactory;
    Character* autoBoss = autoBossFactory.createCharacter();
    autoBoss->describe();

    AutoEnemyFactory<MinionEnemy> autoMinionEnemyFactory;
    Enemy* autoMinionEnemy = autoMinionEnemyFactory.createEnemy();
    autoMinionEnemy->describe();
    
    // Cleanup
    delete bossFactory;
    delete minionFactory;
    delete minonEnemyFactory;
    delete bossEnemyFactory;
    delete boss;
    delete minion;
    delete enemyMinion;
    delete enemyBoss;
    delete autoBoss;
    delete autoMinionEnemy;

}