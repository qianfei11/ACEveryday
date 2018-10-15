import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileInputStreamOutputStreamDemo {
    public static void main(String[] args) {
        try {
            FileCopyUtil.copyFile(new File('/Users/qianfei/test/flag'), new File('/Users/qianfei/Desktop/test.txt'));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class FileCopyUtil {
    public static void copyFile(File src, File dst) throws IOException {
        FileInputStream fis = new FileInputStream(src);
        FileOutputStream fos = new FileOutputStream(dst);
        // int data = -1;
        // while((data = fis.read()) != -1) {
        //     fos.write(data);
        // }
        // fis.close();
        // fos.close();
        byte[] buf = new byte[1024 * 1024];
        int len = 0;
        while((len = fis.read(buf)) != -1) {
            fos.write(buf, 0, len);
        }
        fis.close();
        fos.close();
    }
}