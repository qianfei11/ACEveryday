public class GenericClassDemo<T> {
    public static void main(String[] args) {
        GenericClassDemo<Integer> intObj = new GenericClassDemo<Integer>();
        GenericClassDemo<String> stringObj = new GenericClassDemo<String>();

        intObj.add(new Integer(10));
        stringObj.add(new String("Hello"));

        System.out.printf("intValue: %d\n\n", intObj.get());
        System.out.printf("stringValue: %s\n", stringObj.get());
    }

    private T t;

    public void add(T t) {
        this.t = t;
    }

    public T get() {
        return t;
    }
}