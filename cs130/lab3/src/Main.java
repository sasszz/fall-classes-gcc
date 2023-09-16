import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        double[] monthlyRainfallData = new double[12];
        Scanner scanner = new Scanner(System.in);

        String[] months = {
                "January", "February", "March", "April",
                "May", "June", "July", "August",
                "September", "October", "November", "December"
        };

        for (int i = 0; i < 12; i++) {
            System.out.print("Enter the rainfall amount for month " + (i + 1) + ":\n");
            monthlyRainfallData[i] = scanner.nextDouble();
        }

        RainFall rainData = new RainFall(monthlyRainfallData);

        System.out.printf("Maximum rainfall: %s, %.1f inches%n", months[rainData.getMonthWithMostRain()], rainData.getMostRainQuantity());
        System.out.printf("Minimum rainfall: %s, %.1f inches%n", months[rainData.getMonthWithLeastRain()], rainData.getLeastRainQuantity());
        System.out.printf("Total rainfall: %.1f inches%n", rainData.getTotalRainfall());
        System.out.printf("Average rainfall: %.1f inches%n", rainData.getAverageMonthlyRainfall());


        scanner.close();
    }
}
