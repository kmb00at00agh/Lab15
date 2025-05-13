#pragma once
#include "Character.h"
#include "Enemy.h"

namespace GameEngine {

    class BattleArena {
    private:
        Character& hero;
        Enemy& villain;

    public:
        BattleArena(Character& c, Enemy& e);
        void battle();
    };

}
