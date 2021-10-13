#include "Player.hpp"

size_t Player::cardsLeft() const {
    return skillsCardsSet.size();
}

const std::vector<std::shared_ptr<Card>>& Player::getActualSlots() {
    return skillsCardsSlots;
}

Action Player::fillSlots() {
    while (skillsCardsSlots.size() < 5) {
        if (!skillsCardsSet.empty()) {
            skillsCardsSlots.push_back(skillsCardsSet.top());
            skillsCardsSet.pop();

        } else
            return Action::NoCards;
    }
    return Action::OK;
}

void Player::removeCard(size_t slotIndex) {
    skillsCardsSlots.erase(
        std::remove(skillsCardsSlots.begin(), skillsCardsSlots.end(), skillsCardsSlots.at(slotIndex)), skillsCardsSlots.end());
}

void Player::removeCard(const std::shared_ptr<Card>& slotPtr) {
    skillsCardsSlots.erase(
        std::remove(skillsCardsSlots.begin(), skillsCardsSlots.end(), slotPtr), skillsCardsSlots.end());
}

void Player::swapCardToPoint(size_t slotIndex, size_t Multiplicator) {
    removeCard(slotIndex);
    actionPoints_ += 1 * Multiplicator;
}

Action Player::tryUseCard(size_t slotIndex) {
    if (skillsCardsSlots.at(slotIndex)->getPointCost() >= actionPoints_) {
        DecrasePoints(skillsCardsSlots.at(slotIndex)->getPointCost());
        return Action::CardUseAction;
    }
    return Action::NoPointsToAction;
}

void Player::DecrasePoints(size_t amount) {
    if ((actionPoints_ < amount)) {
        actionPoints_ = 0;
    };
    actionPoints_ -= amount;
}

void Player::loadTeamToBattle(const std::string& teamName)
 {
     
   // characterCardsSet[0] = characterCard1;
   // characterCardsSet[1] = characterCard2;
    //characterCardsSet[2] = characterCard3;

  //  for (auto& card : Cards) {
  //      skillsCardsSet.push(card);
  //  }
}