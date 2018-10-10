public class ObjectDemo {
    public static void main(String[] args) {
        Student stu1 = Student("Jack", 20);
        System.out.println(stu1.toString());
        Student stu2 = Student("Jack", 20);
        // System.out.println(stu1.equals(stu1)); // true
        // System.out.println(stu1.equals(stu2)); // false
        // after overwrite equals
        System.out.println(stu1.equals(stu2)); // true
    }
}

class Student {
    private String name;
    private int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toString() {
        return "name: " + name + " age: " + age;
    }

    public boolean equals(Object obj) {
        if(this == obj) {
            return true;
        }
        if(obj == null) {
            return false;
        }
        if(this.getClass() != obj.getClass()) {
            return false;
        }
        Student stu = (Student) obj;
        if(this.age != stu.age) {
            return false;
        }
        if(this.name == null) {
            if(stu.name != null) {
                return false;
            }
        }
        else if(!this.name.equals(stu.name)) {
            return false;
        }
        return true;
    }
}