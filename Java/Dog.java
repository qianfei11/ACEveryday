public class Dog {
	public String brand;
	public int age;

	public String toString() {
		return "This is a " + age + " years old " + brand;
	}

	public static void main(String [] args) {
		Dog dog = new Dog();
		dog.brand = "normal dog";
		dog.age = 3;
		System.out.println(dog.toString());
	}
}