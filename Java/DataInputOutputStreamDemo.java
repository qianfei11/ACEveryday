import java.io.DataOutputStream;
import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class DataInputOutputStreamDemo {
    public static void main(String[] args) throws IOException {
        String name = "Tony";
        int age = 10;
        boolean flag = true;
        char sex = '男'；
        double money = 100.56;

        DataOutputStream dos = new DataOutputStream(new FileOutputStream("/Users/qianfei/test/1.txt"));
        dos.writeUTF(name);
        dos.writeInt(age);
        dos.writeBoolean(flag);
        dos.writeChar(sex);
        dos.writeDouble(money);
        dos.close();

        DataInputStream dis = new DataInputStream(new FileInputStream("/Users/qianfei/test/1.txt"));
        System.out.println(dis.readUTF());
        System.out.println(dis.readInt());
        System.out.println(dis.readBoolean());
        System.out.println(dis.readChar());
        System.out.println(dis.readDouble());
        dis.close();
    }
}