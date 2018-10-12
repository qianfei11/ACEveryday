public class MemberInnerClass {
    public static void main(String[] args) {
        Outer1 outer = new Outer1();
        Outer1.Inner1 inner = outer.new Inner1();
        inner.innerShow();
        outer.outerShow();
    }
}

class Outer1 {
    private String name = "Tony";
    private int num1 = 10;
    public void outerShow() {
        System.out.println(name);
        System.out.println(num1);
        // invalid
        // System.out.println(num2);
        Inner1 inner1 =  new Inner1();
        inner1.innerShow();
    }

    public class Inner1 {
        private String name = "Peter";
        private int num2 = 20;
        // invalid
        // private static int num3 = 30;
        public void innerShow() {
            System.out.println(Outer1.this.name);
            System.out.println(num2);
            System.out.println(num1);
            Outer1.this.outerShow();
        }
    }
}