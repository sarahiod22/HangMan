#include "hangman.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

HangMan::HangMan() {
    srand(time(0));
    word = words[rand() % 10]; // to get a random word from the array
    guesses = 0;
    correctGuesses = 0;
    incorrectGuesses = 0;
}

int HangMan::wordCount() { return word.size(); }

void HangMan::arrayToString(string _array[]) {
    for (int i = 0; i < word.size(); i++) {
        cout << _array[i] << " ";
    }
    cout << endl << endl;
}

void HangMan::vectorToString(vector<char> _vector) {
    for (int i = 0; i < _vector.size(); i++) {
        cout << _vector.at(i) << " ";
    }
    cout << endl << endl << endl;
}

void HangMan::guessLetter() {
    char letter;
    string answer[word.size()];
    vector<char> incorrectLetters;

    // filling the array with "empty spaces"
    for (int i = 0; i < word.size(); i++) {
        answer[i] = "_";
    }

    arrayToString(answer);

    // game loop
    while (correctGuesses < word.size()) {
        int noMatch = 0; //if noMatch is equal to word.size() then it was an incorrect guess.

        cout << "Enter a letter: ";
        cin >> letter;
        cout << endl;

        //making sure that the input is a letter
        if (isalpha(letter) != 0 && letter) {

            //Accept uppercase and lowercase
            letter = tolower(letter);

            for (int i = 0; i < word.size(); i++) {
                noMatch++;

                //a correct guess
                if (word.at(i) == letter && answer[i] != string(1, letter)) {
                    correctGuesses++;
                    noMatch--;
                    answer[i] = letter;
                    cout << "Well done! That letter is part of the word" << endl;
                    arrayToString(answer);
                    break;
                }
            }

            //an incorrect guess
            if (noMatch == word.size()) {
                incorrectGuesses++;
                incorrectLetters.push_back(letter);
                cout << letter << " is not part of the word. Try again!" << endl;
                arrayToString(answer);
            }

            guesses++;

            cout << "Total guesses: " << guesses;
            cout << " || Correct guesses: " << correctGuesses;
            cout << " || Incorrect guesses: " << incorrectGuesses;
            cout << endl;
            cout << "Incorrectly guessed letters: ";
            vectorToString(incorrectLetters);
        }
        else{
            cout << "Please enter a valid letter" << endl << endl;
        }
    }
    cout << "Good job! You have guessed the word! It took you " << guesses << " guess(es)." << endl << endl;
}
