#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic{
    
    class Player{
        protected:
            Board& b;
            City c;
            string job;

        public:
            Player(Board& b, City c, string j) : b(b), c(c), job(j){}
            virtual Player& treat(City c);
            virtual Player& fly_direct(City c);
            virtual Player& fly_charter(City c);
            virtual Player& fly_shuttle(City c);
            virtual Player& take_card(City c);
            virtual Player& drive(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color color);
            string role(){return job;}
        };

};