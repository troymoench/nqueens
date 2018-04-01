// N-Queens: Hill Climbing
// My laptop was able to solve 50 Queens in ~2 minutes

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"
using namespace std;


Board hillClimbing(Board start) {
  Board current = start;

  while (true) {
    if (current.getCost() == 0) return current;
    Board neighbor = current.getBestNeighbor();
    if (neighbor.getCost() >= current.getCost()) return current; // local min or plateau
    current = neighbor;
  }
}

int main(int argc, char* argv[]) {
  int n;
  if (argc == 2) {
    n = atoi(argv[1]);
  }
  else {
    cout << "Usage: " << argv[0] << " [n]" << endl;
    return -1;
  }
  cout << "N-Queens" << endl;
  cout << "Hill Climbing Algorithm" << endl;
  cout << "N = " << n << endl;

  srand(time(0));
  Board start(n);
  cout << "Start configuration: " << endl;
  start.print();
  start.setCost(start.heuristic());
  cout << "Start cost: " << start.getCost() << endl << endl;

  cout << "Searching for solution..." << endl;
  do {
    Board solution = hillClimbing(start);
    if (solution.getCost() == 0) {
      cout << "Solution found!" << endl;
      solution.print();
      break;
    }
    start.shuffle(); // Local minimum/plateau reached. Need to try again.
  } while (true);


  return 0;
}
