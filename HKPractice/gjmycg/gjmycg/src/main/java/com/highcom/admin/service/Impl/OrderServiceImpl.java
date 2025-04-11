package com.highcom.admin.service.Impl;

import com.highcom.admin.dao.OrderMapper;
import com.highcom.admin.pojo.Order;
import com.highcom.admin.service.OrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class OrderServiceImpl implements OrderService {

    @Autowired
    private OrderMapper orderMapper;

    @Override
    public List<Order> findOrderList(Order order) {
        return this.orderMapper.findOrderList(order);
    }
}
