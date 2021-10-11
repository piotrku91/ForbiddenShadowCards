#include <iostream>
#include "CardsActionManager.hpp"

CardsActionManager CAM;

int main() {
  std::cout << "Gracz 1!\n";
CAM.Player1.fillSlots();
  for (const auto& slot :CAM.Player1.getActualSlots())
  {
   std::cout << slot->getName() << "|\n";
  }
  CAM.Player1.swapCardToPoint(1);
  CAM.Player1.fillSlots();
  for (const auto& slot :CAM.Player1.getActualSlots())
  {
   std::cout << slot->getName() << "|\n";
  }

  std::cout << "Kart " << CAM.Player1.cardsLeft()  << "\n";
}