import java.text.DecimalFormat;
import java.util.Scanner;

public class Payroll {
    private int[] employeeId = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    private int[] hours = new int[7];
    private double[] payRate = new double[7];
    private double[] wages = new double[7];

    public void setHours(int empId, int hoursWorked) {
        int index = findEmployeeIndex(empId);
        if (index != -1 && hoursWorked >= 0) {
            hours[index] = hoursWorked;
            calculateWages(empId); // Calculate wages when hours are set
        } else {
            System.out.println("Hours cannot be negative.");
        }
    }

    public void setPayRate(int empId, double payRateValue) {
        int index = findEmployeeIndex(empId);
        if (index != -1 && payRateValue >= 6.00) {
            payRate[index] = payRateValue;
            calculateWages(empId); // Calculate wages when pay rate is set
        } else {
            System.out.println("Employee pay rate cannot be less than $6.00/hour.");
        }
    }

    public double calculateWages(int empId) {
        int index = findEmployeeIndex(empId);
        if (index != -1) {
            wages[index] = hours[index] * payRate[index];
            return wages[index];
        } else {
            return -1; // Employee not found
        }
    }

    private int findEmployeeIndex(int empId) {
        for (int i = 0; i < employeeId.length; i++) {
            if (employeeId[i] == empId) {
                return i;
            }
        }
        return -1; // Employee not found
    }

    public void displayEmployeeInfo() {
        DecimalFormat decimalFormat = new DecimalFormat("###0.00");
        System.out.println("===========================");
        System.out.println("Employee ID\tGross Wages");
        System.out.println("===========================");
        for (int i = 0; i < employeeId.length; i++) {
            System.out.printf("%11d\t$%10s\n", employeeId[i], decimalFormat.format(wages[i]));
        }
    }

    public static void main(String[] args) {
        Payroll payroll = new Payroll();
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < payroll.employeeId.length; i++) {
            int empId = payroll.employeeId[i];
// Input validation for hours worked
            do {
                System.out.print("Please enter hours for employee ID: " + empId + "\n");
                int hoursWorked = scanner.nextInt();
                if (hoursWorked >= 0) {
                    payroll.setHours(empId, hoursWorked);
                    break;
                } else {
                    System.out.println("Hours cannot be negative.");
                }
            } while (true);

            // Input validation for pay rate
            do {
                System.out.print("Please enter pay rate for employee ID: " + empId + "\n");
                double payRate = scanner.nextDouble();
                if (payRate >= 6.00) {
                    payroll.setPayRate(empId, payRate);
                    break;
                } else {
                    System.out.println("Employee pay rate cannot be less than $6.00/hour.");
                }
            } while (true);
        }

        payroll.displayEmployeeInfo();
    }
}
