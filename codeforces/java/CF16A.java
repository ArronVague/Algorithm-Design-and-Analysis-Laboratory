package codeforces.java;

import java.util.Scanner;

public class CF16A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume newline left-over

        char[][] array = new char[n][m];

        System.out.println("Enter " + n + " lines of " + m + " characters:");
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < m; j++) {
                array[i][j] = line.charAt(j);

            }
        }
        scanner.close();

    }
}
