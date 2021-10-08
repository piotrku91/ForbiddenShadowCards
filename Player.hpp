
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

public:
    size_t cardsLeft() const { return skillsCardsSet.size(); };

    void fillSlots() {
        while (skillsCardsSlots.size() <= 5) {
            skillsCardsSlots.push_back(skillsCardsSet.top());
            skillsCardsSet.pop();
        }
    }

    Player(std::shared_ptr<CharacterCard>characterCard1, std::shared_ptr<CharacterCard>characterCard2, std::shared_ptr<CharacterCard> characterCard3, std::vector<std::shared_ptr<Card>> Cards){
        characterCardsSet[0]=characterCard1;
        characterCardsSet[1]=characterCard2;
        characterCardsSet[2]=characterCard3;

        for (auto& card : Cards)
        {
        skillsCardsSet.push(card);
        }
    };
};