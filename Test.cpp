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

TEST_CASE("operator []"){
	Board board;  
	board[City::London] = 5;    
    for(int i=0;i<101;i++)CHECK(board[City::London] == 5);
}


