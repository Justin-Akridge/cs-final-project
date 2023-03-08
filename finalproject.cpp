/* Game of Sorry
 * Justin Akridge
 * 03/06/2023
 * Plays the game of sorry
 */

#include <iostream>
#include <stdlib.h>
#include <limits>
#include <cmath>
#include <time.h>
#include <cctype>
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

int first_roll() {
  srand(time(0));
  cout << "Press enter to the roll dice";
  cin.get();
  cin.ignore();
  int first = rand() % 6 + 1;
  int second = rand() % 6 + 1;
  cout << "You rolled a " << first << " and a " << second << "\n";
  if(first != second) {
    cout << "You did not roll a double. Wait for another turn.\n";
    return 0;
  }
  else {
    cout << "Move " << first + second << " spaces..\n";
    return first + second;
  }
 }

bool check_for_player(int dice_roll, int index, int board[], int positions[]) { 
  int len = sizeof(positions) / sizeof(positions[0]);
  for(int i=0; i<len; i++) {
    if (board[positions[index] + dice_roll] == 1) {
      return true;
    }
    return false;
  }
}

void start_over(int index, int board[], int positions[]) {
  board[positions[index]] = 0;
  positions[index] = 0;
}

void swap_for_leader(int index, int positions_of_players[]) {
  int number_of_players = sizeof(positions_of_players) / sizeof(positions_of_players[0]);
  int flag = false;
  int position_of_leader = positions_of_players[index];
  int player_in_the_lead = index;
    //find if there is a leading player
  for (int i=0; i<number_of_players; i++) {
    if (positions_of_players[i] > position_of_leader) {
      position_of_leader = positions_of_players[i];
      flag = true
      player_in_the_lead = i;
    }
  }

  // if flag remains false then the player is in the lead
  if (flag == false) {
    cout << "You are the leader. Stay where you are.\n";
    return;
  }
  
  // this is the position of our leading player
  int temp = positions_of_players[position_in_the_lead];
 //swap the leader with the current player
  positions_of_players[player_in_the_lead] = positions_of_players[index];
  positions_of_players[index] = temp;
}


//unit test for swap_for_last function

void swap_for_last(int index, int positions_of_players[]) {
  int numbers_of_players = sizeof(positions_of_players) / sizeof(positions_of_players[0]);
  int flag = false;
  int position_of_last_place = positions_of_players[index];
  int player_in_last_place = index;
    //find if there is a leading player
  for (int i=0; i<numbers_of_players; i++) {
    if (positions_of_players[i] < position_of_last_place) {
      flag = true;
      player_in_last_place = i;
      position_of_last_place = positions_of_players[i];
    }
  }

  // if flag remains false then the player is in the lead
  if (flag == false) {
    cout << "You are already in last.\n";
    break;
  }
}

int special_conditions(int dice_roll, int index, int positions_of_players[]) {
  switch(dice_roll) {
    case 2:
      return 2;
      break;
    case 3:
      return 3;
      break;
    case 4:
      return -1;
      break;
    case 5:
      return 5;
      break;
    case 6:
      return 6;
      break;
    case 7:
      swap_for_leader(index, positions_of_players);
      break;
    case 8:
      return 8;
      break;
    case 9:
      return 9;
      break;
    case 10:
      return 10;
      break;
    case 11:
      swap_for_last(index, dice_roll, board, positions_of_players);
      break;
    case 12:
      return 0;
      // [_] TODO!! FINSIH FUNCTION CALL
      //call function start over after return statement
      break;
  }
}
int main() {
  // get players
  int indexes = get_total_players(); 

  /* this arrary will keep track of the player (index + 1)
   * and the position on the board where each player is at */
  int positions_of_players[indexes] = {0};

  /* Create board.
   * When a player lands on a space, we will change the space
   * from 0 to 1 to mark that a player is there */
  int board[50] = {0};
  
  special_conditions(7, 0, positions_of_players)

  //game loop
  // while (board[50] != 1) {
  //    //loop through each player each time 
  //   for (int i=0; i<indexes; i++) {
     
  //     //this is a new roll on the beginning space
  //     if (players[i] == 0) {
  //       int first_move = first_roll();
  //       //check for player
  //       special_conditions(first_move, i, board[], positon[])
  //       if (check_for_player(first_move, i) {
  //         //change position of player on current space to 0
  //         //put current player on space
  //         // players[i] = 0;
  //       }
  //       else{
  //         board[position[i] + first_move] == 1;
  //         position[player[i]] + first_move;
  //       }  
  //       // if (first_move > 0){
  //       //   board[first_move] = 1;
  //       //   players[i] = first_move;
  //       // } 
  //     }
  //     else {
  //       int dice_roll = roll_dice();
  //       if ([players[i]] + dice_roll <= 50) {
  //         board[players[i]] == 0;
  //         players[i] += dice_roll;
  //         board[players[i]] = 1;
  //       }
  //     }
  //   }   
  // }
}























