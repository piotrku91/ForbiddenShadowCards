#pragma once
#include <memory>
#include "Cards.hpp"
#include "Player.hpp"

class CardsActionManager {  // temporary simulation of cards
    std::vector<std::shared_ptr<CharacterCard>> allCharacterCards_;
    std::vector<std::shared_ptr<Card>> allSkillCards_;

public:
    std::shared_ptr<Player> Player1_;

    size_t getCountAllCharacterCards() const {return allCharacterCards_.size();};
    size_t getCountAllSkillCards() const {return allSkillCards_.size();};

    void loadCardsDataFromFile() {
        allCharacterCards_.clear();
        allSkillCards_.clear();
        // Stub function for now
        allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("STONE", 5)));
        for(int i=0; i<100; i++){
        allSkillCards_.push_back(std::make_shared<Card>(BattleCard("Heavy Roller"+i, allCharacterCards_.back(), 3, 5, false, "This card smash oponent.")));
        }
        allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("FIRE", 5)));
           for(int i=0; i<100; i++){
        allSkillCards_.push_back(std::make_shared<Card>(BattleCard("Heavy Roller"+i, allCharacterCards_.back(), 3, 5, false, "This card smash oponent.")));
        }
        allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("WATER", 5)));
            for(int i=0; i<100; i++){
        allSkillCards_.push_back(std::make_shared<Card>(BattleCard("Heavy Roller"+i, allCharacterCards_.back(), 3, 5, false, "This card smash oponent.")));
        }
        allCharacterCards_.push_back(std::make_shared<CharacterCard>(CharacterCard("CUP", 5)));
         for(int i=0; i<100; i++){
        allSkillCards_.push_back(std::make_shared<Card>(BattleCard("Heavy Roller"+i, allCharacterCards_.back(), 3, 5, false, "This card smash oponent.")));
        }
        Player1_ = std::make_shared<Player>(Player{allCharacterCards_, allSkillCards_});
    }

    CardsActionManager() {
    loadCardsDataFromFile();
    }

    //Player Player2;
};