package com.highcom.admin.dao;

import com.highcom.admin.pojo.Order;

import java.util.List;

public interface OrderMapper {

    List<Order> findOrderList(Order order);
}
