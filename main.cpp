#include <iostream>
#include <string>
#include "Board.h"
#include "View.h"
#include <stdlib.h>

int main() {
  Board board;

  std::cout << "Tic-Tac-Toe\n";

  //std::string first; 

  //int order = rand() % 2;
  int order = 0;
      
  //std::cout << "Would you like to go first? (y/n) "; 
  //std::cin >> first; 
  //std::cout << first; 

  if (order == 0){
    std::cout << "Player Goes First\n";
    display_board(board);
    while (!board.is_win_state_player() && !board.is_win_state_comp()){
      board.player_turn();
      display_board(board);
      if (board.is_win_state_player()){
        break;
      }
      if (board.check_tie()){
        std::cout << "\nThe game has ended in a draw\n";
        break;
      }
      std::cout << "\nComputer's Turn\n";
      board.comp_turn();
      display_board(board);
      if (board.is_win_state_comp()){
        break;
      }
      if (board.check_tie()){
        std::cout << "\nThe game has ended in a draw\n";
        break;
      }
    }
  }
  else{
    std::cout << "Computer Goes First\n";
    while (!board.is_win_state_player() && !board.is_win_state_comp()){
      std::cout << "\nComputer's Turn\n";
      board.comp_turn();
      display_board(board);
      if (board.is_win_state_comp()){
        break;
      }
      if (board.check_tie()){
        std::cout << "\nThe game has ended in a draw\n";
        break;
      }
      board.player_turn();
      display_board(board);
      if (board.is_win_state_player()){
        break;
      }
      if (board.check_tie()){
        std::cout << "\nThe game has ended in a draw\n";
        break;
      }
    }
  }    
  return 0;
}