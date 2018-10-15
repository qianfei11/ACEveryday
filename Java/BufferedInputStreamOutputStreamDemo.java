import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class BufferedInputStreamOutputStreamDemo {
    public static void main(String[] args) {
        try {
            FileUtil.copyFile(new File('/Users/qianfei/test/flag'), new File('/Users/qianfei/Desktop/test.txt'));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class FileUtil {
    public static void copyFile(File src, File dst) throws IOException {
        FileInputStream fis = new FileInputStream(src);
        FileOutputStream fos = new FileOutputStream(dst);
        BufferedInputStream bis = new BufferedInputStream(fis);
        BufferedOutputStream bos = new BufferedOutputStream(fos);
        
        int data = 0;
        while((data = bis.read()) != -1) {
            bos.write(data);
        }
        bis.close();
        bos.close();
    }
}