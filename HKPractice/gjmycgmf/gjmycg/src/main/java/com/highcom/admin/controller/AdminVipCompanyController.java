package com.highcom.admin.controller;

import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.highcom.admin.pojo.Company;
import com.highcom.admin.pojo.Result;
import com.highcom.admin.service.AssignConfig;
import com.highcom.admin.service.CompanyService;
import com.highcom.common.UploadUtil;
import io.swagger.annotations.Api;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import java.util.HashMap;
import java.util.Map;
import java.util.List;

@Api(tags = "后台管理-VIP企业管理")
@RestController
@RequestMapping("/admin")
public class AdminVipCompanyController {

    @Autowired
    private CompanyService companyService;

    @ResponseBody
    @RequestMapping("/indexCompList")
    public Result<Map<Integer, List<Company>>> indexComList() {

        List<Company> list1 = this.companyService.findVipCompanyListByCategory(1);
        List<Company> list2 = this.companyService.findVipCompanyListByCategory(2);
        List<Company> list3 = this.companyService.findVipCompanyListByCategory(3);

        Map<Integer, List<Company>> map = new HashMap<>();
        map.put(1, list1);
        map.put(2, list2);
        map.put(3, list3);

        return new Result<>(200,"",map);
    }

    @RequestMapping(value = "/vipcomlist", method = RequestMethod.GET)

    public Result<PageInfo<Company>> vipComList(String comName, String managerment, String seachbegin, String seachend, Integer page, Integer limit, String sortType) {
        Company company = new Company();
        company.setComName(comName);
        company.setManagement(managerment);
        company.setSearchbegin(seachbegin);
        company.setSearchend(seachend);
        company.setSortType(sortType);
        company.setPageNum(page);
        company.setPageSize(limit);

        PageHelper.clearPage();
        PageHelper.startPage(page, limit);
        List<Company> list = this.companyService.findVipCompanyList(company);

        PageInfo<Company> pageInfo = new PageInfo<>(list, company.getPageSize());

        return new Result<>(200,"",pageInfo);

    }

    @RequestMapping(value = "/findVipCompanyById", method = RequestMethod.GET)
    public Result<Company> findVipCompanyById(String comid) {
        Company company = this.companyService.findVipCompanyById(comid);

        return new Result<Company>(200,"",company);
    }

    @RequestMapping(value = "findVipCompanyByName" , method = RequestMethod.GET)
    public Result<Company> findVipCompanyByName(String comName) {
        Company company = this.companyService.findVipCompanyByName(comName);
        if (company != null) {
            return new Result<>(-1,"企业名称已存在",company);
        }
        return new Result<>(200,"企业名称可用",null);
    }

    @RequestMapping(value = "findVipCompanyByUserName" , method = RequestMethod.GET)
    public Result<Company> findVipCompanyByUserName(String comName) {
        Company company = this.companyService.findVipCompanyByUserName(comName);
        if (company != null) {
            return new Result<>(-1,"用户名已存在",company);
        }
        return new Result<>(200,"用户名可用",null);
    }

    @RequestMapping(value = "/updateVipCompany", method = RequestMethod.POST)
    public Result<String> updateVipCompany(Company company) {
//        上传
        Map<Integer, String> map = UploadUtil.imgsUpload(AssignConfig.uploadUrl, company.getFiles());
        company.setMainImage(map.get(0));
        this.companyService.updateVipCompany(company);
        return new Result<>(200, "企业更新成功", "");
    }

    @RequestMapping(value = "/deleteVipCompany", method = RequestMethod.GET)
    public Result<String> deleteCompany(String comid) {
        this.companyService.deleteCompany(comid);
        return new Result<>(200, "企业删除成功", "");
    }

    @RequestMapping(value = "/vipcomsave", method = RequestMethod.POST)
    public  Result<Object> vipcomsave(Company company) {
        Map<Integer, String> map = UploadUtil.imgsUpload(AssignConfig.uploadUrl, company.getFiles());
        company.setMainImage(map.get(0));
        this.companyService.addCompany(company);

        return new Result<>(200, "企业信息保存成功", null);
    }

}
