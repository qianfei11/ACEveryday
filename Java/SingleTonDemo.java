public class SingleTonDemo {
    public static void main(String[] args) {
        // SingleTon ton1 = new SingleTon();
        // SingleTon ton2 = new SingleTon();
        SingleTon ton1 = SingleTon.getInstance();
        SingleTon ton2 = SingleTon.getInstance();
    }
}

class SingleTon {
    private static SingleTon singleTon = null;
    private SingleTon {
        System.out.println("SingleTon");
    }

    public static SingleTon getInstance() {
        if(singleTon == null) {
            singleTon = new SingleTon();
        }
        return singleTon;
    }
}