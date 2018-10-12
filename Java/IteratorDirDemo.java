import java.io.File;

public class IteratorDirDemo {
    public static void main(String[] args) {
        IteratorUtil.IteratorDir(new File("/Users/qianfei/test"));
    }
}

class IteratorUtil {
    private static int level = 0;
    public static void IteratorDir(File file) {
        if(file != null) {
            if(file.isFile() || file.listFile().length == 0) {
                return;
            }
        } else {
            File[] files = file.listFiles();
            files = sort(files);
            for(File f:files) {
                StringBuilder sb = new StringBuilder();
                if(f.isFile()) {
                    sb.append(getTab(level));
                    sb.append(f.getName());
                } else {
                    sb.append(getTab(level));
                    sb.append(f.getName());
                    sb.append("\\");
                }
                System.out.println(sb.toString());
                if(f.isDirectory()) {
                    level++;
                    IteratorDir(f);
                    level--;
                }
            }
        }
    }

    private static File[] sort(File[] files) {
        List<File> fList = new ArrayList<File>();
        for(File f:files) {
            if(f.isDirectory()) {
                fList.add(f);
            }
        }
        for(File f:files) {
            if(f.isFile()) {
                fList.add(f);
            }
        }

        return fList.toArray(new File[fList.size()]);
    }

    private static String getTab(int level) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < level; i++) {
            sb.append("\t");
        }
        return sb.toString();
    }
}