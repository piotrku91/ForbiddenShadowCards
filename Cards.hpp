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
    bool isAlive() const { return lifePoints_ > 0; }

    CharacterCard(const std::string& characterName, size_t lifePoints)
        : characterName_{characterName}, lifePoints_{lifePoints} {};
};

class Card : public TexturesForCards {
protected:
    std::string shortType_;
    std::string Name_;
    std::shared_ptr<CharacterCard> Character_;
    size_t pointCost_;
    size_t powerPoints_;
    bool Multi_;
    std::string Desc_;

public:
    Card(const std::string& cardName, const std::shared_ptr<CharacterCard>& characterCard, size_t pointCost, size_t powerPoints, bool multi, const std::string& description)
        : Name_{cardName}, Character_{characterCard}, pointCost_{pointCost}, powerPoints_{powerPoints}, Multi_{multi}, Desc_{description} {};

    virtual void setShortType() { shortType_ = "BAS"; };
    std::string getShortType() {return shortType_;};
    std::string getName() const { return Name_; };
    size_t getPointCost() const { return pointCost_; };
};

class BattleCard : public Card {
protected:
    bool Combo_;

public:
    virtual void setShortType() { shortType_ = "BAT"; };
    BattleCard(const std::string& cardName, const std::shared_ptr<CharacterCard>& characterCard, size_t pointCost, size_t powerPoints, bool multi, const std::string& description, bool combo = false)
        : Card{cardName, characterCard, pointCost, powerPoints, multi, description}, Combo_{combo} {setShortType();};
};

class DefenseCard : public Card {
protected:
    virtual void setShortType() { shortType_ = "DEF"; };
      DefenseCard(const std::string& cardName, const std::shared_ptr<CharacterCard>& characterCard, size_t pointCost, size_t powerPoints, bool multi, const std::string& description)
        : Card{cardName, characterCard, pointCost, powerPoints, multi, description} {setShortType();};
};

class ModifierCard : public Card {
protected:
    virtual void setShortType() { shortType_ = "MOD"; };
    ModifierCard(const std::string& cardName, const std::shared_ptr<CharacterCard>& characterCard, size_t pointCost, size_t powerPoints, bool multi, const std::string& description)
        : Card{cardName, characterCard, pointCost, powerPoints, multi, description} {setShortType();};

};

class SpecialCard : public Card {
    protected:
    virtual void setShortType() { shortType_ = "SPC"; };
};
