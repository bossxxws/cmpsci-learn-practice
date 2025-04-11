package com.highcom.admin.service.Impl;

import com.highcom.admin.dao.HomeLoginMapper;
import com.highcom.admin.pojo.Company;
import com.highcom.admin.service.HomeLoginService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;


@Service
public class HomeLoginServiceImpl implements HomeLoginService {

    @Autowired
    private HomeLoginMapper homeLoginMapper;

    @Override
    public Company login(String userName, String password) {

        System.out.println("--------service--------");

        Map<String, String> map = new HashMap<String, String>();
        map.put("userName", userName);
        map.put("password", password);

        return homeLoginMapper.login(map);
    }

    @Override
    public Company queryCompanyByName(String userName) {
        return homeLoginMapper.queryCompanyByName(userName);
    }

    @Override
    public String updatePwd(Integer comid, String password) {

        Map<String, Object> map = new HashMap<>();
        map.put("comid", comid);
        map.put("password", password);
        map.put("modifyTime", new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date()));

        int result = homeLoginMapper.updatePwd(map);

        if (result > 0) {
            return "success";
        }
        return "error";
    }
}
