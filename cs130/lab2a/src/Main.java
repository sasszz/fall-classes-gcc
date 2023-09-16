import java.util.Scanner;

public class Main {
    static boolean isPrime(int userInput) {
        if (userInput <= 1) {
            System.out.println("Invalid input.");
            return false;
        }
        if (userInput <= 3) {
            System.out.println(userInput + " is a prime number.");
            return true;
        }
        if (userInput % 2 == 0 || userInput % 3 == 0) {
            System.out.println(userInput + " is not a prime number.");
            return false;
        }

        // Check for prime using 6k +/- 1 rule
        for (int i = 5; i * i <= userInput; i += 6) {
            if (userInput % i == 0 || userInput % (i + 2) == 0) {
                System.out.println(userInput + " is not a prime number.");
                return false;
            }
        }
        System.out.println(userInput + " is a prime number.");
        return true;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Please enter a number to check for primality or -1 to exit:\n");
        int userInput = Integer.parseInt(scanner.nextLine());

        if (userInput == -1) {
            System.exit(0);
        }

        isPrime(userInput);
    }
}