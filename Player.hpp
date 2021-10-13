
#pragma once
#include <array>
#include <memory>
#include <stack>
#include <vector>
#include <map>
#include "Cards.hpp"
#include "Actions.hpp"

class Player {
private:
    size_t actionPoints_;

    std::map <std::string, std::tuple<std::shared_ptr<CharacterCard>, std::shared_ptr<CharacterCard>, std::shared_ptr<CharacterCard>, std::vector<std::shared_ptr<Card>>>> playerTeams;
    std::array<std::shared_ptr<CharacterCard>, 3> characterCardsSet;
    std::stack<std::shared_ptr<Card>> skillsCardsSet;
    std::vector<std::shared_ptr<Card>> skillsCardsSlots;

    void removeCard(size_t slotIndex);
    void removeCard(const std::shared_ptr<Card>& slotPtr);

public:
    size_t cardsLeft() const;
    const std::vector<std::shared_ptr<Card>>& getActualSlots();

    Action fillSlots();
    Action tryUseCard(size_t slotIndex);
    void swapCardToPoint(size_t slotIndex,size_t Multiplicator=1);
    void DecrasePoints(size_t amount);
    void loadTeamToBattle(const std::string& teamName);
    


};