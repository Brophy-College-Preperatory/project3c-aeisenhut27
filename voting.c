#include <stdio.h>

#define choices 3  // Number of choices


//function to display the current voting results and the percentage of votes for each option
void displayResults(int votes[], int totalVotes, char *options[]) {
    printf("\nCurrent Voting Results:\n");
    for (int i = 0; i < choices; i++) {
        double percentage = (totalVotes > 0) ? (votes[i] * 100.0 / totalVotes) : 0.0;
        printf("%s: %d votes (%.2f%%)\n", options[i], votes[i], percentage);
    }
}

int main() {
    //array of food options
    char *options[choices] = {"Burgers", "Hotdogs", "Milkshakes"};
    //array to store the number of votes for each option
    int votes[choices] = {0};
    //variables to keep track of total votes and the user's choice
    int totalVotes = 0;
    int choice;

    printf("Vote for your favorite food listed\n");
    printf("Your options:\n");

    //display the options to the user
    for (int i = 0; i < choices; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }
    printf("0 to stop voting.\n");

    //loop to get user input for voting
    while (1==1) {
        printf("\nVote (1-%d, or 0 to stop): ", choices);
        scanf("%d", &choice);

        //if user wants to stop voting, break the loop
        if (choice == 0) {
            printf("Voting over. Results:\n");
            displayResults(votes, totalVotes, options);
            break;
        //if not, counts current votes
        } else if (choice >= 1 && choice <= choices) {
            votes[choice - 1]++;
            totalVotes++;
            displayResults(votes, totalVotes, options);
        //error handling for invalid input
        } else {
            printf("Invalid choice. Please enter a number between 1 and %d.\n", choices);
        }
    }

    return 0;
}