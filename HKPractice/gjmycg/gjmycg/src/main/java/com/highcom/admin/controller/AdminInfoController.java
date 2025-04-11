package com.highcom.admin.controller;


import com.highcom.admin.pojo.AdminInfo;
import com.highcom.admin.pojo.Result;
import com.highcom.admin.service.AdminInfoService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpSession;

@Controller @RequestMapping("/admin")
public class AdminInfoController {

    @Autowired
    private AdminInfoService adminInfoService;

    @RequestMapping(value = "/login", method = RequestMethod.POST)
    @ResponseBody
    public Result<AdminInfo> login(String adminName, String password, HttpSession session) {
        // 使用 AdminInfoService 进行登录验证
        AdminInfo adminInfo = adminInfoService.login(adminName, password);

        if (adminInfo != null) {
            session.setAttribute("adminInfo", adminInfo);
            return new Result<>(200, "success", adminInfo);
        } else {
            return new Result<>(200, "error", null);
        }
    }

    @ResponseBody
    @RequestMapping(value = "queryAdminInfoByName", method = RequestMethod.POST)
    public Result queryCompanyByName(String adminName) {
        AdminInfo a = adminInfoService.queryAdminInfoByName(adminName);

        if (a != null) {
            return new Result(200, "success", a);
        }
        return new Result(200, "error");
    }

    @RequestMapping(value = "updatePwd", method = RequestMethod.POST)
    @ResponseBody
    public Result updatePwd(Integer id, String password) {
        return new Result<>(200, adminInfoService.updatePwd(id, password));
    }

    @RequestMapping("/getSessionAdmin")
    @ResponseBody
    public Result getSessionAdmin(HttpSession session) {
        AdminInfo adminInfo = (AdminInfo) session.getAttribute("adminInfo");
        return new Result(200, "success", adminInfo);
    }

    @RequestMapping("refreshSession")
    @ResponseBody

    public void refreshSession(HttpSession session) {
        AdminInfo adminInfo = (AdminInfo) session.getAttribute("adminInfo");
        session.setAttribute("adminInfo", adminInfo);
    }
}

