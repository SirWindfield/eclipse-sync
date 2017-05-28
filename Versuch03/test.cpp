/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include "config.h"

#include <iostream>

extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

bool within_bounds(const int x, const int y)
{
    // either x or y needs to be invalid
    if (x < 0 || x >= SIZE_X)
    {
        return false;
    } else if (y < 0 || y >= SIZE_Y)
    {
        return false;
    }
    return true;
}

bool same_as(int field[SIZE_Y][SIZE_X], const int other[SIZE_Y][SIZE_X])
{
    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            if (field[i][j] != other[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

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
    return turn_valid(field, player, pos_x, pos_y) == valid;
}

bool test_execute_turn(int input[SIZE_Y][SIZE_X],
        const int output[SIZE_Y][SIZE_X], const int player, const int pos_x,
        const int pos_y)
{
    // check for a given field whether the execution of a turn is valid
    show_field(input);
    execute_turn(input, player, pos_x, pos_y);
    return same_as(input, output);
}

bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
        const int count_possible_turns)
{
    // verify if your function finds all possible turns
    std::cout << possible_turns(field, player);
    return possible_turns(field, player) == count_possible_turns;
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
        std::cout << "Winner " << i << " passed? " << msg << std::endl;

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
        bool passed = test_turn_valid(turnvalid_matrix[i], turnvalid_player[i],
                turnvalid_pos[i][0], turnvalid_pos[i][1], turnvalid_valid[i]);
        std::string msg = passed ? "Yes" : "No";
                std::cout << "Valid turns  " << i << " passed? " << msg << std::endl;
        if (!passed)
        {
            result = false;
        }
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
        execute_turn(executeturn_matrix_in[i], executeturn_player[i],
                executeturn_pos[i][0], executeturn_pos[i][1]);
        // compare out to res
        bool passed = same_as(executeturn_matrix_in[i],
                executeturn_matrix_out[i]);
        std::string msg = passed ? "Yes" : "No";
                std::cout << "Executable turns  " << i << " passed? " << msg << std::endl;
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
        bool passed = test_possible_turns(possibleturns_matrix[i],
                possibleturns_player[i], possibleturns_count[i]);
        std::string msg = passed ? "Yes" : "No";
        std::cout << "Possible turns  " << i << " passed? " << msg << std::endl;
        if (!passed)
        {
            result = false;
        }
    }

    return result;
}
