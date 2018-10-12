public class FactorialDemo {
    public static void main(String[] args) {
        System.out.println(FacUtil.getFac(5));
    }
}

class FacUtil {
    public static int getFac(int number) {
        if(number == 1) {
            return 1;
        } else {
            return number * getFac(number - 1);
        }
    }
}