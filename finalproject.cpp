/* Game of Sorry
 * Justin Akridge
 * 03/06/2023
 * Plays the game of sorry
 */

#include <iostream>
#include <stdlib.h>
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

//function returns die
int roll_die() {
  srand(time(0));
  int first = rand() % 6 + 1; 
  int second = rand() % 6 + 1;
  return first + second;
}

int first_move() {
  int first_roll = roll_die();
  int second_roll = roll_die();
  if(first_roll != second_roll) {
    return 0;
  }
  else{
    return first_roll + second_roll;
  }
 }

int check_for_player(int dice_roll, int index) { 
  return (board[players[index] + dice_roll -1 ] == 1);
}

int main() {
  // get players
  int indexes = get_total_players(); 
  int players[indexes] = {};
  for (int i=1; i<=players; i++) {
    player_array[i] = i;
  }

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























