public class InterfaceDemo {
	public static void main(String [] args) {
		Person p = new Person();
		Child child = new Child();
		Dog dog = new Dog();
		p.feed(child);
		p.feed(dog);
	}
}

class Person {
	// reload
	// public void feed(Child child) {
	// 	child.eat();
	// }
	// public void feed(Dog dog) {
	// 	dog.eat();
	// }

	// interface ==> poly
	public void feed(IAbility ability) {
		ability.eat(); // dynamic binding
	}
}

interface IAbility {
	/* public static final */ int number = 1;
	/* public abstract */ void show();
	void eat();
}

class Child implements IAbility {
	public void eat() {
		System.out.println("Eat Rice");
	}
}

class Dog implements IAbility {
	public void eat() {
		System.out.println("Eat Bone");
	}
}