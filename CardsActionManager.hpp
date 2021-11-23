#pragma once
#include <memory>
#include "Cards.hpp"
#include "Player.hpp"

class CardsActionManager {  // temporary simulation of cards
    std::vector<std::shared_ptr<CharacterCard>> allCharacterCards_;
    std::vector<std::shared_ptr<Card>> allSkillCards_;

    

public:
std::shared_ptr<Player> Player1_;
CardsActionManager() {
    // TO DO: read from file all character and skill cards
    // DEFAULT CARDS
allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("STONE", 5)));
allSkillCards_.push_back(std::make_shared<Card>(BattleCard("Heavy Roller", allCharacterCards_.back(), 3, 5, false, "This card smash oponent.")));
allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("FIRE", 5)));
allSkillCards_.push_back(std::make_shared<Card>(BattleCard("Heavy Roller", allCharacterCards_.back(), 3, 5, false, "This card smash oponent.")));
allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("WATER", 5)));
allSkillCards_.push_back(std::make_shared<Card>(BattleCard("Heavy Roller", allCharacterCards_.back(), 3, 5, false, "This card smash oponent.")));


Player1_ = std::make_shared<Player>(Player{allCharacterCards_,allSkillCards_});

}
    
    //Player Player2;
};