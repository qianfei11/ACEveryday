public class FinalDemo {
    public static void main(String[] args) {
        A a = new A();
        a.showNumber1();

        B b = new B();
        b.showNumber2();

        // a2 only can point to the first object
        final A a2 = new A();
        // a2 = new A();
        a2.number2 = 5;
        a2.showNumber2();
    }
}

// can not extend
final class A {
    public final int number1 = 1;
    public int number2 = 2;

    public void showNumber1() {
        // invalid
        // number1++;
        System.out.println(number1);
    }

    // can not overwrite
    public final void showNumber2() {
        System.out.println(number2);
    }
}

// class B extends A {
//     // invalid
//     // public void showNumber2() {
//     //     System.out.println(number2);
//     // }
// }