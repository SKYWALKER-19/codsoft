#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Initialize random number generator
    std::srand(static_cast<unsigned>(std::time(0))); // Seed with current time
    
    // Generate a random number between 1 and 100
    int targetNumber = std::rand() % 100 + 1;
    int guess = 0;

    std::cout << "Guess the number (between 1 and 100): " << std::endl;

    // Loop until the user guesses the correct number
    while (guess != targetNumber) {
        std::cin >> guess; // Get the user's guess

        if (guess < targetNumber) {
            std::cout << "Too low! Try again: " << std::endl;
        } else if (guess > targetNumber) {
            std::cout << "Too high! Try again: " << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
        }
    }

    return 0;
}
