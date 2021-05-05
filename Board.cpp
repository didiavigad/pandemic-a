#include "Board.hpp"

using namespace std;

namespace pandemic{ 



    void Board::build(City c){
        this->dev_station.insert(c);
    }

    bool Board::is_clean(){
        return true;
    }

    void Board::remove_cures(){}


    int &Board::operator[](City c){
        return this->spread[c];
    }

    std::ostream& operator<<(ostream& out, Board& board){

        return out;
    }
};