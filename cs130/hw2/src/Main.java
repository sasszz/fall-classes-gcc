import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Usage: java RockPaperScissorsGame <seed>");
            return;
        }

        long seed = Long.parseLong(args[0]);
        Random random = new Random(seed);
        Scanner scanner = new Scanner(System.in);

        boolean playAgain = true;

        while (playAgain) {
            int computerChoice = random.nextInt(3); // 0 for rock, 1 for paper, 2 for scissors

            int userChoice = getUserChoice(scanner);

            displayChoices(userChoice, computerChoice);

            int result = determineWinner(userChoice, computerChoice);

            if (result == 0) {
                System.out.println("It's a draw.");
            } else if (result == 1) {
                System.out.println("You win.");
            } else {
                System.out.println("Computer wins.");
            }

            System.out.print("Would you like to play more?\n");
            String playMore = scanner.next().toLowerCase();
            playAgain = playMore.equals("y");
        }

        scanner.close();
    }

    public static int getUserChoice(Scanner scanner) {
        System.out.print("Enter 1 for rock, 2 for paper, and 3 for scissors.\n");
        int userChoice;
        do {
            userChoice = scanner.nextInt();
            if(userChoice > 3|| userChoice < 1) {
                System.out.print("Please respond 1, 2, or 3.\n");
                System.out.print("Enter 1 for rock, 2 for paper, and 3 for scissors.\n");
            }
        } while (userChoice < 1 || userChoice > 3);
        return userChoice - 1; // Convert to 0-based index
    }

    public static void displayChoices(int userChoice, int computerChoice) {
        String[] choices = { "rock", "paper", "scissors" };
        System.out.println("Your choice: " + choices[userChoice] + ". Computer choice: " + choices[computerChoice] + ".");
    }

    public static int determineWinner(int userChoice, int computerChoice) {
        if ((userChoice + 1) % 3 == computerChoice) {
            return -1; // Computer wins
        } else if ((computerChoice + 1) % 3 == userChoice) {
            return 1; // User wins
        } else {
            return 0; // It's a draw
        }
    }
}
