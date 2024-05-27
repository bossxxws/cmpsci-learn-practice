package com.nefu.lessons.experiment_07_total;

import java.util.ArrayList;

import java.util.List;

class Bridge implements Runnable {

    public void run()
    {
        synchronized (this) {
            System.out.println(Thread.currentThread().getName() + "开始走独木桥");
            try {
                Thread.sleep(5000);//需要五秒
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println(Thread.currentThread().getName() + "通过了独木桥");
        }

    }

}

public class be{

    public static void main(String[] args){
        Bridge bridge = new Bridge();

        List<String> list = new ArrayList<String>();
        
        for (int i = 'A'; i <= 'J'; i++) {

            list.add(String.valueOf((char) i));

        }

        while (list.size() != 0) {

            int index = (int) (Math.random() * list.size());

            new Thread(bridge, list.get(index)).start();

            list.remove(index);

        }

    }

}

