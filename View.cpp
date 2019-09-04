#include "Board.h"
#include "Cell.h"
#include <vector>
#include <iostream>

void display_board(Board board){
  std::cout << "\n0|1|2\n";
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (board.get_board()[i][j].player){
        std::cout << "X";
      }
      else if (board.get_board()[i][j].comp){
        std::cout << "O";
      }
      else {
        std::cout << " ";
      }

      if (j != 2){
        std::cout << "|";
      }
    }
    std::cout << "|" << i;
    if (i != 2){
      std::cout << "\n- - -\n";
    }
    else{
      std::cout << "\n";
    }
    
  }

}