public class ExceptionDemo2 {
    public static void main(String[] args) {
        Bar bar = new Bar();
        try {
            bar.enter(15);
        } catch (Exception e) {
            System.out.println("error: " + e.getMessage());
        }
        System.out.println("end");
    }
}

class Bar {
    public void enter(int age) throws Exception {
        if(age < 18) {
            // throw new IllegalArgumentException("invalid");
            throw new Exception("invalid");
        } else {
            System.out.println("welcome");
        }
    }
}