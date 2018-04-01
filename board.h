#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
  Board(int);
  Board(int*, int);
  Board(const Board&);
  void shuffle();
  int heuristic();
  void setCost(int);
  int getCost();
  Board getBestNeighbor();
  void print();
private:
  std::vector<int> board;
  int n;
  int cost;
};

#endif
