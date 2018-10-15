public class ExceptionDemo3 {
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

class AgeLessThanEighteenException extends Exception {
    private String message;
    
    public AgeLessThanEighteenException(String message) {
        this.message = message;
    }

    public String getMessage() {
        return message;
    }
}

class Bar {
    public void enter(int age) throws AgeLessThanEighteenException {
        if(age < 18) {
            throw new AgeLessThanEighteenException("invalid");
        } else {
            System.out.println("welcome");
        }
    }
}