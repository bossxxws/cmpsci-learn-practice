package com.highcom.admin.dao;

import com.highcom.admin.pojo.AdminInfo;
import java.util.Map;

public interface AdminInfoMapper {

    // 使用 Map 参数传递用户名和密码
    public AdminInfo login(Map<String, String> map);

    public AdminInfo queryAdminInfoByName(String adminName);

    int updatePwd(Map<String, Object> map);
}
