#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

enum Color { RED, GREEN, BLUE, YELLOW, PURPLE };

Color generateRandomColor() {
    return static_cast<Color>(rand() % 5);
}

string colorToString(Color color) {
    switch (color) {
        case RED: return "Red";
        case GREEN: return "Green";
        case BLUE: return "Blue";
        case YELLOW: return "Yellow";
        case PURPLE: return "Purple";
        default: return "Unknown";
    }
}

void playColoredSquares() {
    srand(time(0));
    Color targetColor = generateRandomColor();
    string guess;

    while (true) {
        system("cls");
        cout << "Welcome to the Colored Square Game!\n";
        cout << "***********************************\n";
        cout << "Guess the color (Red, Green, Blue, Yellow, Purple): ";
        cin >> guess;

      for (int i = 0; i < guess.length(); ++i) {
    guess[i] = tolower(guess[i]);
}


        Color userColor;
        if (guess == "red") userColor = RED;
        else if (guess == "green") userColor = GREEN;
        else if (guess == "blue") userColor = BLUE;
        else if (guess == "yellow") userColor = YELLOW;
        else if (guess == "purple") userColor = PURPLE;
        else {
            cout << "Invalid color. Try again.\n";
            Sleep(1000);
            continue;
        }

        if (userColor == targetColor) {
            cout << "\n?? Congratulations! You guessed correctly.\n";
            break;
        } else {
            cout << "? Wrong guess. Try again!\n";
        }

        Sleep(1000);
    }
}

