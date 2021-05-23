> close!!!


# InputStream  OutputStream (字节)



# Writer Reader (字符, 不能处理非文本文件)



# 节点流

1. File + InputStream/OutputStream

- read(byte[] c)
- write(byte[] c, 0, len)
- .newline(): 换行


2. File + Reader/Writer

- read(char[] c)
- write(char[] c, 0, len)

# 处理流 *+.


1. Buffered

> have a buffer area to store the data, to accelerate
- .flush(): refresh buffer, when full, do it automatically
    
        br.flush();
- .readLine() (BufferedReader): return the length or null in the end of the file, not include the line terminal(    enter),

    String read = br.readLine();
