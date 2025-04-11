package com.highcom.common;

import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;

/*
* 文件上传工具类（单个文件，多文件上传）
*
* */
public class UploadUtil {
    public static Map<Integer, String> imgsUpload(HttpServletRequest request, MultipartFile[] upload){
        Map<Integer, String> map = new HashMap<>();
        String path = request.getServletContext().getRealPath("/");

        File file = new File(path + "upload\\");

        if (!file.exists()){
            file.mkdirs();
        }

        if (upload != null && upload.length > 0){
            for (int i = 0; i < upload.length; i++){
                if (upload[i].isEmpty()){
                    continue;
                }
                String filename = upload[i].getOriginalFilename();
                String uuid = UUID.randomUUID().toString().toUpperCase();
                filename = uuid + "_" + filename;

                map.put(i, filename);

                try {
                    upload[i].transferTo(new File(file, filename));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

        }
        return map;
    }



    public static Map<Integer, String> imgsUpload(String path, MultipartFile[] upload){
        Map<Integer, String> map = new HashMap<>();

        File file = new File(path);

        if (!file.exists()){
            file.mkdirs();
        }

        if (upload != null && upload.length > 0){
            for (int i = 0; i < upload.length; i++){
                if (upload[i].isEmpty()){
                    continue;
                }
                String filename = upload[i].getOriginalFilename();
                String uuid = UUID.randomUUID().toString().toUpperCase();
                filename = uuid + "_" + filename;

                map.put(i, filename);

                try {
                    upload[i].transferTo(new File(file, filename));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

        }
        return map;
    }
}
