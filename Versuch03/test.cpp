/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include "config.h"
#include "main.h"

#include <iostream>

#define NUMBER_TESTS_WINNER 5

extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

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
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code)
{
    std::cout << "Running test for 'winner'..." << std::endl;
    std::cout << "----------------------------" << std::endl;
    show_field(field);
    std::cout << "Checking who wins" << std::endl;

    //Call winner-function

    /* Check if result of winner function is correct and what you expected
     *
     * Return true for correct and false for wrong
     *
     * also print to the console if test was passed or not
     */

    bool result = winner(field) == winner_code;
    std::cout << "Test passed? " << (result ? "yes" : "no") << std::endl;
    return result;
}

bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y, const bool valid)
{
    // check for a given field whether a turn is valid
    return 0;
}

bool test_execute_turn(int input[SIZE_Y][SIZE_X],
        const int output[SIZE_Y][SIZE_X], const int player, const int pos_x,
        const int pos_y)
{
    // check for a given field whether the execution of a turn is valid
    return 0;
}

bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
        const int count_possible_turns)
{
    // very if your function finds all possible turns
    return 0;
}

bool run_full_test(void)
{
    bool result = true;

// ---------- CHECK WINNER ---------- //

    int winner_matrix[5][8][8] =
    {
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 2, 0, 0, 0, 2, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0, 2, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } } };

    int winner_code[NUMBER_TESTS_WINNER] =
    { 1, 2, 1, 1, 0 };

    for (int i = 0; i < NUMBER_TESTS_WINNER; i++)
    {
        bool passed = test_winner(winner_matrix[i], winner_code[i]);
        std::string msg = passed ? "Yes" : "No";
        std::cout << "Matrix " << i << " passed? " << msg << std::endl;

        // if tests fail, make sure to report the error
        if (!passed)
        {
            result = false;
        }
    }

// ---------- CHECK TURN VALID ---------- //

    int turnvalid_matrix[6][8][8] =
    {
    {
    { 1, 0, 2, 0, 0, 1, 1, 1 },
    { 0, 0, 2, 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 0, 1, 2, 2 },
    { 2, 2, 0, 2, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 2, 0 },
    { 0, 0, 0, 2, 1, 1, 0, 2 },
    { 1, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 1 } },

    {
    { 1, 0, 2, 0, 0, 1, 1, 1 },
    { 0, 0, 2, 0, 0, 1, 0, 0 },
    { 0, 0, 2, 0, 0, 2, 1, 1 },
    { 0, 0, 0, 2, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 2, 0 },
    { 0, 0, 0, 2, 1, 1, 0, 2 },
    { 1, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 1 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 1, 0, 0, 2, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0 },
    { 2, 0, 1, 2, 0, 2, 0, 0 },
    { 0, 2, 0, 2, 2, 2, 2, 2 },
    { 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 0, 2, 2, 2 },
    { 0, 2, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 1, 1, 1, 0, 0 } },

    {
    { 2, 1, 0, 0, 2, 1, 1, 1 },
    { 0, 2, 0, 0, 0, 0, 0, 0 },
    { 1, 0, 0, 2, 0, 0, 0, 1 },
    { 0, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 0, 0, 1, 1, 0, 0, 2 },
    { 0, 0, 0, 0, 0, 0, 0, 1 },
    { 1, 1, 0, 0, 0, 0, 2, 0 },
    { 1, 1, 2, 0, 0, 2, 2, 1 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } } };

    int turnvalid_player[6] =
    { 1, 2, 2, 1, 2, 1 };
    int turnvalid_pos[6][2] =
    {
    { 2, 3 },
    { 0, 3 },
    { 4, 3 },
    { 3, 4 },
    { 3, 5 },
    { 3, 4 } };
    bool turnvalid_valid[6] =
    { 0, 0, 0, 1, 1, 0 };

    for (int i = 0; i < 6; i++)
    {
        // TODO: Call the check function
    }

// ---------- CHECK EXECUTE TURN ---------- //

    int executeturn_matrix_in[9][8][8] =
    {
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 2, 2 },
    { 2, 2, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 1, 1 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 2, 0, 2, 0, 0 },
    { 0, 0, 0, 2, 2, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 1, 0 },
    { 0, 0, 0, 2, 0, 2, 0, 0 },
    { 0, 0, 0, 2, 2, 0, 0, 0 },
    { 0, 1, 2, 0, 2, 2, 1, 0 },
    { 0, 0, 0, 2, 2, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 2, 1 },
    { 1, 0, 1, 1, 2, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } } };

    int executeturn_matrix_out[9][8][8]
    {
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 2, 2 },
    { 2, 2, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 1, 1 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 2, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 2, 0, 1, 0, 0 },
    { 0, 0, 0, 2, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 1, 0, 0 },
    { 0, 0, 0, 2, 1, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 1, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 2, 0, 0 },
    { 0, 0, 0, 0, 2, 0, 0, 0 },
    { 0, 0, 0, 2, 0, 0, 0, 0 },
    { 0, 0, 2, 1, 1, 1, 1, 0 },
    { 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 2, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 0, 0, 0, 0, 2, 1 },
    { 1, 2, 2, 2, 2, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } } };

    int executeturn_player[9] =
    { 0, 0, 0, 1, 2, 0, 1, 2, 2 };
    int executeturn_pos[9][2] =
    {
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 3, 4 },
    { 3, 5 },
    { 0, 0 },
    { 3, 4 },
    { 2, 4 },
    { 1, 4 } };

    for (int i = 0; i < 9; i++)
    {
        // TODO: Call the check function
    }

// ---------- CHECK POSSIBLE TURNS ---------- //

    int possibleturns_matrix[2][8][8]
    {
    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 2, 0, 0, 0 },
    { 0, 0, 0, 2, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } },

    {
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 2, 1, 0, 0, 0 },
    { 0, 0, 0, 2, 1, 1, 0, 0 },
    { 0, 0, 0, 2, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0 } } };

    int possibleturns_player[2] =
    { 1, 1 };
    int possibleturns_count[2] =
    { 4, 5 };

    for (int i = 0; i < 2; i++)
    {
        // TODO: Call the check function
    }

    return result;
}
