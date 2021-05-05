#pragma once
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include <string>

namespace pandemic{

    class Scientist : public Player{

        int numCards;
        
        public:
            Scientist(Board& b, City c, int numC) : Player(b, c, "Scientist"), numCards(numC){}
            Player& discover_cure(Color color);
    };
};
