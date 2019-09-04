#include "Board.h"
#include "Cell.h"

#include <iostream>
#include <vector>

std::vector<std::vector<Cell> > Board::init_board(){
  std::vector<Cell> cell_row;
  std::vector<std::vector<Cell> > cell_arr;

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      Cell cell;
      cell.player = false;
      cell.comp = false;
      cell_row.push_back(cell);
    }
    cell_arr.push_back(cell_row);
  }

  return cell_arr;
}

Board::Board(){
  this->board = init_board();
}

std::vector<std::vector<Cell> > Board::get_board(){
  return this->board;
}

bool Board::check_tie(){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (!board[i][j].player && !board[i][j].comp){
        return false;
      }
    }
  }
  return true;
}

bool Board::is_win_state_horiz_player(){
  for (int i = 0; i < 3; i++){
    if (board[i][0].player && board[i][1].player && board[i][2].player){
      return true;
    }
  }

  return false;
}

bool Board::is_win_state_vert_player(){
  for (int i = 0; i < 3; i++){
    if (board[0][i].player && board[1][i].player && board[2][i].player){
      return true;
    }
  }

  return false;
}

bool Board::is_win_state_diag_player(){
  if (board[0][0].player && board[1][1].player && board[2][2].player){
    return true;
  }
  else if (board[0][2].player && board[1][1].player && board[2][0].player){
    return true;
  }
  else{
    return false;
  }
}

bool Board::is_win_state_player(){
  if (is_win_state_diag_player() || is_win_state_vert_player() || is_win_state_horiz_player()){
    std::cout << "Player has won";
    return true;
  }
  else{
    return false;
  }
}

bool Board::is_win_state_horiz_comp(){
  for (int i = 0; i < 3; i++){
    if (board[i][0].comp && board[i][1].comp && board[i][2].comp){
      return true;
    }
  }

  return false;
}

bool Board::is_win_state_vert_comp(){
  for (int i = 0; i < 3; i++){
    if (board[0][i].comp && board[1][i].comp && board[2][i].comp){
      return true;
    }
  }

  return false;
}

bool Board::is_win_state_diag_comp(){
  if (board[0][0].comp && board[1][1].comp && board[2][2].comp){
    return true;
  }
  else if (board[0][2].comp && board[1][1].comp && board[2][0].comp){
    return true;
  }
  else{
    return false;
  }
}

bool Board::full_diag(){
  if ((board[0][0].comp || board[0][0].player) && (board[1][1].comp || board[1][1].player) && (board[2][2].comp || board[2][2].player)){
    return true;
  }
  else if ((board[0][2].comp || board[0][2].player) && (board[1][1].comp || board[1][1].player) && (board[2][0].comp || board[2][0].player)){
    return true;
  }
  else{
    return false;
  }
}

bool Board::free_edge(){
  if (!board[0][1].player && !board[0][1].comp){
    place.x = 0;
    place.y = 1;
    return true;
  }
  else if (!board[1][0].player && !board[1][0].comp){
    place.x = 1;
    place.y = 0;
    return true;
  }
  else if (!board[1][2].player && !board[1][2].comp){
    place.x = 1;
    place.y = 2;
    return true;
  }
  else if (!board[2][1].player && !board[2][1].comp){
    place.x = 2;
    place.y = 1;
    return true;
  }
  else{
    return false;
  }
}

bool Board::is_win_state_comp(){
  if (is_win_state_diag_comp() || is_win_state_vert_comp() || is_win_state_horiz_comp()){
    std::cout << "Computer has won";
    return true;
  }
  else{
    return false;
  }
}

void Board::player_turn(){
  int x;
  int y;

  std::cout << "Put the y coordinate where you would like to place your Y ";
  std::cin >> x;
  std::cout << "Put the x coordinate where you would like to place your X ";
  std::cin >> y;

  if (this->board[x][y].comp || this->board[x][y].player){
    std::cout << "Invalid coordinates, already taken\n";
    std::cout << "Put the y coordinate where you would like to place your Y ";
    std::cin >> x;
    std::cout << "Put the x coordinate where you would like to place your X ";
    std::cin >> y;
    this->board[x][y].player = true;
  }
  else{
    this->board[x][y].player = true;
  }
}

bool Board::cons_horiz(){
  for (int i = 0; i < 3; i++){
    if (board[i][0].player && board[i][1].player){
      if (!board[i][2].player && !board[i][2].comp){
        place.x = i;
        place.y = 2;
        return true;
      }
    }
    if (board[i][1].player && board[i][2].player){
      if (!board[i][0].player && !board[i][0].comp){
        place.x = i;
        place.y = 0;
        return true;
      }
    }
    if (board[i][0].player && board[i][2].player){
      if (!board[i][1].player && !board[i][1].comp){
        place.x = i;
        place.y = 1;
        return true;
      }
    }
    if (board[i][0].comp && board[i][1].comp){
      if (!board[i][2].player && !board[i][2].comp){
        place.x = i;
        place.y = 2;
        return true;
      }
    }
    if (board[i][1].comp && board[i][2].comp){
      if (!board[i][0].player && !board[i][0].comp){
        place.x = i;
        place.y = 0;
        return true;
      }
    }
    if (board[i][0].comp && board[i][2].comp){
      if (!board[i][1].player && !board[i][1].comp){
        place.x = i;
        place.y = 1;
        return true;
      }
    }
  }
  return false;
}

bool Board::cons_vert(){
  for (int i = 0; i < 3; i++){
    if (board[0][i].player && board[1][i].player){
      if (!board[2][i].player && !board[2][i].comp){
        place.x = 2;
        place.y = i;
        return true;
      }
    }
    if (board[1][i].player && board[2][i].player){
      if (!board[0][i].player && !board[0][i].comp){
        place.x = 0;
        place.y = i;
        return true;
      }
    }
    if (board[0][i].player && board[2][i].player){
      if (!board[1][i].player && !board[1][i].comp){
        place.x = 1;
        place.y = i;
        return true;
      }
    }
    if (board[0][i].comp && board[1][i].comp){
      if (!board[2][i].player && !board[2][i].comp){
        place.x = 2;
        place.y = i;
        return true;
      }
    }
    if (board[1][i].comp && board[2][i].comp){
      if (!board[0][i].player && !board[0][i].comp){
        place.x = 0;
        place.y = i;
        return true;
      }
    }
    if (board[0][i].comp && board[2][i].comp){
      if (!board[1][i].player && !board[1][i].comp){
        place.x = 1;
        place.y = i;
        return true;
      }
    }
  }
  return false;
}

bool Board::cons_diag(){
  if (board[0][0].player && board[1][1].player){
    if (!board[2][2].player && !board[2][2].comp){
      place.x = 2;
      place.y = 2;
      return true;
    }
  }
  if (board[1][1].player && board[2][2].player){
    if (!board[0][0].player && !board[0][0].comp){
      place.x = 0;
      place.y = 0;
      return true;
    }
  }
  if (board[0][0].player && board[2][2].player){
    if (!board[1][1].player && !board[1][1].comp){
      place.x = 1;
      place.y = 1;
      return true;
    }
  }
  if (board[0][2].player && board[1][1].player){
    if (!board[2][0].player && !board[2][0].comp){
      place.x = 2;
      place.y = 0;
      return true;
    }
  }
  if (board[1][1].player && board[2][0].player){
    if (!board[0][2].player && !board[0][2].comp){
      place.x = 0;
      place.y = 2;
      return true;
    }
  }
  if (board[0][2].player && board[2][0].player){
    if (!board[1][1].player && !board[1][1].comp){
      place.x = 1;
      place.y = 1;
      return true;
    }
  }

  if (board[0][0].comp && board[1][1].comp){
    if (!board[2][2].player && !board[2][2].comp){
      place.x = 2;
      place.y = 2;
      return true;
    }
  }
  if (board[1][1].comp && board[2][2].comp){
    if (!board[0][0].player && !board[0][0].comp){
      place.x = 0;
      place.y = 0;
      return true;
    }
  }
  if (board[0][0].comp && board[2][2].comp){
    if (!board[1][1].player && !board[1][1].comp){
      place.x = 1;
      place.y = 1;
      return true;
    }
  }
  if (board[0][2].comp && board[1][1].comp){
    if (!board[2][0].player && !board[2][0].comp){
      place.x = 2;
      place.y = 0;
      return true;
    }
  }
  if (board[1][1].comp && board[2][0].comp){
    if (!board[0][2].player && !board[0][2].comp){
      place.x = 0;
      place.y = 2;
      return true;
    }
  }
  if (board[0][2].comp && board[2][0].comp){
    if (!board[1][1].player && !board[1][1].comp){
      place.x = 1;
      place.y = 1;
      return true;
    }
  }
  return false;
}

bool Board::free_corner(){
  if (!board[0][0].player && !board[0][0].comp){
    if (board[1][0].player || board[0][1].player){
      place.x = 0;
      place.y = 0;
      return true;
    } 
  }
  if (!board[0][2].player && !board[0][2].comp){
    if (board[0][1].player || board[1][2].player){
      place.x = 0;
      place.y = 2;
      return true;
    } 
  }
  if (!board[2][0].player && !board[2][0].comp){
    if (board[1][0].player || board[2][1].player){
      place.x = 2;
      place.y = 0;
      return true;
    }
  }
  if (!board[2][2].player && !board[2][2].comp){
    if (board[2][1].player || board[1][2].player){
      place.x = 2;
      place.y = 2;
      return true;
    }
  }
  return false;
}

void Board::comp_turn(){
  //first move should always be the centre if possible
  if (!board[1][1].player && !board[1][1].comp){
    board[1][1].comp = true;
    return;
  }
  
  //if there are any 2 consecutive pieces, always fill it
  if (cons_horiz()){
    board[place.x][place.y].comp = true;
    return;
  }
  
  if (cons_vert()){
    board[place.x][place.y].comp = true;
    return;
  }
  
  if (cons_diag()){
    board[place.x][place.y].comp = true;
    return;
  }
  
  //first check if there is a full diagonal, then place on edge
  if (full_diag()){
    if (free_edge()){
      board[place.x][place.y].comp = true;
      return;
    }
  }

  //else, check for any free corners
  if (free_corner()){
    board[place.x][place.y].comp = true;
    return;
  }
  
  //else pick free spot
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (!board[i][j].player && !board[i][j].comp){
        board[i][j].comp = true;
        return;
      }
    }
  }
  

}


