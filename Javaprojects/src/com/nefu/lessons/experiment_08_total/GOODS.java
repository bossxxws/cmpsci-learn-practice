package com.nefu.lessons.experiment_08_total;


import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.Comparator;
import java.util.Objects;
import java.util.stream.Stream;

public class GOODS {
    public static void main(String[] args) {
        String fileName = "C:/example/from.txt";

        System.out.println("----- 创建文件 ------");
         createFile(fileName);

        System.out.println("-----  将字符串写入文件 -------");
        // \r\n在txt文本中换行
        String str =
                "白日依山尽\r\n" +
                        "黄河入海流\r\n" +
                        "欲穷千里目\r\n" +
                        "更上一层楼\r\n"+"烧火董前";
         writeToFile(fileName, str);
        //  writeToFile2(fileName, str);

        System.out.println("--------- 基于基本IO流实现文件的复制 ----------");
        String toFile = "C:/example/to.txt";
        // copyByIO(fileName, toFile);

        System.out.println("--------- 基于NIO实现文件的复制 ----------");
        String toFile2 = "C:/example/nio/to.txt";
        // copyByIO(fileName, toFile2);

        System.out.println("---------- 删除指定文件 -------------");
        // deleteFile(toFile);

        System.out.println("---------- 遍历指定目录文件 -------------");
        String dir = "C:/example";
        // walkDirectories(dir);
        walkDirectories2(dir);
    }


    /**
     * 基于Path/Files实现
     * 将传入的文件绝对路径字符串转path
     * 判断path不存在，则先创建目录，创建文件
     * 文件存在，忽略操作
     *
     * @param fileName
     */
    private static void createFile(String fileName) {
        try {
            Path path = Paths.get(fileName);
            if(!Files.exists(path))//如果文件不存在就创建
            {
                Files.createDirectories(path.getParent());
                Files.createFile(path);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    /**
     * 注意，传入的fileName为文件绝对路径，必须确保文件所在目录已经存在，才能通过FileOutputStream创建
     * 将字符串转字节数组，基于FileOutputStream直接写入
     *
     * @param fileName
     * @param content
     */
    private static void writeToFile(String fileName, String content) {
        createFile(fileName);//先确保文件存在
        try( OutputStream outputStream = new FileOutputStream(fileName);) {
            byte[] buff = content.getBytes();
            outputStream.write(buff);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * 将传入的文件绝对路径字符串转path，通过Files创建文件所在目录
     * 将字符串，基于Files工具类直接写入。写入方法，文件不存在创建并写入，存在则覆盖写入
     * 字符串转字节数组再写入也可，但无意义
     *
     * @param fileName
     * @param content
     */
    private static void writeToFile2(String fileName, String content) {
        createFile(fileName);//先确保文件存在
        byte[] buff = content.getBytes();
        try {
            Files.write(Paths.get(fileName), buff);

        } catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    /**
     * 基于基本IO，以及字节数组缓冲区，复制文件
     * 打印显示循环读写循环次数
     * 正确关闭资源
     *
     * @param sourceFile
     * @param targetFile
     */
    private static void copyByIO(String sourceFile, String targetFile) throws IOException {
        byte[] buff = new byte[8];
        int num=0;
        int len;
        try( InputStream inputStream = new FileInputStream(sourceFile);
             OutputStream outputStream = new FileOutputStream(targetFile);
        ) {
            while ((len = inputStream.read(buff)) != -1) {
                outputStream.write(buff, 0, len);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    /**
     * 基于NIO，实现文件的复制
     * 注意，判断目标为字符串，需要转为path并创建相应目录
     *
     * @param sourceFile
     * @param targetFile
     */
    private static void copyByNIO(String sourceFile, String targetFile) {
        try {
            Path source = Paths.get(sourceFile);
            Path target = Paths.get(targetFile);
            Files.createDirectories(target.getParent());
            Files.copy(source, target);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    /**
     * 删除文件
     *
     * @param fileName
     */
    private static void deleteFile(String fileName) {
        try {
            Files.deleteIfExists(Paths.get(fileName));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    /**
     * 遍历打印指定目录下全部目录/文件名称
     * 尝试改变正逆序操作方法
     *
     * @param dir
     */
    private static void walkDirectories(String dir) {
        try (Stream<Path> filesName = Files.walk(Paths.get(dir))) {
            filesName.forEach(System.out::println);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private static void walkDirectories2(String dir) {
        try {
            Files.walk(Paths.get(dir))
                    .sorted(Comparator.reverseOrder())//改变正逆序
                    .forEach(System.out::println);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

