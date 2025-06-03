#include <iostream>  
#include "Character.h"  
#include "Boss.h"  
#include "Minion.h"  
#include "../include/gtest/gtest.h"  

using namespace GameEngine;  

//TEST(CharacterTest, DescribeValueCorrectValue)  
//{  
//   Character* b = new Boss("BossName", 150, 30, 20, GameEngine::CharacterType::SWORDSMAN, 100);  
//   Character* m = new Minion("MinionName", 80, 15, 10, GameEngine::CharacterType::DRUID, 50);  
//
//   EXPECT_EQ(b->describe(), std::string("is a powerful boss with rage level"));  
//   EXPECT_EQ(m->describe(), std::string("is a loyal minion with loyalty level "));  
//
//   delete b;  
//   delete m;  
//}  
//
//int main(int argc, char** argv)  
//{  
//   ::testing::InitGoogleTest(&argc, argv);  
//   return RUN_ALL_TESTS();  
//}
