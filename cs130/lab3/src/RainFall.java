public class RainFall {
    private double[] monthlyRainfall;

    public RainFall(double[] monthlyRainfall) {
        if (monthlyRainfall.length != 12) {
            throw new IllegalArgumentException("Monthly rainfall data must have exactly 12 months.");
        }
        this.monthlyRainfall = monthlyRainfall;
    }

    public double getTotalRainfall() {
        double total = 0.0;
        for (double rainfall : monthlyRainfall) {
            total += rainfall;
        }
        return total;
    }

    public double getAverageMonthlyRainfall() {
        return getTotalRainfall() / 12.0;
    }

    public int getMonthWithMostRain() {
        int monthWithMostRain = 0;
        double maxRainfall = monthlyRainfall[0];

        for (int i = 1; i < monthlyRainfall.length; i++) {
            if (monthlyRainfall[i] > maxRainfall) {
                maxRainfall = monthlyRainfall[i];
                monthWithMostRain = i;
            }
        }

        return monthWithMostRain;
    }

    public double getMostRainQuantity() {
        double maxRainfall = monthlyRainfall[getMonthWithMostRain()];

        return maxRainfall;
    }

    public int getMonthWithLeastRain() {
        int monthWithLeastRain = 0;
        double minRainfall = monthlyRainfall[0];

        for (int i = 1; i < monthlyRainfall.length; i++) {
            if (monthlyRainfall[i] < minRainfall) {
                minRainfall = monthlyRainfall[i];
                monthWithLeastRain = i;
            }
        }

        // Adding 1 to the month index to match the human-readable month numbering (1-12)
        return monthWithLeastRain;
    }

    public double getLeastRainQuantity() {
        double leastRainfall = monthlyRainfall[getMonthWithLeastRain()];

        return leastRainfall;
    }
}