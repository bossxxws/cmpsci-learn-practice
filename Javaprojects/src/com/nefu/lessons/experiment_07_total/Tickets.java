package com.nefu.lessons.experiment_07_total;


class Ticket implements Runnable {
    private int tickets = 300;
    @Override
    public void run() {
        while (tickets > 0) {
            synchronized (this) {
                if (tickets > 0) {
                    System.out.println(
                            Thread.currentThread().getName() + "卖出第" + (301 - tickets) + "张票,剩余票数是 " + (--tickets) + "张");
                }
            }

        }
    }

}
public class Tickets {

    public static void main(String[] args) {
        Ticket ticket = new Ticket();
        new Thread(ticket, "哈站").start();
        new Thread(ticket, "哈东站").start();
        new Thread(ticket, "哈西站").start();
    }
}
