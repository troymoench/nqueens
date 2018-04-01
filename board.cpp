#include "board.h"
#include <iostream>
#include <cstdlib>

Board::Board(int n) {
  this->n = n;
  for (int i = 0; i < n; i++) {
    this->board.push_back(rand() % n);
  }
}

Board::Board(int* start, int n) {
    for (int i = 0; i < n; i++) {
      this->board.push_back(start[i]);
    }
    this->n = n;
}

Board::Board(const Board& other) {
  this->board = other.board;
  this->n = other.n;
  this->cost = other.cost;
}


void Board::shuffle() {
  for (int i = 0; i < n; i++) {
    board[i] = rand() % n;
  }
}

int Board::heuristic() {
  // number of queens attacking each other
  int h = 0;
  int offset;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      // check columns
      if (board[i] == board[j]) {
        h++;
      }
      // check diagonals
      offset = j - i;
      if (board[i] == (board[j] - offset) || board[i] == (board[j] + offset)) {
        h++;
      }
    }
  }
  return h;
}

void Board::setCost(int cost) {
  this->cost = cost;
}

int Board::getCost() {
  return this->cost;
}

Board Board::getBestNeighbor() {
  // get the neighbor that has the lowest cost
  Board temp = *this;
  int row, col, cur_cost, val;
  int min_cost = 1000000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (temp.board[i] == j) continue; // avoid false plateau

      val = temp.board[i]; // save the column value
      temp.board[i] = j;
      cur_cost = temp.heuristic();
      if (cur_cost < min_cost) {
        row = i;
        col = j;
        min_cost = cur_cost;
      }
      temp.board[i] = val; // reset the board
    }
  }
  temp.board[row] = col; // make the best move
  temp.cost = min_cost;
  return temp;
}

void Board::print() {
  char blank = '-';
  char queen = 'Q';

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i] == j) {
        std::cout << queen << " ";
      }
      else {
          std::cout << blank << " ";
      }
    }
    std::cout << std::endl;
  }
}
