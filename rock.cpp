#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Convert number to choice name
string choiceToString(int choice) {
    if (choice == 0) return "Rock";
    if (choice == 1) return "Paper";
    return "Scissors";
}

// 0 = draw, 1 = player wins, 2 = computer wins
int decideWinner(int player, int computer) {
    if (player == computer) return 0;

    if ((player == 0 && computer == 2) ||  // Rock beats Scissors
        (player == 1 && computer == 0) ||  // Paper beats Rock
        (player == 2 && computer == 1)) {  // Scissors beats Paper
        return 1;
    } else {
        return 2;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "=== Rock Paper Scissors ===" << endl;

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        int playerChoice;

        cout << "\nChoose your move:\n";
        cout << "0 -> Rock\n";
        cout << "1 -> Paper\n";
        cout << "2 -> Scissors\n";
        cout << "Enter your choice: ";
        cin >> playerChoice;

        if (playerChoice < 0 || playerChoice > 2) {
            cout << "Invalid choice. Please enter 0, 1, or 2.\n";
            continue;
        }

        int computerChoice = rand() % 3;

        cout << "You chose:      " << choiceToString(playerChoice) << endl;
        cout << "Computer chose: " << choiceToString(computerChoice) << endl;

        int result = decideWinner(playerChoice, computerChoice);

        if (result == 0) {
            cout << "Result: It's a draw!" << endl;
        } else if (result == 1) {
            cout << "Result: You win!" << endl;
        } else {
            cout << "Result: Computer wins!" << endl;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing!" << endl;
    return 0;
}
