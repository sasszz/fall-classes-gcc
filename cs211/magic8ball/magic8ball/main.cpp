//
//  main.cpp
//  magic8ball
//
//  Created by Lucie Chevreuil on 10/2/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Array of Magic 8-Ball answers
    const char* responses[] = {
        "It is certain.",
        "It is decidedly so.",
        "Without a doubt.",
        "Yes - definitely.",
        "You may rely on it.",
        "As I see it, yes.",
        "Most likely.",
        "Outlook good.",
        "Yes.",
        "Signs point to yes.",
        "Reply hazy, try again.",
        "Ask again later.",
        "Better not tell you now.",
        "Cannot predict now.",
        "Concentrate and ask again.",
        "Don't count on it.",
        "My reply is no.",
        "My sources say no.",
        "Outlook not so good.",
        "Very doubtful."
    };

    // Prompt the user for a question
    cout << "Ask the Magic 8-Ball a yes-or-no question: \n";
    string question;
    getline(cin, question);

    // Generate a random index for the response
    int randomIndex = rand() % (sizeof(responses) / sizeof(responses[0]));

    // Display the Magic 8-Ball's response
    cout << "Magic 8-Ball says: " << responses[randomIndex] << endl;

    return 0;
}
