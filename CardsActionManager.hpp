#pragma once
#include <memory>
#include "Cards.hpp"
#include "Player.hpp"

class CardsActionManager {  // temporary simulation of cards
    std::vector<std::shared_ptr<CharacterCard>> allCharacterCards_;
    std::vector<std::shared_ptr<Card>> allSkillCards_;

// example
    std::shared_ptr<CharacterCard> ex1 = std::make_shared<CharacterCard>(CharacterCard("golun", 5));

    std::vector<std::shared_ptr<Card>> skills{
        {std::make_shared<Card>(BattleCard("pazur1", ex1, 3, 5, false, "example skill card1"))},
        {std::make_shared<Card>(BattleCard("pazur2", ex1, 3, 5, false, "example skill card2"))},
        {std::make_shared<Card>(BattleCard("pazur3", ex1, 3, 5, false, "example skill card3"))},
        {std::make_shared<Card>(BattleCard("pazur4", ex1, 3, 5, false, "example skill card4"))},
        {std::make_shared<Card>(BattleCard("pazur5", ex1, 3, 5, false, "example skill card5"))},
        {std::make_shared<Card>(BattleCard("pazur6", ex1, 3, 5, false, "example skill card6"))},
        {std::make_shared<Card>(BattleCard("pazur7", ex1, 3, 5, false, "example skill card7"))},
        {std::make_shared<Card>(BattleCard("pazur8", ex1, 3, 5, false, "example skill card8"))},
        };

    // normal code

public:
CardsActionManager() {
    // TO DO: read from file all character and skill cards
allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("golun", 5)));
allSkillCards_.push_back(std::make_shared<Card>(BattleCard("pazur1", ex1, 3, 5, false, "example skill card1")));

}
  
    //Player Player2;
};