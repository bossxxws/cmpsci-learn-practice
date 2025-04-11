package com.highcom.admin.pojo;

import java.util.Date;

public class Orders {
    /**
    * 主键
    */
    private Integer orderid;

    /**
    * 中文名称
    */
    private String ordernamech;

    /**
    * 英文名称
    */
    private String ordernameen;

    /**
    * 订单简介
    */
    private String summary;

    /**
    * 行业分类
    */
    private Integer businessid;

    /**
    * 发布时间
    */
    private Date publishtime;

    /**
    * 图片1
    */
    private String img1;

    /**
    * 图片2
    */
    private String img2;

    /**
    * 图片3
    */
    private String img3;

    /**
    * 点击量
    */
    private Integer clickcount;

    /**
    * 商品名称
    */
    private String goodsname;

    /**
    * 数量
    */
    private Integer number;

    /**
    * 品类
    */
    private Integer categoryid;

    /**
    * 规格
    */
    private String specifications;

    /**
    * 价格
    */
    private Double price;

    /**
    * 供应时间
    */
    private Date supplytime;

    /**
    * 所属企业
    */
    private String comid;

    /**
    * 订单详细
    */
    private String details;

    /**
    * 首页推荐标记位
    */
    private Integer recomflag;

    /**
    * 发布标记位
    */
    private Integer publishflag;

    /**
    * 交易状态记
    */
    private String tradeflag;

    /**
    * 采购供应标记位
    */
    private Integer supplyflag;

    /**
    * 删除标记位
    */
    private Integer delflag;

    /**
    * 更新时间
    */
    private Date updatetime;

    /**
    * 公司名称
    */
    private String comname;

    private String category;

    public Integer getOrderid() {
        return orderid;
    }

    public void setOrderid(Integer orderid) {
        this.orderid = orderid;
    }

    public String getOrdernamech() {
        return ordernamech;
    }

    public void setOrdernamech(String ordernamech) {
        this.ordernamech = ordernamech;
    }

    public String getOrdernameen() {
        return ordernameen;
    }

    public void setOrdernameen(String ordernameen) {
        this.ordernameen = ordernameen;
    }

    public String getSummary() {
        return summary;
    }

    public void setSummary(String summary) {
        this.summary = summary;
    }

    public Integer getBusinessid() {
        return businessid;
    }

    public void setBusinessid(Integer businessid) {
        this.businessid = businessid;
    }

    public Date getPublishtime() {
        return publishtime;
    }

    public void setPublishtime(Date publishtime) {
        this.publishtime = publishtime;
    }

    public String getImg1() {
        return img1;
    }

    public void setImg1(String img1) {
        this.img1 = img1;
    }

    public String getImg2() {
        return img2;
    }

    public void setImg2(String img2) {
        this.img2 = img2;
    }

    public String getImg3() {
        return img3;
    }

    public void setImg3(String img3) {
        this.img3 = img3;
    }

    public Integer getClickcount() {
        return clickcount;
    }

    public void setClickcount(Integer clickcount) {
        this.clickcount = clickcount;
    }

    public String getGoodsname() {
        return goodsname;
    }

    public void setGoodsname(String goodsname) {
        this.goodsname = goodsname;
    }

    public Integer getNumber() {
        return number;
    }

    public void setNumber(Integer number) {
        this.number = number;
    }

    public Integer getCategoryid() {
        return categoryid;
    }

    public void setCategoryid(Integer categoryid) {
        this.categoryid = categoryid;
    }

    public String getSpecifications() {
        return specifications;
    }

    public void setSpecifications(String specifications) {
        this.specifications = specifications;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public Date getSupplytime() {
        return supplytime;
    }

    public void setSupplytime(Date supplytime) {
        this.supplytime = supplytime;
    }

    public String getComid() {
        return comid;
    }

    public void setComid(String comid) {
        this.comid = comid;
    }

    public String getDetails() {
        return details;
    }

    public void setDetails(String details) {
        this.details = details;
    }

    public Integer getRecomflag() {
        return recomflag;
    }

    public void setRecomflag(Integer recomflag) {
        this.recomflag = recomflag;
    }

    public Integer getPublishflag() {
        return publishflag;
    }

    public void setPublishflag(Integer publishflag) {
        this.publishflag = publishflag;
    }

    public String getTradeflag() {
        return tradeflag;
    }

    public void setTradeflag(String tradeflag) {
        this.tradeflag = tradeflag;
    }

    public Integer getSupplyflag() {
        return supplyflag;
    }

    public void setSupplyflag(Integer supplyflag) {
        this.supplyflag = supplyflag;
    }

    public Integer getDelflag() {
        return delflag;
    }

    public void setDelflag(Integer delflag) {
        this.delflag = delflag;
    }

    public Date getUpdatetime() {
        return updatetime;
    }

    public void setUpdatetime(Date updatetime) {
        this.updatetime = updatetime;
    }

    public String getComname() {
        return comname;
    }

    public void setComname(String comname) {
        this.comname = comname;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", orderid=").append(orderid);
        sb.append(", ordernamech=").append(ordernamech);
        sb.append(", ordernameen=").append(ordernameen);
        sb.append(", summary=").append(summary);
        sb.append(", businessid=").append(businessid);
        sb.append(", publishtime=").append(publishtime);
        sb.append(", img1=").append(img1);
        sb.append(", img2=").append(img2);
        sb.append(", img3=").append(img3);
        sb.append(", clickcount=").append(clickcount);
        sb.append(", goodsname=").append(goodsname);
        sb.append(", number=").append(number);
        sb.append(", categoryid=").append(categoryid);
        sb.append(", specifications=").append(specifications);
        sb.append(", price=").append(price);
        sb.append(", supplytime=").append(supplytime);
        sb.append(", comid=").append(comid);
        sb.append(", details=").append(details);
        sb.append(", recomflag=").append(recomflag);
        sb.append(", publishflag=").append(publishflag);
        sb.append(", tradeflag=").append(tradeflag);
        sb.append(", supplyflag=").append(supplyflag);
        sb.append(", delflag=").append(delflag);
        sb.append(", updatetime=").append(updatetime);
        sb.append(", comname=").append(comname);
        sb.append(", category=").append(category);
        sb.append("]");
        return sb.toString();
    }
}