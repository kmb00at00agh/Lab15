//#include <iostream>
//#include <string>
//using namespace std;
//
//enum CharacterType { SWORDSMAN, DRUID, SHAMAN };
//enum EnemyType { WITCH, DEMON, BEAST };
//
//// Base Character class
//class Enemy;  // Forward declaration for use in Character methods
//
//class Character {
//protected:
//    string name;
//    int health;
//    int strength;
//    int defense;
//    CharacterType type;
//
//public:
//    Character(string n, int h, int s, int d, CharacterType t) {
//        name = n;
//        health = h;
//        strength = s;
//        defense = d;
//        type = t;
//        cout << "Character " << name << " created!\n";
//    }
//
//    Character(){
//        name = "Unknown";
//        health = 100;
//        strength = 10;
//        defense = 5;
//        type = SWORDSMAN;
//    }
//
//
//    ~Character() { cout << "Character " << name << " destroyed.\n"; }
//
//    string getName() const { return name; }
//    void attack(Enemy& enemy);
//    void getHit(int damage);
//    void heal(int amount);
//    void spawn();
//    void die();
//};
//
//// Base Enemy class
//class Enemy {
//protected:
//    string name;
//    int health;
//    int damage;
//    int defense;
//    EnemyType type;
//
//public:
//    Enemy(string n, int h, int d, int def, EnemyType t) {
//        name = n;
//        health = h;
//        damage = d;
//        defense = def;
//        type = t;
//        cout << "Enemy " << name << " created!\n";
//    }
//
//    Enemy() {
//        name = "Unknown";
//        health = 50;
//        damage = 8;
//        defense = 3;
//        type = BEAST;
//    }
//
//    ~Enemy() { cout << "Enemy " << name << " destroyed.\n"; }
//
//    string getName() const { return name; }
//    void attack(Character& character);
//    void getHit(int damage);
//    void spawn();
//    void die();
//};
//
//// Derived Character class - Boss
//class Boss : public Character {
//private:
//    int rageLevel;
//
//public:
//    Boss(string n, int h, int s, int d, CharacterType t, int rage) {
//        name = n;
//        health = h;
//        strength = s;
//        defense = d;
//        type = t;
//        rageLevel = rage;
//    }
//
//    void unleashRage() {
//        strength += rageLevel;
//        cout << name << " unleashes rage! Strength is now " << strength << "!\n";
//    }
//};
//
//// Derived Character class - Minion
//class Minion : public Character {
//private:
//    int loyalty;
//
//public:
//    Minion(string n, int h, int s, int d, CharacterType t, int l) {
//        name = n;
//        health = h; 
//        strength = h;
//        defense = d;
//        type = t;
//        loyalty = l;
//    }
//
//    void cheerBoss() {
//        cout << name << " cheers the boss with loyalty level " << loyalty << "!\n";
//    }
//};
//
//// Derived Enemy class - BossEnemy
//class BossEnemy : public Enemy {
//private:
//    bool enraged;
//
//public:
//    BossEnemy(string n, int h, int d, int def, EnemyType t, bool e) {
//        name = n;
//        health = h;
//        damage = d;
//        defense = def;
//        type = t;
//        enraged = e;
//    }
//
//    void empower() {
//        if (enraged) {
//            damage += 5;
//            cout << name << " is enraged! Damage increased to " << damage << "!\n";
//        }
//    }
//};
//
//// Derived Enemy class - MinionEnemy
//class MinionEnemy : public Enemy {
//private:
//    int sneakiness;
//
//public:
//    MinionEnemy(string n, int h, int d, int def, EnemyType t, int s){
//        name = n;
//        health = h;
//        damage = d;
//        defense = def;
//        type = t;
//        sneakiness = s;
//
//    }
//    void sneakAttack(Character& target) {
//        int bonus = sneakiness;
//        cout << name << " does a sneak attack!\n";
//        target.getHit(damage + bonus);
//    }
//};
//
//// Character attacking enemy
//void Character::attack(Enemy& enemy) {
//    cout << name << " attacks " << enemy.getName() << "!\n";
//    enemy.getHit(strength);
//}
//
//// Character getting hit
//void Character::getHit(int damage) {
//    int actualDamage = max(0, damage - defense);
//    health -= actualDamage;
//    cout << name << " takes " << actualDamage << " damage! Health: " << health << "\n";
//    if (health <= 0) die();
//}
//
//void Character::heal(int amount) {
//    health += amount;
//    cout << name << " heals for " << amount << " HP! Health is now " << health << "\n";
//}
//
//void Character::spawn() {
//    cout << "Mighty " << name << " appears!\n";
//}
//
//void Character::die() {
//    cout << name << " has died!\n";
//}
//
//// Enemy attacks
//void Enemy::attack(Character& character) {
//    cout << name << " attacks " << character.getName() << "!\n";
//    character.getHit(damage);
//}
//
//void Enemy::getHit(int damage) {
//    int actualDamage = max(0, damage - defense);
//    health -= actualDamage;
//    cout << name << " takes " << actualDamage << " damage! Health: " << health << "\n";
//    if (health <= 0) die();
//}
//
//void Enemy::spawn() {
//    cout << "Angry " << name << " appears!\n";
//}
//
//void Enemy::die() {
//    cout << name << " has been defeated!\n";
//}
//
//// New class that uses existing classes
//class BattleArena {
//private:
//    Character& hero;
//    Enemy& villain;
//
//public:
//    BattleArena(Character& c, Enemy& e) : hero(c), villain(e) {}
//
//    //BattleArena(Character& c, Enemy& e) {
//    //    hero = c;
//    //    villain = e;
//    //}  //Provides no initializer for reference member..
//
//    void battle() {
//        hero.spawn();
//        villain.spawn();
//        cout << "***BATTLE STARTS!*** \n";
//        hero.attack(villain);
//        villain.attack(hero);
//    }
//};
//
//// MAIN function
//int main() {
//    Boss heroBoss("Mighty Mage", 120, 20, 7, SHAMAN, 10);
//    Minion heroMinion("Elder", 60, 10, 3, DRUID, 5);
//
//    BossEnemy bigBad("Ogre", 180, 25, 10, BEAST, true);
//    MinionEnemy sneakyGoblin("Hound", 40, 6, 2, BEAST, 4);
//
//    BattleArena arena(heroBoss, bigBad);
//    arena.battle();
//    
//    heroBoss.unleashRage();
//    heroMinion.cheerBoss();
//    bigBad.empower();
//    sneakyGoblin.sneakAttack(heroMinion);
//
//    
//
//    return 0;
//}
