public class OverloadDemo {
    public static void main(String[] args) {
        Printer p = new Printer("dale", 1000);
        p.print("hello");
        p.print(10);
        p.print("hello", 10);
    }
}

class Printer {
    private String brand = "hupe";
    private double price;

    public Printer(double price) {
        this.price = price;
    }

    public Printer(String brand, double price) {
        this.brand = brand;
        this.price = price;
    }

    public void print(String content) {
        System.out.println("string: " + content);
    }

    public void print(int content) {
        System.out.println("intergar: " + content);
    }

    public void print(String str, int content) {
        System.out.println(str + "--" + content);
    }

    // invalid
    // public int print(int content) {
    //     return content;
    // }
}