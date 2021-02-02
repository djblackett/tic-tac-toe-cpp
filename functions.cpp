#include "functions.hpp"
#include <vector>
#include <iostream>
#include <regex>

using namespace std;


void draw(char board[]) {
 
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";

}

void update(char board[]) {
  draw(board);
  cout << "\n";
}

void takeTurn(char board[], int turnCount) {
  string strChoice;
  int choice;
  //regex integer_expr(".\\D.");
  cout << "Pick a number between 0 and 8, 0 for top left, 8 for bottom right.\n\n";
  

while (true) {
  try {
  cin >> strChoice;
  //Input validation
  // if (regex_match(strChoice, integer_expr)) {
  //   cout << "Pick a number between 0 and 8.\n\n";
  //   continue;
  // }

  choice = stoi(strChoice);
  if (choice > 8 || choice < 0) {
    cout << "Pick a number between 0 and 8.\n\n";
  } else if (board[choice] == 'X' || board[choice] == 'O') {
    cout << "This square is already full. Choose another.\n\n";
  } 
  else {
    break;
  }
  } catch (...) {
    cout << "Pick a number between 0 and 8.\n\n";
    continue;
  }
}

// Player 1 is X, player 2 is O
if (whoseTurnIsIt(turnCount)) {
  board[choice] = 'X';
} else {
  board[choice] = 'O';
}
}

bool whoseTurnIsIt(int turnCount) {
  // True represents player 1's turn, false is player 2's
  return turnCount % 2 == 0;
}

bool isWinner(char board[]) {
  // Across the top
if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[0] == 'O' && board[1] == 'O' && board[2] == 'O')) {
  return true;
} 

// Across the middle
else if ((board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')) {
  return true;
}

// Across the bottom
else if ((board[6] == 'X' && board[7] == 'X' && board[8] == 'X') || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O')) {
  return true;
}

// Down the left
else if ((board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')) {
  return true;
}

// down the middle
else if ((board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')) {
  return true;
}

// Down the right
else if ((board[2] == 'X' && board[5] == 'X' && board[8] == 'X') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')) {
  return true;
}

// Diagonal from top left
else if ((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')) {
  return true;
}

// Diagonal from top right
else if ((board[2] == 'X' && board[4] == 'X' && board[6] == 'X') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')) {
  return true;
}

// No winner yet
return false;
}

bool isBoardFull(char board[]) {
  // Determines a tie/draw
  int count = 0;
  for (int i = 0; i < 9; i ++) {
    if (board[i] != ' ') {
      count++;
    }
  }
  if (count == 9) {
    return true;
  }

  return false;
}
