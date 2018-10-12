import java.io.File;

public class FileDemo {
    public static void main(String[] args) {
        File file = new File("/Users/qianfei/test");
        System.out.println(file.getAbsolutePath());
        System.out.println(file.getParent());
        System.out.println(file.isDirectory());
        System.out.println(file.isFile());
        System.out.println(file.exists());
        System.out.println(file.length());
        System.out.println(file.delete());
        File myFile = new File("/Users/qianfei/test");
        System.out.println(myFile.mkdir());
        File myFile2 = new File("/Users/qianfei/test/1.txt");
        try {
            System.out.println(myFile2.createNewFile());
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        // String[] files = file.list();
        // for(String f:files) {
        //     System.out.println(f);
        // }

        // String[] files = file.list(new FilenameFilter() {

        //     @Override
        //     public boolean accept(FIle dir, String name) {
        //         return name.endsWith(".gif");
        //     }
        // });
        // for(String f:files) {
        //     System.out.println(f);
        // }

        // File[] files = file.listFiles();
        // for(File f:files) {
        //     System.out.println(f.getName() + "--" + f.length());
        // }

        // File[] files = file.listFiles(new FilenameFilter() {

        //     @Override
        //     public boolean accept(File dir, String name) {
        //         return name.endsWith(".gif");
        //     }
        // });
        // for(File f:files) {
        //     System.out.println(f.getName() + "--" + f.length());
        // }

        file.listFiles(new Filefilter() {
            
            @Override
            public boolean accept(File pathname) {
                return pathname.getName().endsWith(".gif");
            }
        });
        for(File f:files) {
            System.out.println(f.getName() + "--" + f.length());
        }
    }
}