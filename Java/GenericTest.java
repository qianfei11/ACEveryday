import java.util.*;

public class GenericTest {
    public static void main(String[] args) {
        List<String> name = new ArrayList<String>();
        List<Integer> age = new ArrayList<Integer>();
        List<Number> number = new ArrayList<Number>();
        
        name.add("Tony");
        age.add(18);
        number.add(523);

        getData(name);
        getData(age);
        getData(number);

        // invalid
        // getUperNumber(name);
        getUperNumber(age);
        getUperNumber(number);
    }

    public static void getData(List<?> data) {
        System.out.println("data: " + data.get(0));
    }

    // Only take Number or his father class
    public static void getUperNumber(List<? extends Number> data) {
        System.out.println("data: " + data.get(0));
    }
}