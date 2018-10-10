public class ConstructorDemo {
    public static void main(String[] args) {
        Person p = new Person("Peter", 14, "Nowhere");
        // p.setName("Tony");
        // p.setAge(13);
        // p.setCity("Everywhere")
        System.out.println(p.toString());
    }
}

class Person {
    private String name;
    private int age;
    private String city;

    public Person() {
        System.out.println("No args");
    }

    public Person(String name, int age, String city) {
        this();
        this.name = name;
        this.age = age;
        this.city = city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getCity() {
        return this.city;
    }
    
    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getAge() {
        return this.age;
    }

    public String toString() {
        return "name: " + this.name + " age: " + this.age + " address: " + this.city;
    }
}