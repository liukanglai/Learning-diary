package me.T8;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 * @author liukanglai
 * @date 5/15/21 - 11:25 AM
 */
public class Io {
    public static void main(String[] args) throws IOException {
        FileReader fr = new FileReader("/home/liukanglai/1.txt");
        int read = fr.read();
        while(read != -1) {
            System.out.println((char) read);
            read = fr.read();
        }
        fr.close();
    }
}
