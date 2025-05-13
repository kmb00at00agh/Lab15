#include "FieldModifier.h"

// Generic template methods (if needed, otherwise leave empty)
namespace GameEngine {

    // Specialization for Character
    void FieldModifier<Character>::increaseHealth(Character* obj, int amount) {
        obj->heal(amount); // Assuming health is private/protected
    }

    void FieldModifier<Character>::printStats(Character* obj) {
        cout << "Character Stats:\n";
        cout << "Health: " << obj->getHealth() << "\n";
        cout << "Strength: " << obj->getStrength() << "\n";
        cout << "Defense: " << obj->getDefense() << "\n";
    }

    // Specialization for Enemy
    void FieldModifier<Enemy>::increaseHealth(Enemy* obj, int amount) {
        obj->increaseHealth(amount);
    }

    void FieldModifier<Enemy>::printStats(Enemy* obj) {
        cout << "Enemy Stats:\n";
        cout << "Health: " << obj->getHealth() << "\n";
        cout << "Damage: " << obj->getDamage() << "\n";
        cout << "Defense: " << obj->getDefense() << "\n";
    }

    // Function to describe a Character
    void describeCharacter(const Character* c) {
        c->describe();
    }
}