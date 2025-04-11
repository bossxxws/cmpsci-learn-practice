package com.highcom.admin.service;

import com.highcom.admin.pojo.AdminInfo;

public interface AdminInfoService {

    AdminInfo login(String adminName, String password);

    AdminInfo queryAdminInfoByName(String adminName);

    String updatePwd(Integer id, String password);
}
