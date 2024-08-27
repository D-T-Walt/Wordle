#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>  // Include the ctype.h library

// Function to generate random numbers
int random_index(int max) {
    return rand() % max;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // List of words
    const char* words[] = {"death", "sport", "couch", "grape", "screw", "mango"};
    int word_count = sizeof(words) / sizeof(words[0]);

    // Select a random word
    const char* word = words[random_index(word_count)];

    // Number of attempts allowed
    int attempts = 6;
    char guess[7];  // Buffer for user guess (6 letters + 1 for null terminator)

    // Main game loop
    while (attempts > 0) {
        // Ask for user input
        printf("Guess the entire word (6 letters): ");
        scanf("%6s", guess);

        // Convert guess to lowercase
        for (int i = 0; i < 6; i++) {
            guess[i] = tolower(guess[i]);  // Use tolower() for conversion
        }

        // Check if the guessed word is correct
        if (strcmp(guess, word) == 0) {
            printf("\033[0;36mCongratulations! You've guessed the word: %s\n", word);
            break;
        }

        // Check the accuracy of the guess and format feedback
        printf("Feedback: ");
        for (int i = 0; i < 6; i++) {
            if (guess[i] == word[i]) {
                printf("\033[1;32m%c", guess[i]);  // Correct letter
            } else if (strchr(word, guess[i])) {
                printf("\033[1;33m%c", guess[i]);  // Letter in word but in the wrong position
            } else {
                printf("\033[1;37m%c", guess[i]);  // Letter not in word
            }
        }
        printf("\033[0m\n");

        // Decrease attempts
        attempts--;

        // Check if the player has run out of attempts
        if (attempts == 0) {
            printf("\033[0;31mSorry, you've run out of attempts. The word was: %s\n", word);
        }
    }

    return 0;
}
