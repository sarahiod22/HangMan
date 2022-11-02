#include "hangman.h"
#include <iostream>
using namespace std;

int main() {

  string keepPlaying;

  do {
    cout << "Hello! Welcome to Hangman game " << endl << endl;
    
    HangMan *game = new HangMan();
    
    cout << "Your words has " << game->wordCount() << " letters!" << endl << endl;

    game->guessLetter();

    cout << "Do you want to keep playing? (yes/no): ";
    cin >> keepPlaying;
    cout << endl << endl;

    delete game;

  } while (keepPlaying == "yes");

  if(keepPlaying == "no"){
    cout << "Thanks for playing! We are sad to see you go." << endl;
    return 0;
  }
}
