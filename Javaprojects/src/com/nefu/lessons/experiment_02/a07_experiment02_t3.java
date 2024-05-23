package com.nefu.lessons;


import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class User {
    private String name;
    private double balance;
    private String address;

    public User(String name, double balance, String address) {
        this.name = name;
        this.balance = balance;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getAddress() {
        return address;
    }
}

class Product {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }
}

class Item {
    private Product product;
    private int quantity;

    public Item(Product product, int quantity) {
        this.product = product;
        this.quantity = quantity;
    }

    public Product getProduct() {
        return product;
    }

    public int getQuantity() {
        return quantity;
    }
}

class Order {
    private User user;
    private List<Item> items;
    private double totalCost;

    public Order(User user, List<Item> items, double totalCost) {
        this.user = user;
        this.items = items;
        this.totalCost = totalCost;
    }

    public User getUser() {
        return user;
    }

    public List<Item> getItems() {
        return items;
    }

    public double getTotalCost() {
        return totalCost;
    }
}

class OrderService {
    public static Order addOrder(User user, List<Item> items) {
        double totalCost = items.stream()
                .mapToDouble(item -> item.getProduct().getPrice() * item.getQuantity())
                .sum();

        if (user.getBalance() >= totalCost) {
            user.setBalance(user.getBalance() - totalCost);
            return new Order(user, items, totalCost);
        } else {
            return null;
        }
    }
}

public class a07_experiment02_t3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        String userName = scanner.next();
        double userBalance = scanner.nextDouble();
        String userAddress = scanner.next();
        User user = new User(userName, userBalance, userAddress);


        int numProducts = scanner.nextInt();

        List<Item> items = new ArrayList<>();
        for (int i = 0; i < numProducts; i++) {

            String productName = scanner.next();
            int quantity = scanner.nextInt();

            Product product = null;

            switch (productName)
            {
                case "方便面":
                    product = new Product("方便面", 5.5);
                    break;
                case "火腿肠":
                    product = new Product("火腿肠", 2.2);
                    break;
                case "矿泉水":
                    product = new Product("矿泉水", 1.0);
                    break;
                case "饮料":
                    product = new Product("饮料", 3.5);
                    break;
                default:
                    System.out.println("Product not found.");
            }

            if (product != null) {
                items.add(new Item(product, quantity));
            }
        }

        Order order = OrderService.addOrder(user, items);

        if (order != null)
        {
            System.out.printf("购买商品总额：%.2f\n", order.getTotalCost());
            System.out.printf("用户余额：%.2f\n", user.getBalance());
            System.out.println("地址：" + user.getAddress());
        }
        else
        {
            System.out.println("用户余额不足");
        }

        scanner.close();
    }
}
