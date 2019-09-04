#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <vector>

class Board {
  private:
    std::vector<std::vector<Cell> > board;
    coord place;
    std::vector<std::vector<Cell> > init_board();
    bool is_win_state_horiz_player();
    bool is_win_state_vert_player();
    bool is_win_state_diag_player();
    bool is_win_state_horiz_comp();
    bool is_win_state_vert_comp();
    bool is_win_state_diag_comp();
    bool full_diag();
    bool free_edge();
    bool cons_horiz();
    bool cons_vert();
    bool cons_diag();
    bool free_corner();
  public:
    Board();
    void player_turn();
    void comp_turn();
    std::vector<std::vector<Cell> > get_board();
    bool is_win_state_player();
    bool is_win_state_comp();
    bool check_tie();
};



#endif 