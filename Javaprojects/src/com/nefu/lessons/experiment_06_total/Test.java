package com.nefu.lessons.experiment_06_total;

import java.util.*;


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
class Ship {
    private int id;
    private String name;
    private double totalWeight;
    private List<Container> containers;
    public Ship(int id, String name, double totalWeight) {
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

class OverWeightException extends Exception {
    public OverWeightException(String message) {
        super(message);
    }
}

class LoadService {
    public static Ship loadShip(Ship ship, List<Container> containers) throws OverWeightException {
        double totalWeight = 0;
    /*    if(ship.getContainers()!=null){

            for (Container c : ship.getContainers()) {

                totalWeight += c.getWeight();

            }

            System.out.println(totalWeight+"------"+ship.getContainers().size());

        }*/
        for (Container c : containers) {
            totalWeight += c.getWeight();
        }
        double diff = totalWeight - ship.getTotalWeight();
        if (diff > 0) {
            throw new OverWeightException("货船ID：" + ship.getId() + "；货船名称：" + ship.getName() + "；超重：" + diff);
        }
        //  if(ship.getContainers()!=null){containers.addAll(ship.getContainers());}
        ship.setContainers(containers);
        return ship;
    }
}

public class Test {
    public static void main(String[] args) {
        testLoadShip();
    }

    private static void testLoadShip() {

        Scanner scanner = new Scanner(System.in);
        Ship ship = new Ship(scanner.nextInt(), scanner.next(), scanner.nextDouble());
        List<Container> containers = new ArrayList<>();
        int num1 = scanner.nextInt();
        for (int j = 1; j <= num1; j++) {
            int num2 = scanner.nextInt();
            for (int i = 0; i < num2; i++) {
                containers.add(new Container(scanner.nextInt(), scanner.nextDouble()));
            }
            try {
                Ship s2 = LoadService.loadShip(ship, containers);
            } catch (OverWeightException e) {
                System.out.println(e.getMessage());
            } finally {
                double totalWeight = 0;
                if (ship.getContainers() != null) {
                    for (Container c : ship.getContainers()) {
                        totalWeight += c.getWeight();
                    }
                }
                System.out.println("货船ID：" + ship.getId() + "；货船名称：" + ship.getName() + "；第" + j + "次货物装载完毕");
            }
        }
        scanner.close();
    }
}