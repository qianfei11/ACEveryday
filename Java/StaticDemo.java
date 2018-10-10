public class StaticDemo {
    public static void main(String[] args) {
        Account acc1 = new Account();
        acc1.number1++;
        acc1.showNumber1();
        acc1.showNumber2();

        Account acc2 = new Account();
        acc2.showNumber1();
        acc2.showNumber2();

        Account.number1++;
        System.out.println(Account.number1);

        Account acc3 = new Account();
        acc3.showNumber2();
        Account acc4 = new Account();
        acc4.showNumber2();
    }
}

class Account {
    public static int number1 = 1;
    public int number2 = 2;

    public Account() {
        System.out.println("constructor");
    }

    static {
        System.out.println("static");
        number1 = 100;
    }

    public static void showNumber1() {
        System.out.println(number1);
        // can not visit no static value.
        // can not use this.
        // System.out.println(this.number2);
    }

    public void showNumber2() {
        System.out.println(number2);
        System.out.println("No static visit static value: " + number1);
    }
}