// CharacterGroup.h  
#pragma once  
#include "Character.h"  
#include <vector>  

namespace GameEngine {  

   class CharacterGroup : public Character {  
   private:  
       std::vector<Character*> members;  

   public:  
       CharacterGroup(string n, int h, int s, int d, CharacterType t)  
           : Character(n, h, s, d, t) {}  

       void add(Character* character) {  
           members.push_back(character);  
       }  

       void performAction() const override {  
           std::cout << "Group performing actions:\n";  
           for (const auto& c : members) {  
               c->performAction();  
           }  
       }  

       int getPowerLevel() const override {  
           int total = 0;  
           for (const auto& c : members) {  
               total += c->getPowerLevel();  
           }  
           return total;  
       }  

       void describe() const override {  
           std::cout << "Character Group: " << name << "\n";  
           for (const auto& c : members) {  
               c->describe();  
           }  
       }  

       Character* operator+(const Character& other) const override {  
           return nullptr; // Implement if needed  
       }  

       void logStatus() override {  
           std::cout << "Group Status:\n";  
           for (const auto& c : members) {  
               c->logStatus();  
           }  
       }  

       void performTask() override {  
           std::cout << "Group performing tasks:\n";  
           for (const auto& c : members) {  
               c->performTask();  
           }  
       }  

       std::string computeResult() override {  
           std::string result = "Group Results:\n";  
           for (const auto& c : members) {  
               result += c->computeResult() + "\n";  
           }  
           return result;  
       }  

       int generateValue() override {  
           int totalValue = 0;  
           for (const auto& c : members) {  
               totalValue += c->generateValue();  
           }  
           return totalValue;  
       }  

       void processValue(int val) override {  
           std::cout << "Group processing value: " << val << "\n";  
           for (const auto& c : members) {  
               c->processValue(val);  
           }  
       }  

       ~CharacterGroup() {  
           for (auto c : members) {  
               delete c;  
           }  
       }  
   };  
}
