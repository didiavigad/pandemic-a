#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic{
    class Board{

        friend class Player;
        public:
            map<City, int> spread;
            set<City> dev_station;
            bool cure[4]={0};
            bool black, blue, red, yellow;

        public:
            Board(){}
            void build(City c);
            bool is_clean();
            void remove_cures();
            string colors(int color);
            int &operator [](City c);
            friend ostream& operator<<(ostream& out, Board& b);
    };

};
