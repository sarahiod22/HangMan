#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HangMan {
private:
  string word;
  int guesses;
  int correctGuesses;
  int incorrectGuesses;
  string words[10] = {"television", "microscopic", "furniture", "apartment",
                      "desk",       "trousers",    "watch",     "school",
                      "country",    "asphalt"};

public:
  // constructor
  HangMan();

  // return the number of letter in _word
  int wordCount();

  // prints the array (word)
  void arrayToString(string _array[]);

  // prints the vector (incorrect letters)
  void vectorToString(vector<char> _vector);

  // game loop
  void guessLetter();
};

#endif