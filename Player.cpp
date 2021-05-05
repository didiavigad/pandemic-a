#include "Player.hpp"
#include "Board.hpp"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

namespace pandemic{

    Player& Player::build(){
        return *this;
    }

    Player& Player::drive(City c){
        return *this;
    }

    
    Player& Player::discover_cure(Color color){
        return *this;
    }

    Player& Player::treat(City c){
        return *this;
    }

    Player& Player::take_card(City c){
        return *this;
    }


    Player& Player::fly_direct(City c){
        return *this;
    }

    Player& Player::fly_charter(City c){
        return *this;
    }

    Player& Player::fly_shuttle(City c){
        return *this;
    }

};