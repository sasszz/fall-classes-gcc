import java.util.Scanner;

public class Main {
    public static void calculateRetail(double wholesaleCost, double markupPercentage) {
        double calculation = wholesaleCost + (wholesaleCost * markupPercentage / 100);
        System.out.printf("The retail price is: %.2f%n", calculation);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Please enter the wholesale cost or -1 exit:");
            int userWholesaleInput;
            do {
                String userInput = scanner.nextLine();
                if (userInput.equals("-1")) {
                    System.exit(0);
                }
                try {
                    userWholesaleInput = Integer.parseInt(userInput);
                    if (userWholesaleInput < 0) {
                        System.out.println("Wholesale cost cannot be a negative value.");
                        System.out.println("Please enter the wholesale cost again or -1 exit:");
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input. Please enter a valid integer or -1 exit.");
                    userWholesaleInput = -2; // Set an invalid value to trigger re-entry
                }
            } while (userWholesaleInput < 0);

            System.out.println("Please enter the markup percentage or -1 exit:");
            int userMarkupInput;
            do {
                String userInput = scanner.nextLine();
                if (userInput.equals("-1")) {
                    System.exit(0);
                }
                try {
                    userMarkupInput = Integer.parseInt(userInput);
                    if (userMarkupInput < -100) {
                        System.out.println("Markup cannot be less than -100%.");
                        System.out.println("Please enter the markup again or -1 exit:");
                    }
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input. Please enter a valid integer or -1 exit.");
                    userMarkupInput = -2; // Set an invalid value to trigger re-entry
                }
            } while (userMarkupInput < -100);

            calculateRetail(userWholesaleInput, userMarkupInput);
        }
    }
}