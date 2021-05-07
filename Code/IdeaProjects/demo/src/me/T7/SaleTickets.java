
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
		System.out.println(name+"在售票");
		}
	}
	}
	

	public static void main(String[] args) {

		Sale win1 = new Sale("窗口1");
		Sale win2 = new Sale("窗口2");
		Sale win3 = new Sale("窗口3");
		//while(win1.saleTickets <= 100){
			win1.start();
			win2.start();
			win3.start();
		//}
	}

}
