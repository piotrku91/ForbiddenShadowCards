
#include "CardsActionManager.hpp"
#include "gtest/gtest.h"

struct MainOperations : public ::testing::Test {
    CardsActionManager CAM;
};

TEST_F(MainOperations, ShouldLoadTeam) {
    EXPECT_EQ(CAM.Player1_->cardsLeft(), 45);
}

TEST_F(MainOperations, ShouldDecreaseWhenSwap) {
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    EXPECT_EQ(CAM.Player1_->cardsLeft(), 44);
    CAM.Player1_->swapCardToPoint(4);
    CAM.Player1_->fillSlots();
    EXPECT_EQ(CAM.Player1_->cardsLeft(), 43);
    CAM.Player1_->swapCardToPoint(3);
    CAM.Player1_->fillSlots();
    CAM.Player1_->swapCardToPoint(4);
    CAM.Player1_->fillSlots();
    EXPECT_EQ(CAM.Player1_->cardsLeft(), 41);
}

TEST_F(MainOperations, ShouldGetPointsWhenSwap) {
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    EXPECT_EQ(CAM.Player1_->getActionPoints(), 1);
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    CAM.Player1_->swapCardToPoint(2);
    CAM.Player1_->fillSlots();
    CAM.Player1_->swapCardToPoint(3);
    CAM.Player1_->fillSlots();
    EXPECT_EQ(CAM.Player1_->getActionPoints(), 4);
}

TEST_F(MainOperations, ShouldUsePointsWhenUseCardAndDecreaseActionPoints) {
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    EXPECT_EQ(CAM.Player1_->getActionPoints(), 3);
    EXPECT_EQ(CAM.Player1_->tryUseCard(0), Action::CardUseAction);
    EXPECT_EQ(CAM.Player1_->getActionPoints(), 0);
}

TEST_F(MainOperations, ShouldNotUseCardIfIsNotEnoughActionPoints) {
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    EXPECT_EQ(CAM.Player1_->getActionPoints(), 2);
   EXPECT_EQ(CAM.Player1_->tryUseCard(0), Action::NoPointsToAction);
    EXPECT_EQ(CAM.Player1_->getActionPoints(), 2);
}

TEST_F(MainOperations, ShouldEndIfNoCards) {
    while (CAM.Player1_->cardsLeft()>0) {
    CAM.Player1_->swapCardToPoint(1);
    CAM.Player1_->fillSlots();
    }
    EXPECT_EQ(CAM.Player1_->getActionPoints(), 45);
   EXPECT_EQ(CAM.Player1_->fillSlots(), Action::NoCards);
    
}
