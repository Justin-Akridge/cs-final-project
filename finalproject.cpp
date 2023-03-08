/* Game of Sorry
 * Justin Akridge
 * 03/06/2023
 * Plays the game of sorry
 */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <time.h>
#include <cctype>
using namespace std;

//[x] TODO: UNIT TEST FOR GET_TOTAL_PLAYERS FUNCTION

int get_total_players() {
  int players = 0;
  while(players < 2 || players > 4) {
    cout << "Enter total number of players (2-4): ";
    cin >> players;
    cout << endl;
  }
  return players;
}

// [x] TODO: UNIT TEST FOR ROLL_DICE FUNCTION

int roll_dice() {
  srand(time(0));
  cout << "Press enter to the roll dice";
  cin.get();
  cin.ignore();
  int first = rand() % 6 + 1; 
  int second = rand() % 6 + 1;
  cout << "You rolled a " << first << " and a " << second <<
          "\nMove " << first + second << " spaces.." <<  endl;
  return first + second;
}

// [x] TODO: UNIT TEST FOR FIRST_ROLL FUNCTION

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

 //[x] TODO: UNIT TEST FOR DISPLAY_POSITIONS_OF_PLAYERS

void display_positions_of_players(int positions_of_players[], int players) {
  cout << "Positions on board" << endl;
  cout << "------------------" << endl;
  for (int i=0; i<players; i++) {
    cout << "Player " << (i + 1) << ": " << positions_of_players[i] << endl;
    cout << endl;
  }
}

 //[x] TODO: UNIT TEST FOR CHECK_FOR_PLAYERS FUNCTION

bool check_for_player(int dice_roll, int index, int board[], int positions_of_players[], int players) { 
  for(int i=0; i<players; i++) {
    if (board[positions_of_players[index] + dice_roll] == 1) {
      return true;
    }
  }
  return false;
}


//[x] TODO: UNIT TEST FOR SWAP_FOR_LEADER FUNCTION

void swap_for_leader(int index, int positions_of_players[], int players) {
  int flag = false;
  int position_of_leader = positions_of_players[index];
  int player_in_the_lead = index;
    //find if there is a leading player
  for (int i=0; i<players; i++) {
    if (positions_of_players[i] > position_of_leader) {
      position_of_leader = positions_of_players[i];
      flag = true;
      player_in_the_lead = i;
    }
  }
  // RETURN FUNCTION IF PLAYER IS IN LAST PLACE
  if (flag == false) {
    cout << "You are the leader. Stay where you are.\n";
    return;
  }
  // SWAP POSITIONS WITH LEADER
  int temp = positions_of_players[player_in_the_lead];
  positions_of_players[player_in_the_lead] = positions_of_players[index];
  positions_of_players[index] = temp;
}


//[x] TODO: UNIT TEST FOR SWAP_FOR_LAST FUNCTION

void swap_for_last(int index, int positions_of_players[], int players) {
  int flag = false;
  int position_of_last_place = positions_of_players[index];
  int player_in_last_place = index;
    //find if there is a leading player
  for (int i=0; i<players; i++) {
    if (positions_of_players[i] < position_of_last_place) {
      flag = true;
      player_in_last_place = i;
      position_of_last_place = positions_of_players[i];
    }
  }
  // if flag remains false then the player is in the lead
  if (flag == false) {
    cout << "You are already in last. Stay where you are.\n";
    return;
  }
  // swap players position with last place
  int temp = positions_of_players[player_in_last_place];
  positions_of_players[player_in_last_place] = positions_of_players[index];
  positions_of_players[index] = temp;
}



//[x] TODO: UNIT TEST FOR START_OVER FUNCTION 

void start_over(int index, int positions_of_players[], int board[], int players) {
  board[positions_of_players[index]] = 0;
  positions_of_players[index] -= positions_of_players[index];
  display_positions_of_players(positions_of_players, players);
}


//[_] TODO: MAYBE CREATE ANOTHER FUNCTION FOR SENDING THE OTHER PERSON BACK TO 0




// [x] TODO: UNIT TEST FOR BOUNDARY_CHECK FUNCTION

bool boundry_check(int number_of_spaces_to_move, int current_player, int positions_of_players[], int SIZE_OF_BOARD) {
  if (positions_of_players[current_player] + number_of_spaces_to_move > SIZE_OF_BOARD) {
    return true;
  }
  return false;
}


//[_] TODO: UNIT TEST FOR MARK_POSITION_PLAYER_ON_BOARD FUNCTION

void move_position_of_player_on_board(int board[], int position_of_players[], int player, int number_of_spaces_to_move) {
  board[position_of_players[player] + number_of_spaces_to_move] = 1;
}

void update_position_of_player_on_scoreboard(int position_of_players[], int player, int number_of_spaces_to_move) {
  position_of_players[player] = position_of_players[player] + number_of_spaces_to_move;
}

//[x] TODO: UNIT TEST FOR SPECIAL_CONDITIONS FUNCTION

int special_conditions(int number_of_spaces_to_move, int index, int positions_of_players[], int players, int board[]) {
  switch(number_of_spaces_to_move) {
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
      swap_for_leader(index, positions_of_players, players);
      return 0;
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
      swap_for_last(index, positions_of_players, players);
      return 0;
      break;
    case 12:
      start_over(index, positions_of_players, board, players);
      return 0;
      break;
  }
}




//[_] TODO: UNIT TEST FOR PLAY_THE_GAME_AGAIN FUNCTION



//[_] TODO: UNIT TEST FOR IS_PLAYER_AT_THE_START FUNCTION

bool is_player_at_the_start(int position_of_players[], int player) {
  if (position_of_players[player] == 0) {
    return true;
  }
  return false;
}

// GAME LOOP
//FUNCTION PROTOYPES REQUIRED FOR GAME
void display_winner(int positions_of_players[], int players);
void play_the_game_again();
//[_] TODO: UNIT TEST FOR GAME FUNCTION

void game() {
  int players = get_total_players();
    /* this arrary will keep track of the player (index + 1)
    * and the position on the board where each player is at */
    
  int positions_of_players[players] = {0};

  /* Create board.
  * When a player lands on a space, we will change the space
  * from 0 to 1 to mark that a player is there */
  const int SIZE_OF_BOARD = 51;
  int board[SIZE_OF_BOARD] = {0};

  int number_of_spaces_to_move = 0;
  while(board[51] != 1) {
    for (int current_player=0; current_player<players; current_player++) {
      //LETS BEGIN BY ROLLING THE DICE
      if (is_player_at_the_start(positions_of_players, current_player)){
        number_of_spaces_to_move = first_roll();
      } else {
        number_of_spaces_to_move = roll_dice();
      }
      
      //WE WILL UPDATE SPACES TO MOVE WITH ANY SPECIAL CONDITIONS
      number_of_spaces_to_move = special_conditions(number_of_spaces_to_move, current_player, positions_of_players, players, board);
      
      //IF NUMBER OF SPACES TO MOVE IS 0 WE WILL BREAK OUT OF CONDITIONAL
      if (number_of_spaces_to_move == 0) {
        break;
      } 

      //WE WILL MOVE THE PLAYER AHEAD IF THERE IS NOT BOUNDARY ERROR OR SWAP IF PLAYER IS THERE
      if (boundry_check(number_of_spaces_to_move, current_player, positions_of_players, SIZE_OF_BOARD)==false) {
        if (check_for_player(number_of_spaces_to_move, current_player, board, positions_of_players, players)) {
          int space = positions_of_players[current_player] + number_of_spaces_to_move;
          for (int i=0; i<players; i++) {
            if (positions_of_players[i] == space) {
              int temp = positions_of_players[i];
              positions_of_players[i] = positions_of_players[current_player];
              positions_of_players[current_player] = temp;
              break;
            }
          }
        }
        else { 
          move_position_of_player_on_board(board, positions_of_players, current_player, number_of_spaces_to_move);
          update_position_of_player_on_scoreboard(positions_of_players, current_player, number_of_spaces_to_move);
        }
        
      }
      
      //WE WILL DISPLAY THE POSITIONS AFTER EACH MOVE
      display_positions_of_players(positions_of_players, players);
    }

  }
  display_winner(positions_of_players, players);
}

void play_the_game_again() {
  char decision = 'N';
  do {
    cout << "Would you like to play the game again? Press Y for YES or N for NO: ";
    cin >> decision;
    decision = toupper(decision);
    if (decision == 'Y') {
      game();
    }
  } while (decision != 'Y' || decision != 'N');

}

//[_] TODO: UNIT TEST FOR DISPLAY_WINNER FUNCTION

void display_winner(int positions_of_players[], int players) {
  for (int i=0; i<players; i++){
    if (positions_of_players[i] == 50) {
      cout << "Player " << (i + 1) << " is the winner!!!" << endl;
    }
  }
  play_the_game_again();
}

int main() {
  game();
}























