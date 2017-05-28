/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

#ifndef MAIN_H_
#define MAIN_H_

/**
 * @brief Constant used to define the player type as human.
 */
#define HUMAN 1

/**
 * @brief Constant used to define the player type as computer.
 */
#define COMPUTER 2

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X]);

/**
 * @brief Prints the playing field to the console.
 *
 * This function gets the current playing field as parameter (two dimensional array)
 * with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
 * <br>The function prints the playing field, grid included, to the console.
 * Crosses symbolize player 1 while circles symbolize player 2.
 *
 *  @param field  The field which is going to be printed
 */
void show_field(const int field[SIZE_Y][SIZE_X]);

/**
 * @brief Calculates the winner based on the current field state.
 *
 * This function gets the current field passed as an parameter. Each position within
 * the playing field can hold one of the following values:
 * <ul>
 *  <li>0 - The position is empty and doesn't belong to any player.</li>
 *  <li>1 - The position belongs to player 1.</li>
 *  <li>2 - The position belongs to player 2.</li>
 * </ul>
 * The result is calculated by simply summing up all entries for each player.
 * The returning integer will either be <b>1</b> if player 1 has more entries,
 * <b>2</b> if player 2 has more entries or <b>0</b> if the current field state
 * is a draw.
 *
 * @param field The current playing field.
 * @return An integer between 0 - 2.
 */
int winner(const int field[SIZE_Y][SIZE_X]);

bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y);

void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
        const int pos_y);

int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

bool human_turn(int field[SIZE_Y][SIZE_X], const int player);

int do_turn(int field[SIZE_Y][SIZE_X], const int player, const int player_type);

void game(const int player_typ[2]);

int main();

#endif /* MAIN_H_ */
