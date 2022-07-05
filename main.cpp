#include <iostream>

// Better practice to not use the below statement to avoid naming conflicts
// Using here since such a tiny project.
using namespace std;

char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Declared here since CPP does not have hoisting
// Defined below main fn
int checkWin();
void board();

int main()
{
    return (0);
}

// checkWin will check all possible combos of possible wins
// 1 = winner, -1 = no winner continue, 0 = tie

// board will render the board on the console
