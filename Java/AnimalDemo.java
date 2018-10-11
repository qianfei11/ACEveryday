public class AnimalDemo {
    public static void main(String[] args) {
        Animal animal1 = new Dog("Wang");
        animal1.eat();
        // animal1.sleep();
        Animal animal2 = new Cat("Money");
        animal2.eat();
        // unsafe
        if(animal1 instanceof Cat) {
            System.out.println("right???");
            Cat cat = (Cat)animal1;
        }
    }
}

class Animal {
    private String name;

    public Animal(String name) {
        this.name = name;
    }

    public void eat() {
        ;
    }
}

class Dog extends Animal {
    public Dog(String name) {
        super(name);
    }

    public void eat() {
        System.out.println("Eat Bone.");
    }

    public void sleep() {
        System.out.println("Sleep.");
    }
}

class Cat extends Animal {
    public Cat(String name) {
        super(name);
    }

    public void eat() {
        System.out.println("Eat Fish.");
    }
}