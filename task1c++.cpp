#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have picked a number between 1 and 100." << endl;
    // Keep asking the user for a guess until they get it right
    while (userGuess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        if (userGuess < randomNumber) {
            cout << "Your guess is too low. Try again!" << endl;
        } else if (userGuess > randomNumber) {
            cout << "Your guess is too high. Try again!" << endl;
        } else {
            cout << "Congratulations! You guessed the right number: " << randomNumber << "!" << endl;
        }
    }
    return 0;
}
