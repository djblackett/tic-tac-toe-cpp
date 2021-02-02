#include "functions.hpp"
#include <iostream>
#include <vector>

using namespace std;


int main() {
  
  // Set blank board
  char board[9] = {};
  for (int i = 0; i < 9; i++) {
    board[i] = ' ';
  }

  draw(board);

  int turnCount = 0;
  bool isPlayer1sTurn = true;
  bool isTie = false;

  // Main game loop
  while (true) {
    if (isPlayer1sTurn) {
      cout << "Player 1's move!\n\n";
    } else {
      cout << "Player 2's move!\n\n";
    }
    
    takeTurn(board, turnCount);
    update(board);

    if (isWinner(board)) {
      break;
    }

    if (isBoardFull(board)) {
      isTie = true;
      break;
    }

    turnCount++;
    isPlayer1sTurn = whoseTurnIsIt(turnCount);
  }

if (isTie) {
  cout << "==============\n";
  cout << "It's a tie!\n";
  cout << "==============\n";
}

  else if (isPlayer1sTurn) {
    cout << "==============\n";
    cout << "Player 1 Wins!\n";
    cout << "==============\n";
  }

  else if (!isPlayer1sTurn) {
    cout << "==============\n";
    cout << "Player 2 Wins!\n";
    cout << "==============\n";
  }
}


