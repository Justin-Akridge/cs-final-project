/* Game of Sorry
 * Justin Akridge
 * 03/06/2023
 * Plays the game of sorry
 */

#include <iostream>
#include <stdlib.h>
#include <limits>
#include <time.h>
using namespace std;

int get_total_players() {
  int players = 0;
  while(players < 2 || players > 4) {
    cout << "Enter total number of players (2-4): ";
    cin >> players;
  }
  return players;
}

int roll_dice() {
  srand(time(0));
  cout << "Press enter to the roll dice";
  cin.get();
  cin.ignore();
  int first = rand() % 6 + 1; 
  int second = rand() % 6 + 1;
  cout << "You rolled a " << second << ".\n";
  cout << "You rolled a " << first << " and a " << second <<
          "... Move " << first + second << " spaces." <<  "\n";
  return first + second;
}

int first_move() {
  srand(time(0));
  cout << "Press enter to the roll dice";
  cin.get();
  cin.ignore();
  int first_roll = rand() % 6 + 1;
  int second_roll = rand() % 6 + 1;
  cout << "You rolled a " << first_roll << " and a " << second_roll << "\n";
  if(first_roll != second_roll) {
    cout << "You did not roll a double. Wait for another turn.\n";
    return 0;
  }
  else {
    return first_roll + second_roll;
  }
 }

int check_for_player(int dice_roll, int index, int board[], int players[]) { 
  return (board[players[index] + dice_roll -1 ] == 1);
}

int main() {
  // get players
  int indexes = get_total_players(); 
  int players[indexes] = {0};
  for (int i=1; i<=indexes; i++) {
    players[i] = i;
  }

  int position[indexes] = {0};
  // need another array to keep track of the positions of each
  // and then match that to where it is on the board
  //create board
  int board[50] = {0};
  
  //game loop
  while (board[50] != 1) {
     //loop through each player each time 
    for (int i=0; i<indexes; i++) {
     
      //this is a new roll on the beginning space
      if (players[i] == 0) {
        int first_move == first_move();
        //check for player
        if (check_for_player(first_move, i) {
          board[players[i]] = 0;
          players[i] = 0;
        }  
        if (first_move > 0){
          board[first_move] = 1;
          players[i] = first_move;
        } 
      }
      else {
        int dice_roll = roll_dice();
        if ([players[i]] + dice_roll <= 50) {
          board[players[i]] == 0;
          players[i] += dice_roll;
          board[players[i]] = 1;
        }
      }
    }   
  }
}























