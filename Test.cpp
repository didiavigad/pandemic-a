#include <iostream>
#include "doctest.h"   
#include <stdexcept>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "Medic.hpp"
#include "GeneSplicer.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <string>
using namespace std; //used to include functions such as memcpy..


TEST_CASE("Scientist"){
    Board board;
    Scientist player{board, City::Santiago, 1};
    player.take_card(Santiago);
    player.build();
    CHECK_THROWS(player.discover_cure(Color::Yellow)); //ilegall action: Don't have cards.
    player.take_card(City::Bogota);
    CHECK_NOTHROW(player.discover_cure(Color::Yellow)); // llegal action: Have 1 card.
}


TEST_CASE("Dispatcher"){
    Board board;
    Dispatcher player{board, City::Sydney};
    CHECK_THROWS(player.build());
    player.take_card(Sydney);
    CHECK_NOTHROW(player.build());
    player.take_card(Santiago).take_card(Seoul).take_card(Shanghai);
    board.build(City::SaoPaulo);
    player.fly_direct(SaoPaulo);
    CHECK_THROWS(player.build());
    player.take_card(SaoPaulo);
    board[City::SaoPaulo] = 3;
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    CHECK_NOTHROW(player.treat(SaoPaulo));
    CHECK(board[City::SaoPaulo] == 2);
}


TEST_CASE("operator []"){
	Board board;  
	board[City::Baghdad] = 4;     
	board[City::Chicago] = 2;    
	board[City::Madrid] = 2; 
	board[City::Lagos] = 1; 
    CHECK_NOTHROW(board[City::Baghdad] = 3);
    CHECK_NE(board[City::Baghdad], 4);
    CHECK(board[City::Chicago] == 2);
    CHECK(board[City::Madrid] == 2);
    CHECK(board[City::Lagos] == 1);
    board[City::Baghdad] = 1;
    board[City::Madrid] = 0;
    CHECK(board[City::Baghdad] != 3);
    CHECK(board[City::Madrid] == 0);
    CHECK(board[City::Jakarta] == 0);
    board[City::Jakarta] = 2;
    CHECK(board[City::Jakarta] != 0);
    CHECK(board[City::Jakarta] == 2);
    board[City::Karachi] = 4;
    CHECK(board[City::Karachi] == 4);
    board[City::Karachi] = 1;
    CHECK(board[City::Karachi] == 1);
    board[City::Karachi] = 0;
    CHECK(board[City::Karachi] == 0);
}

TEST_CASE("OprationsExpert"){
    Board board;
    OperationsExpert player{board, LosAngeles};
    player.build();
    player.take_card(City::Chicago).take_card(City::Washington).take_card(City::Paris); 
    player.fly_direct(City::Washington);
    player.build();
    player.take_card(Washington).take_card(SanFrancisco).take_card(Chicago).take_card(StPetersburg);
    CHECK_THROWS(player.fly_shuttle(City::StPetersburg));
    player.fly_direct(Chicago);
    player.build();
    board[City::Chicago] = 5;
    board.remove_cures();
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    CHECK_NOTHROW(player.treat(City::Chicago));
}