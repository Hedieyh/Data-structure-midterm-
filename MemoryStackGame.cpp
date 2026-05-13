#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

string reverseWithStack(string word) {
    stack<char> letters;
    string reversed = "";

    for (int i = 0; i < word.length(); i++) {
        letters.push(word[i]);
    }

    while (!letters.empty()) {
        reversed += letters.top();
        letters.pop();
    }

    return reversed;
}

void clearScreen() {
    for (int i = 0; i < 40; i++) {
        cout << endl;
    }
}

int main() {
    srand(time(0));

    char choice;
    char playAgain;
    string word, answer, correctAnswer;

    cout << "=====================================\n";
    cout << "        MEMORY STACK GAME\n";
    cout << "=====================================\n";
    cout << "In this game, you will see a word.\n";
    cout << "When the word is reversed, it becomes another meaningful word.\n";
    cout << "You should memorize the word and type its reversed form.\n";
    cout << "This game uses Stack and LIFO principle.\n";
    cout << "LIFO means Last In, First Out.\n\n";

    do {
        cout << "Choose a Level:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            int randomEasy = rand() % 2;

            if (randomEasy == 0) {
                word = "live";
            } else {
                word = "loop";
            }
        }
        else if (choice == '2') {
            word = "drawer";
        }
        else if (choice == '3') {
            word = "stressed";
        }
        else if (choice == '4') {
            cout << "Exiting the game...\n";
            break;
        }
        else {
            cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n\n";
            continue;
        }

        correctAnswer = reverseWithStack(word);

        cout << "\nMemorize this word: " << word << endl;
        cout << "You have 3 seconds...\n";

        this_thread::sleep_for(chrono::seconds(3));

        clearScreen();

        cout << "Now type the reversed word: ";
        cin >> answer;

        while (answer != correctAnswer) {
            cout << "Wrong answer! Try again.\n";
            cout << "Enter the reversed word: ";
            cin >> answer;
        }

        cout << "\nCorrect! Well done.\n";
        cout << "Reversed word: " << correctAnswer << endl;

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

        clearScreen();

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThank you for playing!\n";

    return 0;
}
