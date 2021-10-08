#pragma once
#include <memory>
#include "Cards.hpp"
#include "Player.hpp"

class CardsActionManager {  // temporary simulation of cards
    std::shared_ptr<CharacterCard> ex1 = std::make_shared<CharacterCard>(CharacterCard("golun", 5));

    std::vector<std::shared_ptr<Card>> skills{std::make_shared<Card>(Card("pazur", ex1, 3, 5, false, "example skill card"))};

    // normal code

private:
    Player Player1{ex1, ex1, ex1, skills};
    //Player Player2;
};