#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define a structure to hold quiz question data
typedef struct {
    char question[150];
    char options[4][50];
    char correct_answer;
} QuizQuestion;

// Function to clear the input buffer
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Initialize an array of questions
    QuizQuestion quiz[3] = {
        {
            "Which programming language is known as the 'mother of all languages'?",
            {"A. Python", "B. C", "C. Java", "D. Assembly"},
            'B'
        },
        {
            "What does CPU stand for?",
            {"A. Central Processing Unit", "B. Computer Personal Unit", "C. Central Processor Unifier", "D. Central Print Utility"},
            'A'
        },
        {
            "Which of the following is NOT an operating system?",
            {"A. Linux", "B. Windows", "C. macOS", "D. HTML"},
            'D'
        }
    };

    int total_questions = 3;
    int score = 0;
    char user_answer;

    printf("====================================\n");
    printf("🧠    Welcome to the Tech Quiz!    🧠\n");
    printf("====================================\n\n");

    // Loop through each question
    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        
        // Print the 4 options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Get and validate user input
        while (1) {
            printf("Your answer (A, B, C, or D): ");
            scanf(" %c", &user_answer); // Note the space before %c to skip whitespace
            user_answer = toupper(user_answer); // Convert to uppercase for easy matching

            if (user_answer >= 'A' && user_answer <= 'D') {
                break; // Valid answer received
            } else {
                printf("❌ Invalid choice. Please enter A, B, C, or D.\n");
                clear_buffer();
            }
        }

        // Check if the answer is correct
        if (user_answer == quiz[i].correct_answer) {
            printf("🎉 Correct!\n\n");
            score++;
        } else {
            printf("❌ Wrong. The correct answer was %c.\n\n", quiz[i].correct_answer);
        }
    }

    // Display final score
    printf("====================================\n");
    printf("🏁 Quiz Finished! 🏁\n");
    printf("Your Final Score: %d out of %d\n", score, total_questions);
    
    double percentage = ((double)score / total_questions) * 100;
    printf("Percentage: %.1f%%\n", percentage);
    
    if (score == total_questions) {
        printf("🏆 Perfect score! You're a genius!\n");
    } else if (score >= total_questions / 2) {
        printf("👍 Good job! You passed.\n");
    } else {
        printf("📚 Better luck next time! Keep studying.\n");
    }
    printf("====================================\n");

    return 0;
}