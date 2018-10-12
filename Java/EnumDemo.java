public class EnumDemo {
    public static void main(String[] args) {
        System.out.println(Color.BLUE);
        Color[] colors = Color.values();
        for(Color c:colors) {
            System.out.println(c);
        }
        System.out.println(Person.P1 /*.toString() */);
        Person[] ps = Person.values();
        for(Person p:ps) {
            System.out.println(p);
        }

        Person p = Person.P3
        switch (p) {
            case P1:
                System.out.println(P1);
                break;

            case P2:
                System.out.println(P2);
                break;

            case P3:
                System.out.println(P3);
                break;
        
            default:
                break;
        }
    }
}

// public static final Color RED = new Color()
// public static final Color BLUE = new Color()
// public static final Color YELLOW = new Color()
enum Color {
    // first line
    RED, BLUE, YELLOW;
    private Color() {
        System.out.println("test");
    }
}

// public static final Person P1 = new Person("Tony", 30)
// public static final Person P1 = new Person("John", 20)
// public static final Person P1 = new Person("Sarah", 18)
enum Person {
    P1("Tony", 30), P2("John", 20), P3("Sarah", 18);
    private String name;
    private int age;
    private Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public String toString() {
        return name + "--" + age;
    }
}