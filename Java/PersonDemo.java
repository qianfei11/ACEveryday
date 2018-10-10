public class Person {
    public static void main(String[] args) {
        Student stu = new Student("Tony", 20, 100);
        stu.eat();
        stu.walk();
        stu.goSchool();
        stu.exam();
        System.out.println(stu);
    }
}

class Person {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void eat() {
        System.out.println("I'm eating.");
    }

    public void walk() {
        System.out.println("I'm walking.");
    }

    public String toString() {
        return "name: " + name + " age: " + age;
    }
}

class Student extends Person {
    private int score;

    public Student(String name, int age, int score) {
        super(name, age);
        this.score = score;
    }

    public String toString() {
        return super.toString() + " score: " + score;
    }

    public void goSchool() {
        System.out.println("I'm going to school.");
    }

    public void exam() {
        System.out.println("I'm taking a exam.");
    }
}