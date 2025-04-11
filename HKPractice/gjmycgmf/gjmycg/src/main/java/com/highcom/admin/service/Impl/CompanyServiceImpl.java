package com.highcom.admin.service.Impl;

import com.highcom.admin.pojo.Company;
import com.highcom.admin.service.AssignConfig;
import com.highcom.admin.service.CompanyService;
import com.highcom.admin.dao.CompanyMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CompanyServiceImpl implements CompanyService
{
    @Autowired
    private CompanyMapper companyMapper;

    public List<Company> findVipCompanyListByCategory(int category){

        List<Company> list = this.companyMapper.findVipCompanyListByCategory(category);

        return list;
    }

    @Override
    public List<Company> findVipCompanyList(Company company) {
        return this.companyMapper.findVipCompanyList(company);
    }


    @Override
    public Company findVipCompanyById(String comid) {
        Company c = this.companyMapper.findVipCompanyById(comid);
        c.setMainImage(AssignConfig.virtualUrl + c.getMainImage());
        return c;
    }

    @Override
    public Company findVipCompanyByName(String comName) {
        return this.companyMapper.findVipCompanyByName(comName);
    }

    @Override
    public Company findVipCompanyByUserName(String userName) {
        return this.companyMapper.findVipCompanyByUserName(userName);
    }

    @Override
    public int updateVipCompany(Company company) {
        return this.companyMapper.updateVipCompany(company);
    }

    @Override
    public void deleteCompany(String comid) {
        this.companyMapper.deleteCompany(comid);
    }

    @Override
    public void addCompany(Company company) {
        this.companyMapper.addCompany(company);
    }


}
