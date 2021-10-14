
#pragma once
#include <array>
#include <map>
#include <memory>
#include <stack>
#include <vector>
#include "Actions.hpp"
#include "Cards.hpp"

class Player {
private:
    size_t actionPoints_;
    using PlayerTeamMap = std::tuple< std::shared_ptr<CharacterCard>, std::shared_ptr<CharacterCard>, std::shared_ptr<CharacterCard>, std::vector<std::shared_ptr<Card>> >;
    std::map <std::string,PlayerTeamMap> playerTeams;

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
    void swapCardToPoint(size_t slotIndex, size_t Multiplicator = 1);
    void DecrasePoints(size_t amount);
    void loadTeamToBattle(const std::string& teamName);
    PlayerTeamMap loadTeamToEdit(const std::string& teamName);
};