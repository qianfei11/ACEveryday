public class StringBuilderDemo {
    public static void main(String[] args) {
        // invalid
        // StringBuilder sb = "abc";
        StringBuilder sb = new StringBuilder("abc");
        sb.append("hello");
        sb.append(1);
        sb.append(1.5)
        sb.append(true);
        System.out.println(sb.length());
        System.out.println(sb.capacity());
        sb.insert(5, "world");
        System.out.println(sb.toString());
        sb.replace(5, 7, "el");
        System.out.println(sb.toString());
        System.out.println(sb.indexOf("el"));
        System.out.println(sb.reverse());
    }
}