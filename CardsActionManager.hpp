#pragma once
#include <memory>
#include "Cards.hpp"
#include "Player.hpp"

class CardsActionManager {  // temporary simulation of cards
    std::shared_ptr<CharacterCard> ex1 = std::make_shared<CharacterCard>(CharacterCard("golun", 5));

    std::vector<std::shared_ptr<Card>> skills{
        {std::make_shared<Card>(Card("pazur1", ex1, 3, 5, false, "example skill card1"))},
        {std::make_shared<Card>(Card("pazur2", ex1, 3, 5, false, "example skill card2"))},
        {std::make_shared<Card>(Card("pazur3", ex1, 3, 5, false, "example skill card3"))},
        {std::make_shared<Card>(Card("pazur4", ex1, 3, 5, false, "example skill card4"))},
        {std::make_shared<Card>(Card("pazur5", ex1, 3, 5, false, "example skill card5"))},
        {std::make_shared<Card>(Card("pazur6", ex1, 3, 5, false, "example skill card6"))},
        {std::make_shared<Card>(Card("pazur7", ex1, 3, 5, false, "example skill card7"))},
        {std::make_shared<Card>(Card("pazur8", ex1, 3, 5, false, "example skill card8"))},
        };

    // normal code

public:
    Player Player1{ex1, ex1, ex1, skills};
    //Player Player2;
};