/**
 * @file test.h
 *
 * Provides various functions for testing the program.
 */
#ifndef TEST_H_
#define TEST_H_

/**
 * The number of tests run for the test_winner function.
 */
#define NUMBER_TESTS_WINNER 5

/**
 * @brief Checks if the passed coordinates are within the bounds of the playing field.
 *
 * This is done by checking that the given coordinates are between 1 and SIZE_X for the x
 * coordinate and 1 and SIZE_Y for the y coordinate.
 *
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return True if the point is within the playing field, false otherwise.
 */
bool within_bounds(const int x, const int y);

/**
 * @brief Compares two playing fields and checks if they are the same.
 *
 * This is done by comparing points at the same position of both fields.
 * Points are considered to be the same if their state is the same, meaning that either
 * the same player has to have a stone on that point.
 *
 * @param field One of the fields that will be used for the comparison.
 * @param other THe other field used for the comparison.
 * @return True if both fields are the same, false otherwise.
 */
bool same_as(int field[SIZE_Y][SIZE_X], const int other[SIZE_Y][SIZE_X]);

/**
 * @brief Checks if the expected winner is actually the winner of the passed field.
 *
 * This function is used for unit testing and makes sure that the winner function works
 * properly.
 * The first argument is the actual field state whereas the second one will be the expected
 * winner. The check is done by comparing the result of the winner function
 * with the expected winner.
 * The function will then return a boolean value based on the comparison's result.
 *
 * @param field The current field state that should be used for unit testing
 * @param winner_code The expected winner that results from the field.
 * @return <b>True</b> If the check has been successful, <b>false</b> otherwise.
 */
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code);

/**
 * @brief Checks if the given player can actually play at the given position.
 *
 * This function is used for unit testing and makes sure that the turn_valid function works
 * properly.
 * The first argument is the actual field state whereas the second one will be the player
 * trying to place a stone at the given position, defined by pos_x and pos_y.
 * The check is done by comparing the result of the turn_valid function
 * with the expected one.
 * The function will then return a boolean value based on the comparison's result.
 *
 * @param field The current field state that should be used for unit testing
 * @param player The player that will execute the turn.
 * @param pos_x The x-coordinate of the point.
 * @param pos_y The y-coordinate of the point.
 * @param valid The expected value that the turn_valid function should return.
 * @return <b>True</b> If the check has been successful, <b>false</b> otherwise.
 */
bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y, const bool valid);

/**
 * @brief Checks if the given player's stone has been properly placed at the given position.
 *
 * This function is used for unit testing and makes sure that the execute_turn function works
 * properly.
 * The first argument is the actual field state whereas the second one will be the player
 * trying to place a stone at the given position, defined by pos_x and pos_y.
 * The check is done by comparing the result of the execute_turn function
 * with the expected field's state, passed as argument output.
 * The function will then return a boolean value based on the comparison's result.
 *
 * @param field The current field state that should be used for unit testing
 * @param player The player that will execute the turn.
 * @param pos_x The x-coordinate of the point.
 * @param pos_y The y-coordinate of the point.
 * @param other The expected field state after the move has been done.
 * @return <b>True</b> If the check has been successful, <b>false</b> otherwise.
 */
bool test_execute_turn(int input[SIZE_Y][SIZE_X],
        const int output[SIZE_Y][SIZE_X], const int player, const int pos_x,
        const int pos_y);

/**
 * @brief Checks if the calculated possible turns are the same as the expected ones.
 *
 * This function is used for unit testing and makes sure that the execute_turn function works
 * properly.
 * The first argument is the actual field state whereas the second one will be the player.
 * The check is done by comparing the result of the possible_turns function
 * with the expected count, passed as argument.
 * The function will then return a boolean value based on the comparison's result.
 *
 * @param field The current field state that should be used for unit testing
 * @param player The player that will execute the turn.
 * @param count_possible_turns The actual expected turns that the player can do.
 * @return <b>True</b> If the check has been successful, <b>false</b> otherwise.
 */
bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
        const int count_possible_turns);

/**
 * @brief Runs all tests consecutively.
 *
 * This method calls
 */
bool run_full_test(void);

#endif /* TEST_H_ */
