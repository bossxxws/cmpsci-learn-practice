package com.nefu.lessons.experiment_03;
// Test类
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class a08_experiment03_t1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 输入经理信息

        String[] managerInfo = scanner.nextLine().split(" ");
        String managerName = managerInfo[0];
        double managerBaseSalary = Double.parseDouble(managerInfo[1]);
        int managerLevel = Integer.parseInt(managerInfo[2]);

        // 输入销售人员信息

        String[] sellerInfo = scanner.nextLine().split(" ");
        String sellerName = sellerInfo[0];
        double sellerBaseSalary = Double.parseDouble(sellerInfo[1]);
        double salesAmount = Double.parseDouble(sellerInfo[2]);
        double salesCommission = Double.parseDouble(sellerInfo[3]);

        // 创建经理对象和销售人员对象
        Manager manager = new Manager(managerName, managerBaseSalary, managerLevel);
        Seller seller = new Seller(sellerName, sellerBaseSalary, salesAmount, salesCommission);

        // 创建员工列表
        List<Employee> employees = new ArrayList<>();
        employees.add(manager);
        employees.add(seller);

        // 计算薪资总额
        SalaryService salaryService = new SalaryService();
        double totalSalaries = salaryService.getTotalSalaries(employees);

        // 输出薪资总额
        System.out.printf("薪资总额: %.2f\n", totalSalaries);

        scanner.close();
    }
}
// 接口Workable
interface Workable {
    void updateName(String newName);
    double calculateSalary();
}

// 员工实体类Employee
abstract class Employee implements Workable {
    protected String name;
    protected double baseSalary;

    public Employee(String name, double baseSalary) {
        this.name = name;
        this.baseSalary = baseSalary;
    }

    @Override
    public void updateName(String newName) {
        this.name = newName;
    }
}

// 经理实体类Manager
class Manager extends Employee {
    private int level;

    public Manager(String name, double baseSalary, int level) {
        super(name, baseSalary);
        this.level = level;
    }

    @Override
    public double calculateSalary() {
        return baseSalary * level * 80 / 100.0;
    }
}

// 销售实体类Seller
class Seller extends Employee {
    private double salesAmount;
    private double salesCommission;

    public Seller(String name, double baseSalary, double salesAmount, double salesCommission) {
        super(name, baseSalary);
        this.salesAmount = salesAmount;
        this.salesCommission = salesCommission;
    }

    @Override
    public double calculateSalary() {
        return baseSalary + salesAmount * salesCommission;
    }
}

// 薪资业务逻辑操作类SalaryService
class SalaryService {
    public double getTotalSalaries(List<Employee> employees) {
        double totalSalaries = 0;
        for (Employee employee : employees) {
            totalSalaries += employee.calculateSalary();
        }
        return totalSalaries;
    }
}
