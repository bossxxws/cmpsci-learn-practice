package com.highcom.admin.service;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class AssignConfig {

    public static String uploadUrl;
    public static String uploadType; // 上传类型    0 本地上传  1 远程磁盘共享文件夹(OSS)
    public static String uploadPath;
    public static String virtualUrl; // 虚拟地址
    public static String hostUrl; // 主机地址

//    @Value("D:/XM/upload")
    @Value("${uploadUrl}")
    public void setUploadUrl(String uploadUrl) {
        AssignConfig.uploadUrl = uploadUrl;
    }
    @Value("${uploadType}")
    public void setUploadType(String uploadType) {
        AssignConfig.uploadType = uploadType;
    }
    @Value("${uploadPath}")
    public void setUploadPath(String uploadPath) {
        AssignConfig.uploadPath = uploadPath;
    }
    @Value("${virtualUrl}")
    public void setvirtualUrl(String virtualUrl) {
        AssignConfig.virtualUrl = virtualUrl;
    }
    @Value("${hostUrl}")
    public void sethostUrl(String hostUrl) {
        AssignConfig.hostUrl = hostUrl;
    }

}
