#pragma once
#include <memory>
#include "Cards.hpp"
#include "Player.hpp"

class CardsActionManager {  // temporary simulation of cards
    std::vector<std::shared_ptr<CharacterCard>> allCharacterCards_;
    std::vector<std::shared_ptr<Card>> allSkillCards_;

public:
CardsActionManager() {
    // TO DO: read from file all character and skill cards
allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("golun", 5)));
allSkillCards_.push_back(std::make_shared<Card>(BattleCard("pazur1", allCharacterCards_.back(), 3, 5, false, "example skill card1")));

}
     Player Player1;
    //Player Player2;
};