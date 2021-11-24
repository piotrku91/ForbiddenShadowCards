
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

    // Actual battle containers
    std::array<std::shared_ptr<CharacterCard>, 3> characterCardsSet;
    std::stack<std::shared_ptr<Card>> skillsCardsSet;
    std::vector<std::shared_ptr<Card>> skillsCardsSlots;
    
    // In battle functions
    void removeCard(size_t slotIndex);
    void removeCard(const std::shared_ptr<Card>& slotPtr);

public:
    // In battle functions
    const std::vector<std::shared_ptr<Card>>& getActualSlots();
    size_t getActionPoints() const {return actionPoints_;};
    size_t cardsLeft() const;
    Action fillSlots();
    Action tryUseCard(size_t slotIndex);
    void swapCardToPoint(size_t slotIndex, size_t Multiplicator = 1);
    void DecrasePoints(size_t amount);


    // Battle prepair function
    void loadTeamToBattle(const std::string& teamName);


    Player(std::vector<std::shared_ptr<CharacterCard>>& allCards, std::vector<std::shared_ptr<Card>>& allSkillCards):actionPoints_(0){
    // TEMPORARY TEAM CREATION

   playerTeams.insert({"mainteam", PlayerTeamMap{allCards[0],allCards[1],allCards[2],allSkillCards}});

   
    loadTeamToBattle("mainteam");
    fillSlots();

    }
};

