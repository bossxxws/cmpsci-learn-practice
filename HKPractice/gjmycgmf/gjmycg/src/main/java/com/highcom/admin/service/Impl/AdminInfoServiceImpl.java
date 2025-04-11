package com.highcom.admin.service.Impl;

import com.highcom.admin.dao.AdminInfoMapper;
import com.highcom.admin.pojo.AdminInfo;
import com.highcom.admin.service.AdminInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

@Service
public class AdminInfoServiceImpl implements AdminInfoService {

    @Autowired
    private AdminInfoMapper adminInfoMapper;

    @Override
    public AdminInfo login(String adminName, String password) {
        // 使用 Map 传递参数
        Map<String, String> params = new HashMap<>();
        params.put("adminName", adminName);
        params.put("password", password);

        // 调用 Mapper 方法，传递 Map
        return adminInfoMapper.login(params);
    }

    @Override
    public AdminInfo queryAdminInfoByName(String adminName) {
        return adminInfoMapper.queryAdminInfoByName(adminName);
    }

    @Override
    public String updatePwd(Integer id, String password) {
        Map<String, Object> map = new HashMap<>();
        map.put("id", id);
        map.put("password", password);

        int result = adminInfoMapper.updatePwd(map);

        if (result > 0) {
            return "success";
        }
        return "error";
    }
}
