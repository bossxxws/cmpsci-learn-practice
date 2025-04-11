package com.highcom.admin.dao;

import com.highcom.admin.pojo.Company;

import java.util.List;

public interface CompanyMapper {

    List<Company> findVipCompanyListByCategory(int category);

    int deleteByPrimaryKey(Integer comid);

    int insert(Company record);

    int insertSelective(Company record);

    Company selectByPrimaryKey(Integer comid);

    int updateByPrimaryKeySelective(Company record);

    int updateByPrimaryKey(Company record);

    List<Company> findVipCompanyList(Company company);

    Company findVipCompanyById(String comid);

    Company findVipCompanyByName(String companyname);

    int updateVipCompany(Company company);

    Company findVipCompanyByUserName(String userName);

    void deleteCompany(String comid);

    void addCompany(Company company);
}