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
#include <stdbool.h>
#include "team.h"

// -----------------------------------------------------------------------
// DO NOT CHANGE THIS REGION OF CODE
const int MAX_PLAYERS = 5;
const int TEAM_INVALID_ID = -1;
const struct team team_empty = {TEAM_INVALID_ID, 0}; // Doesn't set players to empty_player
                                                     // Must be done by team_init_empty

// DO NOT CHANGE THESE
// Reasons for failures
const int FAIL_INSUFFICIENT_FUNDS = -1;
const int FAIL_ROSTER_FULL = -2;
// END OF DO NOT CHANGE REGION

void swap(struct team* t, int min_idx, int i) {
    int temp_id = t->players[min_idx].player_id;
    int temp_val = t->players[min_idx].value;

    t->players[min_idx].player_id = t->players[i].player_id;
    t->players[min_idx].value = t->players[i].value;
    t->players[min_idx].player_id = temp_id;
    t->players[min_idx].value = temp_val;
}

// YOU MUST COMPLETE THIS FUNCTION
void team_print(const struct team* const t) {
  assert(t);
  assert(team_player_value(t) + team_cash(t) == team_value(t));
  printf("Team %d : ", team_get_id(t));
  
  struct team temp_team = {};
  temp_team.team_id = t->team_id;
  temp_team.cash_available = t->cash_available;
  temp_team.num_players = t->num_players;
  
  for (int i = 0; i < MAX_PLAYERS; i++) {
    temp_team.players[i].player_id = t->players[i].player_id;
    temp_team.players[i].value = t->players[i].value;
  }
  
  for (int i = 0; i < MAX_PLAYERS; i++)
    {
        // Find the minimum element in unsorted array
        int min_idx = i;
        for (int j = i + 1; j < MAX_PLAYERS; j++) {
          if (t->players[j].player_id < t->players[min_idx].player_id) {
            min_idx = j;
          }
        }
        if(min_idx != i) {
          swap(&temp_team, min_idx, i);
        }
    }

  for (int i = 0; i < MAX_PLAYERS; i++) {
    if (! (temp_team.players[i].player_id == PLAYER_INVALID_ID)) {
      player_print(&temp_team.players[i]);
    }
  }

  // Players must be printed from the lowest player_id to highest player_id.
  // You must NOT print players with player_id == PLAYER_INVALID_ID
  // The function you use to print the player is 
  //    player_print(player_ptr);  See player.h
  // player_print will take care of proper spacing.
  // See team_print in team.c of A5 if you need a better idea of what to do.

  printf("player value = %d cash = %d", team_player_value(t), team_cash(t));
  printf("\n");
}
// -----------------------------------------------------------------------

int team_player_value(const struct team* const t) {
  assert(t);
  assert(t->team_id != TEAM_INVALID_ID);

  int total = 0;
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t->players[i].player_id != TEAM_INVALID_ID) {
      total += t->players[i].value;
    }
  }
  return total;
}

int team_value(const struct team* const t) {
  assert(t);
  assert(t->team_id != TEAM_INVALID_ID);
  return team_player_value(t) + team_cash(t);
}

int team_cash(const struct team* const t) {
  assert(t);
  assert(t->team_id != TEAM_INVALID_ID);

  return t->cash_available;
}

void team_init_empty(struct team* const t) {
  assert(t);
  t->team_id = TEAM_INVALID_ID;
  t->num_players = 0;
  t->cash_available = 0;
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    t->players[i] = player_empty;
  }
}

void team_setup(struct team* const t, const int id, const int cash) {
  assert(t);
  assert(t->team_id == TEAM_INVALID_ID);
  assert(id >= 0);
  assert(cash >= 0);
  assert(t->num_players == 0);
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    assert(t->players[i].player_id == PLAYER_INVALID_ID);
  }

  t->team_id = id;
  t->num_players = 0;
  t->cash_available = cash;
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    t->players[i] = player_empty;
  }
}

int team_get_id(const struct team* const t) {
  assert(t);
  return t->team_id;
}

bool team_is_player_on(const struct team* const t, const int id) {
  assert(t);
  assert(t->team_id != TEAM_INVALID_ID);
  assert(id >= 0);

  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t->players[i].player_id == id) {
      return true;
    }
  }

  return false;
}

bool team_add_player(struct team* const t, const int id, const int val,
   struct reason *r) {
  assert(t);
  assert(r);
  assert(t->team_id != TEAM_INVALID_ID);
  assert(id >= 0);
  assert(val >= 0);
  assert(!team_is_player_on(t, id));

  //check if roster is full
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t->players[i].player_id == PLAYER_INVALID_ID) {
      break;
    } else if (i == MAX_PLAYERS - 1) {
      r->code = FAIL_ROSTER_FULL;
      r->team_num = t->team_id;
      return false;
    }
  }

  //check if team has enough cash
  if (t->cash_available < val) {
    r->code = FAIL_INSUFFICIENT_FUNDS;
    r->team_num = t->team_id;
    return false;
  }

  // add player to team
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t->players[i].player_id == PLAYER_INVALID_ID) {
      t->players[i].player_id = id;
      t->players[i].value = val;
      break;
    }
  }

  t->cash_available -= val;

  return true;
}

bool team_sell_player(struct team* const t1, const int id,
     struct team* const t2, struct reason *r) {
  assert(t1);
  assert(t2);
  assert(r);
  assert(t1->team_id != TEAM_INVALID_ID);
  assert(t2->team_id != TEAM_INVALID_ID);
  assert(id >= 0);
  assert(team_is_player_on(t1, id));
  assert(!team_is_player_on(t2, id));
  assert(t1->team_id != t2->team_id);

  int player_value = 0;
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t1->players[i].player_id == id) {
      player_value = t1->players[i].value;
      break;
    }
  }

  if (!team_add_player(t2, id, player_value, r)) {
    return false;
  } else {
    t1->cash_available += player_value;
    for (int i = 0; i < MAX_PLAYERS; ++i) {
      if (t1->players[i].player_id == id) {
        t1->players[i] = player_empty;
        break;
        }
    }
    return true;
  }
}

bool team_trade_players(struct team* const t1, const int id1,
     struct team* const t2, const int id2, struct reason *r) {
  assert(t1);
  assert(t2);
  assert(r);
  assert(t1->team_id != TEAM_INVALID_ID);
  assert(t2->team_id != TEAM_INVALID_ID);
  assert(id1 >= 0);
  assert(id2 >= 0);
  assert(team_is_player_on(t1, id1));
  assert(team_is_player_on(t2, id2));
  assert(!team_is_player_on(t2, id1));
  assert(!team_is_player_on(t1, id2));
  assert(t1->team_id != t2->team_id);

  int t1_player_value = 0;
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t1->players[i].player_id == id1) {
      t1_player_value = t1->players[i].value;
      break;
    }
  }

  int t2_player_value = 0;
  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t2->players[i].player_id == id2) {
      t2_player_value = t2->players[i].value;
      break;
    }
  }

  if (t1->cash_available + t1_player_value < t2_player_value) {
    r->code = FAIL_INSUFFICIENT_FUNDS;
    r->team_num = t1->team_id;
    return false;
  } else if (t2->cash_available + t2_player_value < t1_player_value) {
    r->code = FAIL_INSUFFICIENT_FUNDS;
    r->team_num = t2->team_id;
    return false;
  }

  int temp_id = id1;
  int temp_val = t1_player_value;

  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t1->players[i].player_id == id1) {
      t1->players[i].player_id = id2;
      t1->players[i].value = t2_player_value;
      break;
    }
  }

  for (int i = 0; i < MAX_PLAYERS; ++i) {
    if (t2->players[i].player_id == id2) {
      t2->players[i].player_id = temp_id;
      t2->players[i].value = temp_val;
      break;
    }
  }
  
  if (t1_player_value >= t2_player_value) {
    t1->cash_available += (t1_player_value - t2_player_value);
    t2->cash_available -= (t1_player_value - t2_player_value);
  } else {
    t2->cash_available += (t2_player_value - t1_player_value);
    t1->cash_available -= (t2_player_value - t1_player_value);
  }

  return true;
}