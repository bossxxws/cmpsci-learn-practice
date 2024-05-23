package com.nefu.lessons.experiment_06;

import com.nefu.lessons.experiment06.entity.Container;
import com.nefu.lessons.experiment06.entity.Ship;
import com.nefu.lessons.experiment06.exception.OverWeightException;
import com.nefu.lessons.experiment06.service.LoadService;

import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        testLoadShip();
    }

    private static void testLoadShip() {
        Ship ship = new Ship(1, "�����", 1000);
        List<Container> containers = new ArrayList<>();
        containers.add(new Container(1001, 564));
        containers.add(new Container(2547, 1280));

        try {
            Ship s2 = LoadService.loadShip(ship, containers);
            System.out.println(s2.getName());
        } catch (OverWeightException e) {
            System.out.println(e.getMessage());
        }finally{        	
        	System.out.println("����");
        }
    }
}
