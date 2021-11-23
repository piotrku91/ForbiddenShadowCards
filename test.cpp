
#include "gtest/gtest.h"
#include "CardsActionManager.hpp"


struct MainOperations : public ::testing::Test {
CardsActionManager CAM;
};

TEST_F(MainOperations, ShouldLoadTeam) {
    EXPECT_EQ(CAM.Player1_->cardsLeft(),11);
    
}