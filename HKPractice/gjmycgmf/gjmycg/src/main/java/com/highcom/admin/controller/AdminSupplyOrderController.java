package com.highcom.admin.controller;

import com.github.pagehelper.PageHelper;
import com.github.pagehelper.PageInfo;
import com.highcom.admin.pojo.Order;
import com.highcom.admin.pojo.Result;
import com.highcom.admin.service.OrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.List;

@Controller
@RequestMapping(value = "/admin")
public class AdminSupplyOrderController {

    @Autowired
    private OrderService orderService;

    @ResponseBody
    @RequestMapping("findSupplyOrderList")
    public Result<PageInfo<Order>> findSupplyOrderList(
            String orderNamech,
            String comname,
            String businessid,
            String publishtime,
            int pageNum
    ){
//        order 根据你要搜索的条件封装

        Order order = new Order();
        order.setOrderNamech(orderNamech);
        order.setComname(comname);
        order.setBusinessid(businessid);
        order.setPublishtime(publishtime);
        order.setPageNum(pageNum);
        order.setSupplyflag("1");

        PageHelper.clearPage();
        PageHelper.startPage(order.getPageNum(), order.getPageSize());

        List<Order> list = this.orderService.findOrderList(order);
        PageInfo<Order> pageInfo = new PageInfo<>(list, order.getPageSize());

        return new Result<PageInfo< Order >>(200, "success", pageInfo);
    }
}
