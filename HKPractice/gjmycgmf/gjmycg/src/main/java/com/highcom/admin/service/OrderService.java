package com.highcom.admin.service;

import com.highcom.admin.pojo.Order;

import java.util.List;

public interface OrderService {
    List<Order> findOrderList(Order order);

}
