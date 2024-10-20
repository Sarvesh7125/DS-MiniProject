#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10

typedef struct {
    int guesses[MAX_GUESSES];
    int top;
} Stack;

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_GUESSES - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int guess) {
    if (!isFull(s)) {
        s->top++;
        s->guesses[s->top] = guess;
    } else {
        printf("No more space for guesses!\n");
    }
}

void pop(Stack *s) {
    if (!isEmpty(s)) {
        s->top--;
    }
}

void printGuesses(Stack *s) {
    if (isEmpty(s)) {
        printf("No guesses made yet.\n");
    } else {
        printf("Your previous guesses: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->guesses[i]);
        }
        printf("\n");
    }
}

// Main game logic
int main() {
    Stack guesses;
    int number, guess;
    
    // Seed the random number generator
    srand(time(NULL));
    number = rand() % 100 + 1;  // Random number between 1 and 100

    // Initialize the guess stack
    initStack(&guesses);

    printf("Welcome to the Number Guessing Game!\n");
    printf("I've selected a number between 1 and 100. Try to guess it!\n");

    while (1) {
        printf("Enter your guess (or -1 to see previous guesses): ");
        scanf("%d", &guess);

        if (guess == -1) {
            printGuesses(&guesses);
            continue;
        }

        // Push the guess onto the stack
        push(&guesses, guess);

        if (guess < number) {
            printf("Higher!\n");
        } else if (guess > number) {
            printf("Lower!\n");
        } else {
            printf("Congratulations! You've guessed the number: %d\n", number);
            break;
        }
    }

    return 0;
}
