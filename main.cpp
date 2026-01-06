#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

// Function prototypes (defined in other .cpp files)
void playColoredSquares();
void playCatchTheBall();
void playRockPaperScissors();

int main() {
    int choice;
    do {
        system("cls");
        cout << "\n======= GameHub: Mini Game Collection =======\n";
        cout << "1. Colored Squares\n";
        cout << "2. Catch the Ball\n";
        cout << "3. Rock Paper Scissors\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: playColoredSquares(); break;
            case 2: playCatchTheBall(); break;
            case 3: playRockPaperScissors(); break;
            case 4: cout << "Thanks for playing!\n"; break;
            default: cout << "Invalid choice.\n"; Sleep(1000);
        }

        if (choice != 4) {
            cout << "\nPress any key to return to menu...";
            cin.ignore(); cin.get();
        }

    } while (choice != 4);

    return 0;
}

