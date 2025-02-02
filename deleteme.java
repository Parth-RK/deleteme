import java.io.*;

public class deleteme {
    public static void main(String[] args) {
        String classFile = deleteme.class.getName().replace('.', File.separatorChar) + ".class";
        String javaFile = deleteme.class.getName().replace('.', File.separatorChar) + ".java";
        new Thread(() -> {
            try {
                Thread.sleep(1000);  // Delay before deletion
                new File(javaFile).delete();
                new File(classFile).delete();
            } catch (InterruptedException e) {}
        }).start();
    }
}
