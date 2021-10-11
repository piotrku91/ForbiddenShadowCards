#include "Player.hpp"

 size_t Player::cardsLeft() const { return skillsCardsSet.size(); };

    const std::vector<std::shared_ptr<Card>>& Player::getActualSlots() {
        return skillsCardsSlots;
    }

    void Player::fillSlots() {
        while (skillsCardsSlots.size() < 5) {
            if (!skillsCardsSet.empty()) {
                skillsCardsSlots.push_back(skillsCardsSet.top());
                skillsCardsSet.pop();
            };
        }
    }

    void Player::removeCard(size_t slotIndex) {
        skillsCardsSlots.erase(
            std::remove(skillsCardsSlots.begin(), skillsCardsSlots.end(), skillsCardsSlots.at(slotIndex)), skillsCardsSlots.end());
    }

    void Player::removeCard(const std::shared_ptr<Card>& slotPtr) {
        skillsCardsSlots.erase(
            std::remove(skillsCardsSlots.begin(), skillsCardsSlots.end(), slotPtr), skillsCardsSlots.end());
    }

    void Player::swapCardToPoint(size_t slotIndex,size_t Multiplicator)
    {
    removeCard(slotIndex);
    actionPoints_+=1*Multiplicator;   
    }

    void Player::DecrasePoints(size_t amount)
    {
    if ((actionPoints_- amount)<0) {actionPoints_=0;};
    actionPoints_-=amount; 
    }

    Player::Player(std::shared_ptr<CharacterCard> characterCard1, std::shared_ptr<CharacterCard> characterCard2, std::shared_ptr<CharacterCard> characterCard3, std::vector<std::shared_ptr<Card>> Cards):actionPoints_(0) {
        characterCardsSet[0] = characterCard1;
        characterCardsSet[1] = characterCard2;
        characterCardsSet[2] = characterCard3;

        for (auto& card : Cards) {
            skillsCardsSet.push(card);
        }
    };