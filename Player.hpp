
#pragma once
#include <array>
#include <memory>
#include <stack>
#include <vector>
#include "Cards.hpp"

class Player {
private:
    size_t actionPoints_;

    std::array<std::shared_ptr<CharacterCard>, 3> characterCardsSet;
    std::stack<std::shared_ptr<Card>> skillsCardsSet;
    std::vector<std::shared_ptr<Card>> skillsCardsSlots;

    void removeCard(size_t slotIndex);
    void removeCard(const std::shared_ptr<Card>& slotPtr);

public:
    size_t cardsLeft() const;
    const std::vector<std::shared_ptr<Card>>& getActualSlots();

    void fillSlots();
    void swapCardToPoint(size_t slotIndex,size_t Multiplicator=1);
    void DecrasePoints(size_t amount);
    

//c -tor
    Player(std::shared_ptr<CharacterCard> characterCard1, std::shared_ptr<CharacterCard> characterCard2, std::shared_ptr<CharacterCard> characterCard3, std::vector<std::shared_ptr<Card>> Cards);
};