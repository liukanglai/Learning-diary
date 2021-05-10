package me.T7;

import org.w3c.dom.css.Counter;

/**
 * @author liukanglai
 * @date 5/9/21 - 9:50 AM
 */
public class SaleTickets {

    public static class Sale implements Runnable {
        static int saleTickets = 0;
        String name;

        Sale(String name) {
            this.name = name;
        }

        @Override
        public void run() {
            while (true) {
                synchronized (Sale.class) {
                    if(saleTickets < 100) {
                        saleTickets++;
                        System.out.println(name + "正在售票, 还有" + String.valueOf(100 - saleTickets) + "张");
                    }
                    else{
                        break;
                    }
                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }
    public static void main(String[] args) {

        Sale win1 = new Sale("窗口1");
        Sale win2 = new Sale("窗口2");
        Sale win3 = new Sale("窗口3");
        Thread thread1 = new Thread(win1);
        Thread thread2 = new Thread(win2);
        Thread thread3 = new Thread(win3);
        thread1.start();
        thread2.start();
        thread3.start();
    }
}
