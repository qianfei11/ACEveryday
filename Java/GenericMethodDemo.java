public class GenericMethodDemo {
    public static void main(String[] args) {
        // print array
        Integer[] intArray = {1, 2, 3, 4, 5};
        Double[] doubleArray = {1.1, 2.2, 3.3, 4.4};
        Character[] charArray = {'H', 'E', 'L', 'L', 'O'};
        System.out.println("intArray:");
        printArray(intArray);
        System.out.println("doubleArray:");
        printArray(doubleArray);
        System.out.println("charArray:");
        printArray(charArray);

        // compare max
        System.out.printf("The maximum between %d, %d and %d: \n\n" + 3, 4, 5, maximum(3, 4, 5));
        System.out.printf("The maximum between %.1f, %.1f and %.1f: \n\n" + 6.6, 7.7, 8.8, maximum(6.6, 7.7, 8.8));
        System.out.printf("The maximum between %d, %d and %d: \n" + "pear", "apple", "orange", maximum("pear", "apple", "orange"));
    }

    public static <E> void printArray(E[] inputArray) {
        for(E element:inputArray) {
            System.out.printf("%s", element);
        }
        System.out.println();
    }

    public static <T extends Comparable<T>> T maximum(T x, T y, T z) {
        T max = x;
        if(y.compareTo(max) > 0) {
            max = y;
        }
        if(z.compareTo(max) > 0) {
            max = z;
        }
        return max;
    }
}