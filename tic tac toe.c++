//build a tic tac toe game!
#include <iostream>
#include <vector>

using namespace std;

const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

bool isValidMove(const vector<char>& board, int row, int col) {
  return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row * 3 + col] == EMPTY;
}

void makeMove(vector<char>& board, char player, int row, int col) {
  board[row * 3 + col] = player;
}

bool isWinner(const vector<char>& board, char player) {
  // Check rows and columns
  for (int i = 0; i < 3; ++i) {
    if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player ||
        board[i] == player && board[3 + i] == player && board[6 + i] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0] == player && board[4] == player && board[8] == player ||
      board[2] == player && board[4] == player && board[6] == player) {
    return true;
  }

  return false;
}

bool isDraw(const vector<char>& board) {
  for (char c : board) {
    if (c == EMPTY) {
      return false;
    }
  }
  return true;
}

void displayBoard(const vector<char>& board) {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << board[i * 3 + j] << " | ";
    }
    cout << endl;
  }
}

int main() {
  vector<char> board(9, EMPTY);
  char currentPlayer = PLAYER_X;
  bool playing = true;

  while (playing) {
    displayBoard(board);

    int row, col;
    cout << currentPlayer << ", enter your move (col row): ";
    cin >> row >> col;

    if (!isValidMove(board, row - 1, col - 1)) {
      cout << "Invalid move. Please try again." << endl;
      continue;
    }

    makeMove(board, currentPlayer, row - 1, col - 1);

    if (isWinner(board, currentPlayer)) {
      displayBoard(board);
      cout << currentPlayer << " Congratulations you wins!" << endl;
      playing = false;
    } else if (isDraw(board)) {
      displayBoard(board);
      cout << "It's a draw!" << endl;
      playing = false;
    } else {
      currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
  }

  char playAgain;
  cout << "Play again? (y/n): ";
  cin >> playAgain;

  if(playAgain=='y')
  {
    board.assign(9,EMPTY);
    currentPlayer=PLAYER_X;
    playing=true;

  } else{
    cout<<"Thanks for Playing!"<<endl;
  }

  return 0;

}


