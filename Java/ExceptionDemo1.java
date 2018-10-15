import java.util.Scanner;
import java.util.InputMismatchException;

public class ExceptionDemo1 {
    public static void main(String[] args) {
        System.out.println("Please input a number:");
        Scanner input = new Scanner(System.in);
        int res = 0;
        try {
            int number = input.nextInt();
            res = 10 / number;
            // System.exit(0);
        } catch (InputMismatchException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        } catch (ArithmeticException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        } catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        } finally {
            // close file...
            System.out.println("result: " + res);
        }

        testTryFinally("Tony");
    }

    public static void testTryFinally(String name) {
        try {
            System.out.println(name.length());
        } finally {
            System.out.println("end");
        }
    }
}