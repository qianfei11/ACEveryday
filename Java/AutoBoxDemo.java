public class AutoBoxDemo {
    public static void main(String[] args) {
        int i = 10;
        double = 10.5;
        Intergar num1 = 1;
        Double num2 = d;
        System.out.println(num1);
        System.out.println(num2);

        int j = num1; // int j = num1.intValue();
        double dd = num2; // double dd = num2.doubleValue();
        System.out.println(j);
        System.out.println(dd);

        Object o = i; // Object o = new Intergar(i);
        Intergar b = (Intergar)o;
        System.out.println(b.intValue());
    }
}