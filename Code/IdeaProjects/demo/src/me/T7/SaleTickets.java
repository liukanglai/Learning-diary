package me.T7;

/**
 * @author liukanglai
 * @date 5/9/21 - 9:50 AM
 */
public class SaleTickets extends Thread {
    static int saleTickets = 0;

    public static class Sale extends Thread {
        String name;
        Sale(String name){
            this.name = name;
        }

        public void run() {
            while(saleTickets <= 100){
                saleTickets++;
                System.out.println(name+"����Ʊ");
            }
        }
    }


    public static void main(String[] args) {

        Sale win1 = new Sale("����1");
        Sale win2 = new Sale("����2");
        Sale win3 = new Sale("����3");
        //while(win1.saleTickets <= 100){
        win1.start();
        win2.start();
        win3.start();
        //}
    }

}
