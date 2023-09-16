import java.util.Scanner;

public class Main {

    static boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num <= 3) {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0) {
            return false;
        }

        // Check for prime using 6k +/- 1 rule
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    static void printPrime(int userInput) {
        if (userInput > 1) {
            for (int i = 2; i < userInput; i++) {
                if (isPrime(i)) {
                    System.out.print(i + " ");
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: \n");

        int userInput = Integer.parseInt(scanner.nextLine());
        printPrime(userInput);


    }
}