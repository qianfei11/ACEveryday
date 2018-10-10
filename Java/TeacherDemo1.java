public class TeacherDemo {
	public static void main(Stirng [] args) {
		Teacher t = new Teacher();
		t.setName("Tony");
		System.out.println(t.getName());
		t.setAge(24);
		System.out.println(t.getAge());
	}
}

class Teacher {
	private String name;
	private int age;

	public void setName(String tname) {
		name = tname;
	}
	
	public String getName() {
		return name;
	}
	
	public void setAge(int tage) {
		if(tage < 25) {
			System.out.println("Too young too naive");
			age = 25;
		}
		else {
			age = tage;
		}
	}
	
	public int getAge() {
		return age;
	}
}