/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Name: Ken Wu
// login ID: 20999205
//////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <assert.h>
#include "cs136-trace.h"
#include "team.h"

//////////////////////////////////////////////////////////////////////////////////////////
// These definitions are used to control testing.
const int MAX_TEAMS = 4;

// -----------------------------------------------------------------------
// DO NOT CHANGE THIS REGION OF CODE

// print_reason(r) prints information about the reason for a failure
//    as indicated in the structure r.
// requires: r is a valid pointer to a reason
//           The reason code is either FAIL_INSUFFICIENT_FUNDS or FAIL_ROSTER_FULL
// effects: produces output

void print_reason(const struct reason* const r) {
  assert(r);
  assert(r->code == FAIL_INSUFFICIENT_FUNDS || r->code == FAIL_ROSTER_FULL);
  if (r->code == FAIL_INSUFFICIENT_FUNDS) {
    printf("Team %d doesn't have enough money\n", r->team_num);
  } else if (r->code == FAIL_ROSTER_FULL) {
    printf("Team %d has a full roster\n", r->team_num);
  } 
}
// END OF DO NOT CHANGE REGION
//////////////////////////////////////////////////////////////////////////////////////////


void do_io_tests(void) {
  int command;
  int TEAM = lookup_symbol("team");
  int ADD_PLAYER = lookup_symbol("add_player");
  int TRADE_PLAYERS = lookup_symbol("trade_players");
  int SELL_PLAYER = lookup_symbol("sell_player");
  int IS_ON = lookup_symbol("is_on");
  int PRINT = lookup_symbol("print");

  
  struct reason r = {};
  struct team teams[4] = {};

  for (int i = 0; i < MAX_TEAMS; ++i) {
    team_init_empty(&teams[i]);
  }

  while (true) {
    command = read_symbol();
    
    if (command == INVALID_SYMBOL) {
      break;
    } 

    if (command == TEAM) {
      int id;
      scanf("%d", &id);
      
      int cash;
      scanf("%d", &cash);

      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == TEAM_INVALID_ID) {
          team_setup(&teams[i], id, cash);
          break;
        } else if (i == MAX_TEAMS - 1) {
          printf("Teams are all initialized\n");
        }
      }
    } else if (command == ADD_PLAYER) {
      int team_id;
      scanf("%d", &team_id);
      
      int player_id;
      scanf("%d", &player_id);
      
      int player_val;
      scanf("%d", &player_val);

      struct team *selected_team;
      
      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == team_id) {
          selected_team = &teams[i];
        }
      }

      if (!team_add_player(selected_team, player_id, player_val, &r)) {
        printf("add_player failed : ");
        print_reason(&r);
      }

    } else if (command == IS_ON) {
      int team_id;
      scanf("%d", &team_id);
      
      int player_id;
      scanf("%d", &player_id);

      struct team *selected_team;
      
      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == team_id) {
          selected_team = &teams[i];
        }
      }

      if (team_is_player_on(selected_team, player_id)) {
        printf("Player %d is on team %d\n", player_id, team_id);
      } else {
        printf("Player %d is not on team %d\n", player_id, team_id);
      }
    } else if (command == SELL_PLAYER) {
      int team1_id;
      scanf("%d", &team1_id);
      
      int player_id;
      scanf("%d", &player_id);
      
      int team2_id;
      scanf("%d", &team2_id);

      struct team *selected_team1;
      
      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == team1_id) {
          selected_team1 = &teams[i];
        }
      }

      struct team *selected_team2;
      
      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == team2_id) {
          selected_team2 = &teams[i];
        }
      }

      if (!team_sell_player(selected_team1, player_id, selected_team2, &r)) {
        printf("sell_player failed : ");
        print_reason(&r);
      }
    } else if (command == TRADE_PLAYERS) {
      int team1_id;
      scanf("%d", &team1_id);
      
      int player1_id;
      scanf("%d", &player1_id);
      
      int team2_id;
      scanf("%d", &team2_id);

      int player2_id;
      scanf("%d", &player2_id);

      struct team *selected_team1;
      
      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == team1_id) {
          selected_team1 = &teams[i];
        }
      }

      struct team *selected_team2;
      
      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == team2_id) {
          selected_team2 = &teams[i];
        }
      }

      if (!team_trade_players(selected_team1, player1_id, selected_team2, player2_id, &r)) {
        printf("trade_players failed : ");
        print_reason(&r);
      }
    } else if (command == PRINT) {
      int team_id;
      scanf("%d", &team_id);

      struct team *selected_team;
      
      for (int i = 0; i < MAX_TEAMS; ++i) {
        if (teams[i].team_id == team_id) {
          selected_team = &teams[i];
        }
      }

      team_print(selected_team);
    }

  // Possible messages for team command (nothing is printed if successful)
  //   "Teams are all initialized\n"

  // Possible messages for is_on command
  //   "Player %d is on team %d\n"
  //   "Player %d is not on team %d\n"

  // Possible messages for add_player command (nothing is printed if successful)
  //   "add_player failed : " 
  //    followed by calling print_reason to print the reason for the failure

  // Possible messages for sell_player command (nothing is printed if successful)
  //   "sell_player failed : "
  //    followed by calling print_reason to print the reason for the failure

  // Possible messages for trade_players command (nothing is printed if successful)
  //   "trade_players failed : "
  //    followed by calling print_reason to print the reason for the failure
  }
}

int main(void) {
  // DO NOT CHANGE THE CODE BELOW THIS LINE
  do_io_tests();
}