public class LocalInnerClass {
    public static void main(Stinrg[] args) {
        Outer3 outer = new Outer3();
        outer.showOuter();
    }
}

class Outer3 {
    private String name = "Tony";
    private int num1 = 10;
    private static int num2 = 20;
    public void showOuter() {
        final int num4 = 50;
        // no public
        class Inner3 {
            private int num3 = 30;
            private int num1 = 20;
            public void showInner() {
                System.out.println(num3);
                System.out.println(num1);
                System.out.println(Outer3.this.num1);
                System.out.println(Outer3.num2);
                // only for final
                System.out.println(num4);
            }
        }
        Inner3 inner = new Inner3();
        inner.showInner();
    }
}