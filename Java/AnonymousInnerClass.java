public class AnonymousInnerClass {
    public static void main(String[] args) {
        Person p = new Person();
        // Animal dog = new Dog();
        // p.feed(dog);
        /* Animal dog = */ new IAnimal() {
            private String name = "wang";
            // invalid
            // static {
            //     name = "haha"
            // }
            public void eat() {
                System.out.println("eat bone");
            }
            public void show() {
                System.out.println("my own way");
            }
        }.show();
        // p.feed(dog);
        // p.feed(dog);
        p.feed(new Animal() {
            public void eat() {
                System.out.println("eat fish");
            }
        });
    }
}

class Person {
    public void feed(IAnimal animal) {
        animal.eat();
    }
}

// abstract class Animal {
//     public abstract void eat();
// }

interface IAnimal {
    public abstract void eat();
}

// class Dog extends Animal {
//     public void eat() {
//         System.out.println("eat bone");
//     }
// }