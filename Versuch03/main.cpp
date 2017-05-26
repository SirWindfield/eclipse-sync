/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
 * @mainpage Reversi
 *
 * Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
 *
 */

/**Defines the type of a player */
#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
    for (int j = 0; j < SIZE_Y; j++)
    {
        for (int i = 0; i < SIZE_X; i++)
        {
            field[j][i] = 0;
        }
    }
    field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
    field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
    field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
    field[SIZE_Y / 2][SIZE_X / 2] = 1;
}

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
void show_field(const int field[SIZE_Y][SIZE_X])
{
    std::cout << "  ";

//Start at ASCII 65 = A
    for (int j = 65; j < 65 + SIZE_Y; j++)
        std::cout << ((char) j) << " ";

    std::cout << std::endl;

    for (int j = 0; j < SIZE_Y; j++)
    {
        std::cout << j + 1;
        for (int i = 0; i < SIZE_X; i++)
        {
            switch (field[j][i])
            {
            case 0:
                std::cout << "  ";
                break;
            case 1:
                std::cout << " X";
                break;
            case 2:
                std::cout << " O";
                break;
            default:
                std::cout << "Inconsistent data in field!" << std::endl;
                std::cout << "Aborting .... " << std::endl;
                exit(0);
                break;
            }
        }; //for i
        std::cout << std::endl;
    } //for j
}

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
int winner(const int field[SIZE_Y][SIZE_X])
{
    int count_p1 = 0;
    int count_p2 = 0;

    for (int j = 0; j < SIZE_Y; j++)
    {
        for (int i = 0; i < SIZE_X; i++)
        {
            if (field[j][i] == 1)
            {
                count_p1++;
            } else if (field[j][i] == 2)
            {
                count_p2++;
            }
        }
    }
    if (count_p1 == count_p2)
    {
        return 0;
    }
    if (count_p2 > count_p1)
    {
        return 2;
    } else
    {
        return 1;
    }
}

/**
 *
 */
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
        const int pos_x, const int pos_y)
{
    // Process all possible directions
    int opponent = 3 - player;
    // the same as: if player = 1 -> opponent = 2 else
    // if player = 2 -> opponent = 1

    if (field[pos_y][pos_x] != 0) //check if field is currently empty
    {
        return false;
    }

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            //check if you can find an opponents stone in a neighboring field
            //then check if in this direction all stones are opponent stones until
            //the line is terminated by one of your own stone
            //in that case return true otherwise not

            if (field[pos_y + j][pos_x + i] == opponent)
            {
                // ignore the first found enemy stone -> 2
                int path_length = 2;
                // the current position of the stone that we'll check
                int next_x = pos_x + path_length * i;
                int next_y = pos_y + path_length * j;

                // as long as the bounds are valid, continue the check
                bool work = true;
                while (work && within_bounds(next_x, next_y))
                {
                    int stone = field[next_y][next_x];
                    if (stone == 0)
                    {
                        // stop looking for other stones once we reached an empty spot
                        work = false;
                    } else if (stone == player)
                    {
                        return true;
                    }
                    // increment path length to get to the next stone
                    path_length++;
                    // update coordinates according to new path length
                    next_x = pos_x + path_length * i;
                    next_y = pos_y + path_length * j;
                }
            }
        }
    }
    return false;
}

/**
 *
 */
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
        const int pos_y)
{
    // Process all possible directions
    int opponent = 3 - player;
    // the same as: if player = 1 -> opponent = 2 else
    // if player = 2 -> opponent = 1
    if (field[pos_y][pos_x] != 0)
    {
        return;
    }

    field[pos_y][pos_x] = player;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            //check if you can find an opponents stone in a neighboring field
            //then check if in this direction all stones are opponent stones until
            //the line is terminated by one of your own stone
            //in that case return true otherwise not

            if (field[pos_y + j][pos_x + i] == opponent)
            {
                int path_length = 2;
                // the current position of the stone that we'll check
                int next_x = pos_x + path_length * i;
                int next_y = pos_y + path_length * j;

                // as long as the bounds are valid, continue the check
                bool work = true;
                while (work && within_bounds(next_x, next_y))
                {
                    int stone = field[next_y][next_x];
                    if (stone == 0)
                    {
                        work = false;
                    } else if (stone == player)
                    {
                        for (int stones = path_length - 1; stones > 0; stones--)
                        {
                            field[pos_y + stones * j][pos_x + stones * i] =
                                    player;
                        }
                        work = false;
                    }
                    // increment path length to get to the next stone
                    path_length++;
                    // update coordinates according to new path length
                    next_x = pos_x + path_length * i;
                    next_y = pos_y + path_length * j;
                }
            }
        }
    }
}

/**
 *
 */
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
    int turns = 0;
    for (int i = 0; i < SIZE_X; i++)
    {
        for (int j = 0; j < SIZE_Y; j++)
        {
            if (turn_valid(field, player, i, j))
            {
                turns++;
            }
        }
    }
    return turns;
}

bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
    if (possible_turns(field, player) == 0)
    {
        return false;
    }

    int px;
    int py;
    // bool repeat = false; not used

    while (true)
    {
        std::string input;
        input.reserve(50);
        std::cout << std::endl << "Your move (e.g. A1): ";
        input.erase(input.begin(), input.end());
        std::cin >> input;
        px = ((int) input.at(0)) - 65;
        py = ((int) input.at(1)) - 49;

        if (turn_valid(field, player, px, py))
        {
            std::cout << "turn is actually valid" << std::endl;
            //accept turn;
            break;
        } else
        {
            std::cout << std::endl << "Invalid input !" << std::endl;
        }
    }

    execute_turn(field, player, px, py);

    return true;
}

/**
 *
 */
int do_turn(int field[SIZE_Y][SIZE_X], const int player, const int player_type)
{
    int moves = possible_turns(field, player);
    if (moves > 0)
    {
        switch (player_type)
        {
        case HUMAN:
            human_turn(field, player);
            break;
        case COMPUTER:
            computer_turn(field, player);
            break;
        }

        show_field(field);
    }
    return moves;
}

/**
 *
 */
void game(const int player_typ[2])
{
    int field[SIZE_Y][SIZE_X];

    //Create starting pattern
    initialize_field(field);

    int current_player = 1;
    show_field(field);

    // stores the last player's possible turns
    int priorTurns = 0;
    // used to break the loop
    bool playing = true;
    while (playing)
    {
        int moves = do_turn(field, current_player,
                player_typ[current_player - 1]);
        if (moves == 0 && priorTurns == 0)
        {
            // stop the game
            playing = false;
        }
        // toggle between players
        current_player = current_player == 1 ? 2 : 1;
        priorTurns = moves;
    }

    switch (winner(field))
    {
    case 0:
        std::cout << "The game ended in a draw." << std::endl;
        break;
    case 1:
        std::cout << "Player 1 wins!" << std::endl;
        break;
    case 2:
        std::cout << "Player 2 wins!" << std::endl;
        break;
    }
}

/**
 *
 */
int main(void)
{
    if (TEST == 1)
    {
        bool result = run_full_test();
        if (result == true)
        {
            std::cout << "ALL TESTS PASSED!" << std::endl;
        } else
        {
            std::cout << "TEST FAILED!" << std::endl;
        }
    }

    int player_type[2] =
    { COMPUTER, COMPUTER }; //Contains information whether players are HUMAN(=1) or COPMUTER(=2)
    game(player_type);
    return 0;
}
