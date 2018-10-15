import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileOutputStream;

public class ByteArrayInputOutputStreamDemo {
    public static void main(String[] args) {
        String str = "Hello World";
        ByteArrayInputStream bis = new ByteArrayInputStream(str.getBytes());
        int data = -1;
        while((data = bis.read()) != -1) {
            System.out.print((char)data);
        }

        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        bos.write(97);
        bos.write(65);
        bos.write("Hello World".getBytes());
        byte[] buf = bos.toByteArray();
        for(byte data:buf) {
            System.out.print((char)data);
        }

        FileOutputStream fos = new FileOutputStream("/Users/qianfei/test/flag", true);
        bos.writeTo(fos);
        fos.close();
    }
}

