#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int winner(string y, string c) {
    if (y == c) return -1;
    if (y == "Rock" && c == "Scissor") return 1;
    if (y == "Scissor" && c == "Paper") return 1;
    if (y == "Paper" && c == "Rock") return 1;
    return 0;
}

void displayRPSRules() {
    cout << "----------------------------\n";
    cout << "Rock Paper Scissors Rules:\n";
    cout << "- Rock crushes Scissors\n";
    cout << "- Scissors cuts Paper\n";
    cout << "- Paper covers Rock\n";
    cout << "----------------------------\n";
}

void playRockPaperScissors() {
    srand(time(0));
    string name;
    cout << "Enter your name: ";
    cin.ignore(); getline(cin, name);
    int score = 0;
    char input;

    do {
        system("cls");
        displayRPSRules();
        int choice;
        string userMove, compMove;
        cout << "\n1) Rock\n2) Paper\n3) Scissor\n";
        cout << "Enter your move: ";
        cin >> choice;

        if (choice == 1) userMove = "Rock";
        else if (choice == 2) userMove = "Paper";
        else if (choice == 3) userMove = "Scissor";
        else { cout << "Invalid input.\n"; continue; }

        int comp = rand() % 3 + 1;
        if (comp == 1) compMove = "Rock";
        else if (comp == 2) compMove = "Paper";
        else compMove = "Scissor";

        cout << "Computer chose: " << compMove << endl;

        int result = winner(userMove, compMove);
        if (result == 1) {
            cout << "?? You Win!\n"; score++;
        } else if (result == 0) {
            cout << "? You Lose!\n";
        } else {
            cout << "?? It's a Draw.\n";
        }

        cout << "Play again? (y/n): ";
        cin >> input;
    } while (input == 'y' || input == 'Y');

    cout << name << ", your final score is: " << score << endl;
}

