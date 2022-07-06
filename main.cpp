#include <iostream>

// Better practice to not use the below statement to avoid naming conflicts
// Using here since such a tiny project.
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
// The solutions (soln) are the base case to compare if the original values changed.
char soln[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Declared here since CPP does not have hoisting
// Defined below main fn
int checkWin();
void board();
bool isNumeric();

int main()
{
    // player will be used to determine who's turn
    // i will be used to hold match results after each selection
    // choice is choice duh
    int player = 1, i, choice;
    // This will oscillate between X and O
    char mark;

    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cin.get();
            continue;
        }

        mark = (player == 1) ? 'X' : 'O';

        for (int i = 1; i < 11; i++)
        {
             if (i == 11)
            {
                player--;
                cin.ignore();
                cin.get();
            }
            if (choice == i && square[i] == soln[i])
            {
                square[i] = mark;
                break;
            }
        }
        i = checkWin();
        player++;

    } while (i <= -1);

    board();
    if(i == 1)
    {
        cout << "==>\aPlayer " << --player << " wins!";
    } else
    {
        cout << "\aGame draw";
    }

    cin.ignore();
    cin.get();

    return (0);
}

bool isNumeric()
{

    return(1);
}

// checkWin will check all possible combos of possible wins
// 1 = winner, -1 = no winner continue, 0 = tie
// this needs to be refactored - holy hell
int checkWin()
{
    // Check Horizontals
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    // Check Verticals
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    // Check Diagonals
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
            && square[4] != '4' && square[5] != '5' && square[6] != '6'
            && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}


// board will render the board on the console
void board()
{
    // system is part of the standard library
    // passing 'cls' will clear the console screen so a new screen can re-render
    system("cls");
    // \t is used for tab
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  " << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  " << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  " << endl;

    cout << "     |     |     " << endl;
}
