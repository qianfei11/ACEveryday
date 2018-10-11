public class EmployeeDemo {
    public static void main(String[] args) {
        JavaTeacher teacher = new JavaTeacher(1, "Tony", 2000);
        teacher.work();
        Leader leader = new leader(2, "Peter", 3000, 10000);
        leader.work();

        // illegal
        // Employee emp = new Employee(3, "Test", 123);
    }
}

abstract class Employee {
    private int number;
    private String name;
    private double salary;

    public Employee(int number, String name, double salary) {
        this.number = number;
        this.name = name;
        this.salary = salary;
    }
    
    public abstract void work();
}

class JavaTeacher extends Employee {
    public JavaTeacher(int number, String name, double salary) {
        super();
    }

    public void work() {
        System.out.println("Java Lesson!");
    }
}

class Leader extends Employee {
    private double allowance;

    public leader(int number, String name, double salary, double allowance) {
        super();
        this.allowance = allowance;
    }

    public void work() {
        System.out.println("Train new fish!");
        System.out.println("Design new lesson!");
    }
}