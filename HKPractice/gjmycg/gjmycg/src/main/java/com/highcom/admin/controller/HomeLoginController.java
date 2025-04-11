package com.highcom.admin.controller;

import com.highcom.admin.pojo.Company;
import com.highcom.admin.pojo.Result;
import com.highcom.admin.service.HomeLoginService;
import com.highcom.utils.VerifyCodeUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.OutputStream;
import java.text.SimpleDateFormat;
import java.util.*;

@Controller
@RequestMapping("/home")
public class HomeLoginController {

    @Autowired
    private HomeLoginService homeLoginService;

    @RequestMapping(value = "login", method = RequestMethod.POST)
    @ResponseBody
    public Result login(String userName, String password, HttpSession session) {
        System.out.println("------------controller-------------");
//        用户名 密码 ---》   数据库
//        用户是否存在， 密码是否匹配

        Company company = homeLoginService.login(userName, password);

        if (company != null) {
//            判断是不是vip
            if (company.getVipbegin() != null && company.getVipend() != null) {
                String currentTime = new SimpleDateFormat("yyyy-MM-dd").format(new Date());
                if (company.getVipbegin().compareTo(currentTime) <= 0 && company.getVipend().compareTo(currentTime) >= 0){
//                    1     vip
                    company.setVipflag(1);
                }else {
                    company.setVipflag(0);
                }
            }else {
                company.setVipflag(0);
            }
            session.setAttribute("company", company);

//            清空 code
            session.removeAttribute("code");

            return new Result(200, "success", company);
        }
        return new Result(200, "error");
    }


    @RequestMapping(value = "createCode", method = RequestMethod.GET)
    public void createCode(HttpSession session, HttpServletResponse response) {
        try{
            OutputStream outputStream = response.getOutputStream();

            int w = 100, h = 66;

            String code = VerifyCodeUtils.generateVerifyCode(4);
            session.setAttribute("code", code);
            VerifyCodeUtils.outputImage(w, h, outputStream, code);
            outputStream.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }

//    校验 验证码

    @RequestMapping(value = "verifyCode", method = RequestMethod.GET)
    @ResponseBody
    public Result verifyCode(String code, HttpSession session) {
        if (code.equalsIgnoreCase(session.getAttribute("code").toString())) {
            return new Result(200, "success");
        }

        return new Result(200, "error");
    }

//    用户名验证
    @ResponseBody
    @RequestMapping(value = "queryCompanyByName", method = RequestMethod.POST)
    public Result queryCompanyByName(String userName) {
        Company c = homeLoginService.queryCompanyByName(userName);

        if (c != null) {
            return new Result(200, "success", c);
        }
        return new Result(200, "error");
    }

//    获取短信验证码
    @RequestMapping(value = "createMsgCode", method = RequestMethod.POST)
    @ResponseBody
    public Result createMsgCode(String telephone, HttpSession session) {
//        生成6位验证码
        String msgCode = String.valueOf(new Random().nextInt(899999) + 100000);

        msgCode = "888888";

        session.setAttribute("msgCode", msgCode);

        System.out.println(telephone + "---短信验证---" + msgCode);
//        需要删除 超时的msgCode 定时一分钟删除
        session.setAttribute("msgCode", msgCode);
        removeAttribute(session, "msgCode");

        return new Result(200, "success");
    }
    /*
    *
    * 设置定时一分钟后删除session的msgCode
    * */

    private void removeAttribute(final HttpSession session, final String attrName) {
        final Timer timer = new Timer();

        timer.schedule(new TimerTask() {
            @Override
            public void run() {
//                删除session中的验证码
                session.removeAttribute(attrName);
                timer.cancel();
            }
        } , 1000 * 60 * 2);
    }


    @RequestMapping(value = "verifyMsgCode", method = RequestMethod.POST)
    @ResponseBody
    public Result verifyMsgCode(String msgCode,HttpSession session){
        Object obj=session.getAttribute("msgCode");
        if (obj!=null){//没过期
            if (msgCode.equals((String) obj)){
                //移除验证码
                session.removeAttribute("msgCode");
                return new Result(200,"success");


            }else {
                return new Result(200,"error");
            }


        }
        return new Result(200,"delayed");
    }
    /*
    * 修改密码
    *用户ID   comid
    * */
    @RequestMapping(value = "updatePwd", method = RequestMethod.POST)
    @ResponseBody
    public Result updatePwd(Integer comid, String password) {
        return new Result<>(200, homeLoginService.updatePwd(comid, password));
    }


}
