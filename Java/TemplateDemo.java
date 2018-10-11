public class TemplateDemo {
    public static void main(String[] args) {
        Teacher t1 = new DBTeacher();
        t1.work();
        Teacher t2 = new CTeacher();
        t2.work();
    }
}

class Teacher {
    public void prepared() {
        System.out.println("prepare chalk");
        System.out.println("open machine");
    }

    public void end() {
        System.out.println("close machine");
        System.out.println("close the door");
    }

    public abstract void teaching();

    // template
    public void work() {
        prepared();
        teaching();
        end();
    }
}

class DBTeacher extends Teacher {
    public void teaching() {
        System.out.println("open oracle");
        System.out.println("write sql code");
        System.out.println("beatify the code");
    }
}

class CTeacher extends Teacher {
    public void teaching() {
        System.out.println("open vs");
        System.out.println("write c code");
        System.out.println("debug the code");
    }
}