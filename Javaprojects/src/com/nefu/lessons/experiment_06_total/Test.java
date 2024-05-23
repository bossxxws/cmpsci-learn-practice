package com.nefu.lessons.experiment_06_total;


import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class OverWeightException extends Exception {
    public OverWeightException(String message) {
        super(message);
    }
}
class Ship {
    private int id;
    private String name;
    private double totalWeight;
    private List<Container> containers;

    public Ship(int id, String name, double totalWeight)
    {
        this.id = id;
        this.name = name;
        this.totalWeight = totalWeight;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Container> getContainers() {
        return containers;
    }

    public void setContainers(List<Container> containers) {
        this.containers = containers;
    }

    public double getTotalWeight() {
        return totalWeight;
    }

    public void setTotalWeight(double totalWeight) {
        this.totalWeight = totalWeight;
    }
}
class Container {
    private int id;
    private double weight;

    public Container(int id, double weight) {
        this.id = id;
        this.weight = weight;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
}
class LoadService {

    public static Ship loadShip(Ship ship, List<Container> containers) throws OverWeightException {
        double totalWeight = 0;
        for (Container c : containers) {
            totalWeight += c.getWeight();
        }
        double diff = totalWeight - ship.getTotalWeight();
        if (diff > 0) {
            throw new OverWeightException("����ID��" + ship.getId() + "���������ƣ�" + ship.getName() + "�����أ�" + diff);
        }
        ship.setContainers(containers);
        return ship;
    }

}

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
//        int a;
//        Scanner s = new Scanner(System.in);
//
//        a=s.nextInt();
//
//        if(a==10001)System.out.println("货船ID：10001；货船名称：东风号；第1次货物装载完毕\n" +
//
//                "货船ID：10001；货船名称：东风号；超重：68.0\n" +
//
//                "货船ID：10001；货船名称：东风号；第2次货物装载完毕");
//        else System.out.println("货船ID：10002；货船名称：海南号；第1次货物装载完毕\n" +
//                "货船ID：10002；货船名称：海南号；第2次货物装载完毕");
    }
}
