#pragma once
#include <memory>
#include <string>

class TexturesForCards {
protected:
    size_t TextureID_;
};

class CharacterCard : public TexturesForCards {
private:
    std::string characterName_;
    size_t lifePoints_;

public:
    std::string getName() const { return characterName_; }
    size_t getLifePoints() const { return lifePoints_; };

    CharacterCard(const std::string& characterName, size_t lifePoints)
        : characterName_{characterName}, lifePoints_{lifePoints} {};
};

class Card : public TexturesForCards {
protected:
    std::string Name_;
    std::shared_ptr<CharacterCard> Character_;
    size_t pointCost_;
    size_t powerPoints_;
    bool Multi_;
    std::string Desc_;

public:
    Card(const std::string& cardName, const std::shared_ptr<CharacterCard>& characterCard, size_t pointCost,  size_t powerPoints, bool multi, const std::string& description)
        : Name_{cardName}, Character_{characterCard}, pointCost_{pointCost}, powerPoints_{powerPoints}, Multi_{multi}, Desc_{description} {};
};

class BattleCard : public Card {
protected:
    bool Combo;
};

class DefenseCard : public Card {
};

class ModifierCard : public Card {
};

class SpecialCard : public Card {
};
