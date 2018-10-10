public class TeacherDemo {
	public static void main(Stirng [] args) {
		JavaTeacher jTeacher = new JavaTeacher("Tony", "Ali");
		jTeacher.teaching();

		DBTeacher dTeacher = new DBTeacher("Peter", "Huawei");
		dTeacher.teaching();
	}
}

class Teacher {
	private String name;
	private String school;

	public Teacher(String name, String school) {
		this.name = name;
		this.school = school;
	}

	public void teaching() {
		System.out.println("prepare");
	}
}

class JavaTeacher extends Teacher {
	public JavaTeacher(String name, String school) {
		super(name, school);
	}

	public void teaching() {
		super.teaching();
		System.out.println("open eclipse");
		System.out.println("write java code");
	}
}

class DBTeacher extends Teacher {
	public JavaTeacher(String name, String school) {
		super(name, school);
	}

	public void teaching() {
		super.teaching();
		System.out.println("open oracle");
		System.out.println("write sql code");
	}
}