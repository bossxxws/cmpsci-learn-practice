package com.highcom.admin.service;

import com.highcom.admin.pojo.Company;

public interface HomeLoginService {
    /**
     * 用户登录接口
     *
     * @param userName 用户名
     * @param password 密码
     * @return Company 用户信息（如果登录成功），否则返回 null
     */
    Company login(String userName, String password);

    Company queryCompanyByName(String userName);

    String updatePwd(Integer comid, String password);
}
