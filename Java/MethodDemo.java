public class MethodDemo {
    public void method1() {
        System.out.println("return nothing and no args.");
    }

    public String method2() {
        return "return a string but no args.";
    }

    public void method3(String name) {
        System.out.println("return nothing but has an arg. " + name);
    }

    public String method4(String name, int age) {
        return "return a string and has more than one arg. " + name + age;
    }

    public void operateData(int age) {
        age++;
        System.out.println(age);
    }

    public void operateArray(int[] array) {
        array[2] = 100;
        System.out.println(array[2]);
    }

    public static void main(String[] args) {
        MethodDemo demo = new MethodDemo();
        demo.method1();
        System.out.println(demo.method2());
        demo.method3("hello");
        System.out.println(demo.method4("hello", 20));
        
        int age = 10;
        demo.operateData(age);
        System.out.println(age);

        int[] array = {1, 2, 3, 4};
        demo.operateArray(array);
        System.out.println(array[2]);
    }
}