package com.highcom.admin.dao;

import com.highcom.admin.pojo.Company;

import java.util.Map;

public interface HomeLoginMapper {
    public Company login(Map<String, String> map);

    public Company queryCompanyByName(String userName);

    int updatePwd(Map<String, Object> map);
}
