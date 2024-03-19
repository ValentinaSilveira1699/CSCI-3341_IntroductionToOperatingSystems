/*
Write a Java program A1p1.java with a public class A1p1 and no named packages. The program should take two command line arguments assumed to be integers a and b (with a<b) and print the integers a,a+3,a+6,a+9,…,(up to b). Each line should contain five integers separated by commas with no comma after the last integer on each line (the last line is allowed to contain less than five integers). Further, if any integer is a multiple of 7, it should be printed between a pair of curly braces. Two sample runs look like the following (Note: in sample runs, blue color means those typed by the user while others are displayed by the program or the command window itself):
[kwang@computer][~/temp]$ java A1p1 5 47
5,8,11,{14},17
20,23,26,29,32
{35},38,41,44,47
[kwang@computer][~/temp]$ java A1p1 -3 59
-3,{0},3,6,9
12,15,18,{21},24
27,30,33,36,39
{42},45,48,51,54
57

*/
public class A1p1 {
    public static void main(String[] args) {
        // Parse command line arguments as integers
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);

        // Counter to keep track of the number of outputs in the current row
        int outputCount = 0;

        // Iterate from 'a' to 'b' with a step of 3
        for (int i = a; i <= b; i += 3) {
            // Check if the current number is a multiple of 7
            if (i % 7 == 0) {
                // If multiple of 7, print the number within curly braces
                System.out.print("{" + i + "}");
            } else {
                // If not multiple of 7, print the number as is
                System.out.print(i);
            }

            // Add a comma if it's not the last number in the loop and not the 5th output
            if (i + 3 <= b && i + 3 - a <= b - a && outputCount < 4) {
                System.out.print(",");
            }

            // Increment the output count
            outputCount++;

            // Print a newline after every 5 outputs
            if (outputCount == 5) {
                System.out.println();
                outputCount = 0; // Reset the output count for the next row
            }
        }

        // Print a newline if the last row contains less than 5 outputs
        if (outputCount > 0) {
            System.out.println();
        }
    }
}



