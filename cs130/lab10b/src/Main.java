import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter a string to test for palindrome or type QUIT to exit:\n");
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("QUIT")) {
                break;
            }

            if (isPalindrome(input)) {
                System.out.println("The input is a palindrome.");
            } else {
                System.out.println("The input is not a palindrome.");
            }
        }

        scanner.close();
    }

    private static boolean isPalindrome(String str) {
        // Remove non-alphabetic characters and convert to lowercase
        String cleanedStr = str.replaceAll("[^a-zA-Z]", "").toLowerCase();
        return isPalindromeRecursive(cleanedStr);
    }

    private static boolean isPalindromeRecursive(String str) {
        if (str.length() < 2) {
            return true;
        } else {
            char firstChar = str.charAt(0);
            char lastChar = str.charAt(str.length() - 1);

            if (firstChar == lastChar) {
                // Recursively check the substring without the first and last characters
                return isPalindromeRecursive(str.substring(1, str.length() - 1));
            } else {
                return false;
            }
        }
    }
}
