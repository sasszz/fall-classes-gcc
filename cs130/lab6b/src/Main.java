import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter a series of numbers separated only by commas or type QUIT to exit:\n");
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("QUIT")) {
                break;
            }

            if (input.isEmpty()) {
                System.out.println("Empty string.");
                continue;
            }

            double sum = calculateSum(input);

            if (sum == -1) {
                System.out.println("Invalid input.");
            } else {
                System.out.printf("The sum of those numbers is %.2f\n", sum);
            }
        }

        scanner.close();
    }

    public static double calculateSum(String input) {
        double sum = 0;

        // Remove spaces and split the input by commas
        String[] numbers = input.replaceAll(" ", "").split(",");

        for (String number : numbers) {
            try {
                double num = Double.parseDouble(number);
                sum += num;
            } catch (NumberFormatException e) {
                // Invalid input, return -1 to indicate an error
                return -1;
            }
        }

        return sum;
    }
}
