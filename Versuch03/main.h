/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "config.h"

/**
 * Constant used to define the player type as human.
 */
#define HUMAN 1

/**
 * Constant used to define the player type as computer.
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

/**
 * @brief Returns whether a move by the passed player is considered valid.
 *
 * A move is only valid if the placed stone is enclosing enemy pieces, resulting in
 * the player receiving points. Stones can only be put on empty spaces.
 * The result is calculated by checking each neighbor stone. If any of them is an enemy
 * stone, the function will check all stones in a straight line until it can find
 * another player's stone. If so, the turn is considered valid.
 *
 * @param field The current playing field.
 * @param player The player trying to make a move.
 * @param pos_x The x-coordinate of the point.
 * @param pos_y The y-coordinate of the point.
 * @return <b>True</b> if the turn is considered valid, <b>false</b> otherwise.
 */
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y);

/**
 * @brief Executes a turn based on the given player and position.
 *
 * A turn consists of two steps:
 * <ul>
 * 	<li>1. Checking what stones can get turned around</li>
 * 	<li>2. Turning all possible stones around.</li>
 * </ul>
 * This is done by checking each neighbor stone. If any of them is an enemy
 * stone, the function will check all stones in a straight line until it can find
 * another player's stone. All stones in that line will then get turned around.
 *
 * @param field The current playing field.
 * @param player The player who is making the move.
 * @param pos_x The x-coordinate of the point.
 * @param pos_y The y-coordinate of the point.
 */
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
        const int pos_y);

/**
 * @brief Calculates the possible turns of the given player.
 *
 * This function checks whether every empty field is a valid turn for the given player.
 *
 * @param field The current playing field.
 * @param player The player who trying to make a move.
 * @return The number of possible turns.
 */
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

/**
 * @brief Takes the user input and executes the given turn.
 *
 * The stone's position is entered using a grid system where A1 is the upper left and
 * H8 is the lower right corner.
 *
 * @param field The current playing field.
 * @param player The current player.
 * @return <b>True</b> if the given player made a move, <b>false</b> otherwise.
 */
bool human_turn(int field[SIZE_Y][SIZE_X], const int player);

/**
 * @brief Executes a turn based on the player type.
 *
 * The given player type can either be a COMPUTER or HUMAN. This function will then
 * call all needed sub-routines responsible for making the actual move.
 *
 * @param field The current playing field.
 * @param player The current player.
 * @param player_type The current player type.
 * @return The number of possible turns that the given player had the choice between.
 */
int do_turn(int field[SIZE_Y][SIZE_X], const int player, const int player_type);

/**
 * @brief The main method of the game.
 *
 * This function will initialize a new field and keep the game up until no valid turns
 * are possible for both players. It then announces the winner in the console.
 * The player types can be any combination of COMPUTER and HUMAN.
 *
 * @param player_typ The player type configuration.
 */
void game(const int player_typ[2]);

/**
 * @brief Application entry point.
 *
 * The main method will initialize a new game and start it.
 * @return <b>0</b> if the program exits successfully, other numbers if not.
 */
int main();

#endif /* MAIN_H_ */
