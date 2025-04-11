package com.highcom.admin.service;

import com.highcom.admin.pojo.Company;

import java.util.List;

public interface CompanyService {
    public List<Company> findVipCompanyListByCategory(int i);

    List<Company> findVipCompanyList(Company company);

    Company findVipCompanyById(String comid);

    Company findVipCompanyByName(String comName);

    Company findVipCompanyByUserName(String comName);

    int updateVipCompany(Company company);

    void deleteCompany(String comid);

    void addCompany(Company company);
}
